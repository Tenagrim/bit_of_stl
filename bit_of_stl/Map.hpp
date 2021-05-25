//
// Created by Gerry Shona on 5/23/21.
//

#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include "Utils.hpp"

namespace ft
{
	template <class T>
	struct M_Node{
		typedef T value_type;
		bool 			red;
		value_type		value;
		M_Node			*left;
		M_Node			*right;
		M_Node			*parent;

		M_Node(const value_type &value):value(value), left(0), right(0), parent(0) {}
		bool	is_red(){return red;}
		bool	is_black(){return !red;}
	};


#pragma region iterators
	template<class T>
	class MapIteratorBase{
	protected:
		typedef	T	value_type;
		typedef M_Node <T>	*node_pointer;

		M_Node <T>	*		_p;

		explicit MapIteratorBase(node_pointer p) : _p(p){}
		MapIteratorBase(const MapIteratorBase &other) : _p(other._p){}
		MapIteratorBase() : _p(0){}
		~MapIteratorBase(){}
		MapIteratorBase & operator=(const MapIteratorBase &other){_p = other._p;}

		node_pointer _next(node_pointer p)
		{
			node_pointer next;
			if(p->right)
			{
				next = p->right;
				while (next->left)
					next = next->left;
			}
			else
			{
				next = p;
				while (next->parent && next == next->parent->right)
					next = next->parent;
				next = next->parent;
			}
			return next;
		}

		node_pointer _prev(node_pointer p)
		{
			node_pointer prev;
			if(p->left)
			{
				prev = p->left;
				while (prev->right)
					prev = prev->right;
			}
			else
			{
				prev = p;
				while (prev->parent && prev == prev->parent->left)
					prev = prev->parent;
				prev = prev->parent;
			}
			return prev;
		}
	};

	template<class T>
	class MapIterator : public MapIteratorBase<T>
	{
	private:
		typedef M_Node <T>	*node_pointer;
		typedef T			value_type;
	public:
		MapIterator(){}
		MapIterator(node_pointer p) : MapIteratorBase<T>(p){}
		MapIterator(const MapIterator &other) : MapIteratorBase<T>(other) {}
		MapIterator &operator=(const MapIterator &other){this->_p = other._p;}
		~MapIterator(){}

		MapIterator &operator++()
		{
			this->_p = this->_next(this->_p);
			return *this;
		}

		MapIterator operator++(int)
		{
			MapIterator tmp(*this);
			this->operator++();
			return tmp;
		}
		MapIterator &operator--()
		{
			this->_p = this->_prev(this->_p);
			return *this;
		}

		MapIterator operator--(int)
		{
			MapIterator tmp(*this);
			this->operator--();
			return tmp;
		}

		value_type &operator*() {
			return this->_p->value;
		}

		value_type *operator->() {
			return &this->_p->value;
		}

		node_pointer _node(){return this->_p;}

		bool operator==(const MapIterator &other) {
			return this->_p == other._p;
		}


		bool operator!=(const MapIterator &other) {
			return this->_p != other._p;
		}

		MapIterator &operator+=(int n) {
			while (n < 0) {
				this->operator++();
				n++;
			}
			while (n > 0) {
				this->operator--();
				n--;
			}
			return *this;
		}

		MapIterator &operator-=(int n) {
			while (n < 0) {
				this->operator++();
				n++;
			}
			while (n > 0) {
				this->operator--();
				n--;
			}
			return *this;
		}

		MapIterator operator+(int n) {
			MapIterator p(*this);
			p += n;
			return p;
		}

		MapIterator operator-(int n) {
			MapIterator p(*this);
			p -= n;
			return p;
		}
	};

#pragma endregion //iterators


	template<
			class Key,
			class T,
			class Compare = ft::less<Key>,
			class Allocator = std::allocator<ft::Pair<const Key, T> >
	>
	class Map{
	public:
		typedef Key								key_type;
		typedef	T								mapped_type;
		typedef	Compare							key_compare;
		typedef size_t 							size_type;
		typedef Allocator						allocator_type;
		typedef ft::Pair<key_type, mapped_type>	value_type;
		typedef M_Node<value_type>				node;
		typedef MapIterator<value_type>			iterator;

		class value_compare{
			friend class Map<key_type , mapped_type, key_compare, allocator_type>;
		protected:
			Compare	comp;
			value_compare( Compare c ): comp(c){}
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator()( const value_type& lhs, const value_type& rhs ) const
			{
				return comp(lhs.first, rhs.first);
			}
		};

	private:
		typedef typename allocator_type::template rebind<M_Node<ft::Pair<Key, T> > >::other
				node_allocator_type;

