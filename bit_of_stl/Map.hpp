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
	class M_Node{
		typedef T value_type;

		value_type		value;
		M_Node			*left;
		M_Node			*right;
		M_Node			*parent;

		M_Node(const value_type &value):value(value), left(0), right(0), parent(0) {}
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
			(*this)++;
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
			(*this)--;
			return tmp;
		}

		value_type &operator*() {
			return this->_p->data;
		}

		value_type *operator->() {
			return this->_p->data;
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

		node *_allocate(value_type &data = value_type())
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
			if (!_root)
				_begin->parent = _end;
			else{
				p = _root;
				while (p->left)
					p = p->left;
				_begin->parent = p;
				while (p->right)
					p = p->right;
				_end->parent = p;
			}
		}

		void 	_insert(node *n)
		{
			node *prev = _root;
			_detach_borders();
			if(!_root){
				_root = n;
			}else
			{

			}
			_attach_borders();
		}

	public:
		explicit Map(const key_compare &comp = key_compare(), const allocator_type alloc = allocator_type()) :
		_len(0), _compare(comp), _alloc(alloc){_init();}
		~Map(){}

		key_compare key_comp() const
		{return _compare;}

		value_compare value_comp() const
		{return (value_compare(key_compare()));}

		size_type size() const{return _len;}
		bool empty() const{return _len == 0;}

		iterator begin(){return iterator(_begin->parent);}
		iterator end(){return iterator(_end);}
	};
}
#endif //MAP_HPP