		allocator_type			_alloc;
		node_allocator_type		_node_alloc;
		key_compare				_compare;
		value_compare			_v_compare;

		size_type				_len;

		node 					*_root;
		node					*_begin;
		node					*_end;

		void _deallocate(node *n)
		{
			_node_alloc.destroy(n);
			_node_alloc.deallocate(n, 1);
//			delete n;
		}

		node *_allocate(value_type const &data = value_type())
		{
			node *res = _node_alloc.allocate(1);
			_node_alloc.construct(res, node(data));
			return res;
//			return new node;
		}

		node *_create_node(node *left, node *right, node *parent,  value_type data) {
			node *res = _allocate(data);
			res->parent = parent;
			res->right = right;
			res->left = left;
			return res;
		}

		void _init()
		{
			_root = 0;
			_end = _create_node(0,0,0, value_type());
			_begin = _create_node(0,0, _end, value_type());
		}
		void _detach_borders()
		{
			if (_begin->parent && _begin->parent->left) {
				_begin->parent->left = 0;
				_begin->parent = 0;
			}
			if (_end->parent && _end->parent->right) {
				_end->parent->right = 0;
				_end->parent = 0;
			}
		}

		void _nullify_node(node *n)
		{
			n->parent = 0;
			n->left = 0;
			n->right = 0;
		}

		void _attach_borders()
		{
			node *p;
			_nullify_node(_begin);
			_nullify_node(_end);
			if (!_root) {
				_begin->parent = _end;
				_end->left = _begin;
			}
			else{
				p = _root;
				while (p->left)
					p = p->left;
				_begin->parent = p;
				p->left = _begin;
				p = _root;
				while (p->right)
					p = p->right;
				_end->parent = p;
				p->right = _end;
			}
		}

		node * _insert(node *n)
		{
			node *cur = _root;
			node *prev;
			node **p;
			_detach_borders();
			if(!_root){
				_root = n;
			}else{
				do{
					prev = cur;
					if(_v_compare(n->value, cur->value)){
						p = &cur->left;
						cur = cur->left;
					}
					else{
						p = &cur->right;
						cur = cur->right;
					}
				} while(cur);
				*p = n;
				n->parent = prev;
			}
			_len++;
			_attach_borders();
			return n;
		}

		void _delete_subtree(node *n)
		{
			if(!n)
				return;
			if (n->parent && n->parent->left == n)
				n->parent->left =0;
			if (n->parent && n->parent->right == n)
				n->parent->right =0;

			if(n->left)
				_delete_subtree(n->left);
			if(n->right)
				_delete_subtree(n->right);
			_deallocate(n);
			_len--;
		}

		void _delete_node(node *n)
		{

		}

		node *_find(node *n, const key_type & key) const
		{
			if(!n)
				return 0;
			else if (n->value.first == key)
				return n;
			else if(_compare(key,n->value.first))
				return _find(n->left, key);
			else
				return _find(n->right, key);
		}

	public:
		explicit Map(const key_compare &comp = key_compare(), const allocator_type alloc = allocator_type()) :
		_len(0), _compare(comp), _alloc(alloc), _v_compare(value_compare(comp)){_init();}
		~Map(){}

		key_compare key_comp() const
		{return _compare;}

		value_compare value_comp() const
		{return (value_compare(key_compare()));}

		/// Element access
		mapped_type &operator[](const key_type &key)
		{
			node *p = _find(_root,key);
			if(p)
				return p->value.second;
			else
				return _insert(_allocate(value_type(key, mapped_type())))->value.second;
		}
		///


		/// Iterators
		iterator begin(){return iterator(_begin->parent);}
		iterator end(){return iterator(_end);}
		///

		/// Capacity
		size_type size() const{return _len;}
		bool empty() const{return _len == 0;}
		size_type max_size() const {return std::numeric_limits<size_type>::max() / sizeof(Node<T>);}
		///

		/// Modifiers
		void clear()
		{
			_detach_borders();
			_delete_subtree(_root);
			_root = 0;
			_attach_borders();
		}

		ft::Pair<iterator, bool>	insert(const value_type &value)
		{
			node *p = _find(_root, value.first);
			if(p)
				return Pair<iterator, bool>(iterator(p), false);
			else
				return Pair<iterator, bool>(iterator(_insert(_allocate(value))), true);
		}
		///

		/// Lookup
		iterator find(const key_type &key)
		{
			if(_len==0)
				return (end());
			node *n = _find(_root, key);
			if(n)
				return (iterator(n));
			return end();
		}
		///


		/// Trash //TODO: remove
		void deb_insert()
		{
			_insert(_allocate(Pair<int,int>(rand()%100, rand()%100)));
		}
		///

	};
}
#endif //MAP_HPP
