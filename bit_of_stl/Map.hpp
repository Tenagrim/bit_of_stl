//
// Created by Gerry Shona on 5/23/21.
//

#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include "Utils.hpp"


#include <iostream> // TODO: remove
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
		virtual ~MapIteratorBase(){}
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
		virtual ~MapIterator(){}

		virtual MapIterator &operator++()
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

		virtual MapIterator &operator--()
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


	template<class T>
	class MapReverseIterator : public MapIterator<T>
	{
	private:
		typedef M_Node <T>	*node_pointer;
		typedef T			value_type;
	public:
		MapReverseIterator(){}
		MapReverseIterator(node_pointer p) : MapIterator<T>(p){}
		MapReverseIterator(const MapReverseIterator &other) : MapIterator<T>(other) {}
		MapReverseIterator &operator=(const MapReverseIterator &other){this->_p = other._p;}
		virtual ~MapReverseIterator(){}

		MapReverseIterator &operator++()
		{
			this->_p = this->_prev(this->_p);
			return *this;
		}
		MapReverseIterator &operator--()
		{
			this->_p = this->_next(this->_p);
			return *this;
		}
	};


	template<class T>
	class MapConstIterator : public MapIterator<T>
	{
	private:
		typedef M_Node <T>	*node_pointer;
		typedef T			value_type;
	public:
		MapConstIterator(){}
		MapConstIterator(node_pointer p) : MapIterator<T>(p){}
		MapConstIterator(const MapConstIterator &other) : MapIterator<T>(other) {}
		MapConstIterator &operator=(const MapConstIterator &other){this->_p = other._p;}
		virtual ~MapConstIterator(){}

		const value_type &operator*() const {
			return this->_p->value;
		}

		const value_type *operator->() const {
			return &this->_p->value;
		}

	};

	template<class T>
	class MapConstReverseIterator : public MapIterator<T>
	{
	private:
		typedef M_Node <T>	*node_pointer;
		typedef T			value_type;
	public:
		MapConstReverseIterator(){}
		MapConstReverseIterator(node_pointer p) : MapIterator<T>(p){}
		MapConstReverseIterator(const MapConstReverseIterator &other) : MapIterator<T>(other) {}
		MapConstReverseIterator &operator=(const MapConstReverseIterator &other){this->_p = other._p;}
		virtual ~MapConstReverseIterator(){}

		MapConstReverseIterator &operator++()
		{
			this->_p = this->_prev(this->_p);
			return *this;
		}
		MapConstReverseIterator &operator--()
		{
			this->_p = this->_next(this->_p);
			return *this;
		}
		const value_type &operator*() const{
			return this->_p->value;
		}
		const value_type *operator->() const{
			return &this->_p->value;
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
		typedef Key									key_type;
		typedef	T									mapped_type;
		typedef	Compare								key_compare;
		typedef size_t 								size_type;
		typedef Allocator							allocator_type;
		typedef ft::Pair<key_type, mapped_type>		value_type;
		typedef M_Node<value_type>					node;
		typedef MapIterator<value_type>				iterator;
		typedef MapReverseIterator<value_type>		reverse_iterator;
		typedef MapConstIterator<value_type>		const_iterator;
		typedef MapConstReverseIterator<value_type>	const_reverse_iterator;

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

		void _unlink_parent(node *n, node *subtree = 0)
		{
			if(n->parent)
			{
				if (n->parent->left == n)
					n->parent->left = subtree;
				else if (n->parent->right == n)
					n->parent->right = subtree;
				if(subtree)
					subtree->parent = n->parent;
			}
		}

		void _delete_subtree(node *n)
		{
			if(!n)
				return;
			_unlink_parent(n);

			if(n->left)
				_delete_subtree(n->left);
			if(n->right)
				_delete_subtree(n->right);
			_deallocate(n);
			_len--;
		}

		node *_next_node(node *p) const
		{
			node * next;
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

		node * _prev_node(node *p) const
		{
			node * prev;
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

		void _delete_node(node *n)
		{
			if(!n->left && !n->right)
				_unlink_parent(n);
			else if (n->left && !n->right)
				_unlink_parent(n, n->left);
			else if(!n->left && n->right)
				_unlink_parent(n, n->right);
			else
			{
				node *next = _next_node(n);
				if(!next)
					next = _prev_node(n);
				ft::swap(n->value, next->value);
				_delete_node(next);
				return;
			}
			_deallocate(n);
			_len--;
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

		node *_lower_bound(const key_type &key) const
		{
			node *n = _closest_lower(_root, key);
			if (n->value.first == key || n ==_end)
				return n;
			else
				return _next_node(n);
		}
		node *_upper_bound(const key_type &key) const
		{
			node *n = _lower_bound(key);
			if (n->value.first == key )
				return _next_node(n);
			return n;
		}
		node *_closest_lower(node *n, const key_type &key) const
		{
			if(!n)
				return 0;
			else if (n->value.first == key)
				return n;
			else if(_compare(key,n->value.first))
			{
				std::cout << "left : "<< n->value.first << "\n";
				if(n->left)
					return _closest_lower(n->left, key);
				else if(n->parent)
					return n->parent;
				else
					return _end;
			}
			else
			{
				std::cout << "right : "<< n->value.first << "\n";
				if(n->right)
					return _closest_lower(n->right, key);
				else return n;
			}
		}

	public:
		/// Constructor
		#pragma region constructor
		explicit Map(const key_compare &comp = key_compare(), const allocator_type alloc = allocator_type()) :
		_len(0), _compare(comp), _alloc(alloc), _v_compare(value_compare(comp)){_init();}

		template <class InputIterator>
		Map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
	  		const allocator_type alloc = allocator_type())
				: _alloc(alloc), _compare(comp),_v_compare(value_compare(comp)), _len(0)
		{
			_init();
			insert(first, last);
		}

		explicit Map(const Map<Key, T> &other)
				: _len(0), _alloc(other._alloc), _compare(other._compare),_v_compare(value_compare(other._compare))
		{
			_init();
			insert(other.begin(), other.end());
		};
		Map &operator=(const Map<Key, T> &other)
		{
			clear();
			insert(other.begin(), other.end());
			return (*this);
		};

		allocator_type get_allocator() const
		{
			return _alloc;
		}
		#pragma endregion // constructor
		///

		/// Destructor
		~Map(){ _delete_subtree(_root);}
		///

		/// Element access
		#pragma region element_access
		mapped_type &operator[](const key_type &key)
		{
			node *p = _find(_root,key);
			if(p)
				return p->value.second;
			else
				return _insert(_allocate(value_type(key, mapped_type())))->value.second;
		}
		#pragma endregion // element_access
		///

		/// Iterators
		#pragma region iterators
		iterator begin(){return iterator(_begin->parent);}
		iterator end(){return iterator(_end);}
		const_iterator begin() const {return const_iterator(_begin->parent);}
		const_iterator end() const {return const_iterator(_end);}

		reverse_iterator rbegin(){return reverse_iterator(_begin);}
		reverse_iterator rend(){return reverse_iterator(_end->parent);}
		const_reverse_iterator rbegin() const {return const_reverse_iterator(_begin);}
		const_reverse_iterator rend() const {return const_reverse_iterator(_end->parent);}
		#pragma endregion // iterators
		///

		/// Capacity
		#pragma region capacity
		size_type size() const{return _len;}
		bool empty() const{return _len == 0;}
		size_type max_size() const {return std::numeric_limits<size_type>::max() / sizeof(node);}
		#pragma endregion // capacity
		///

		/// Modifiers
		#pragma region modifiers
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

		iterator insert(iterator hint, const value_type& value )
		{
			node *n = _find(_root, value.first);
			if (n)
				return iterator(n);
			else
				return iterator(_insert(_allocate(value)));
		}
		template< class InputIt >
		void insert(InputIt first, InputIt last)
		{
			while(first != last)
			{
				insert(value_type(first->first, first->second));
				first++;
			}
		}

		void swap( Map& other)
		{
			ft::swap(_alloc, other._alloc);
			ft::swap(_node_alloc, other._node_alloc);
			ft::swap(_compare, other._compare);
			ft::swap(_v_compare, other._v_compare);
			ft::swap(_len, other._len);
			ft::swap(_root, other._root);
			ft::swap(_begin, other._begin);
			ft::swap(_end, other._end);
		}

		void erase( iterator pos )
		{
			_delete_node(pos._node());
		}
		void erase( iterator first, iterator last )
		{
			while(first != last)
				erase(first++);
		}
		size_type erase( const key_type& key)
		{
			iterator p = find(key);
			if (p != end())
				erase(p);
			return 1;
		}
		#pragma endregion /// modifiers
		///

		/// Lookup
		#pragma region lookup
		iterator find(const key_type &key)
		{
			if(_len==0)
				return (end());
			node *n = _find(_root, key);
			if(n)
				return (iterator(n));
			return end();
		}

		size_type	count(const key_type &value)
		{
			return static_cast<bool>(_find(_root,value) != 0);
		}

		iterator lower_bound(const key_type &key)
		{
			return iterator(_lower_bound(key));
		}

		const_iterator lower_bound(const key_type &key) const
		{
			return const_iterator (_lower_bound(key));
		}

		iterator upper_bound(const key_type &key)
		{
			return iterator(_upper_bound(key));
		}

		const_iterator upper_bound(const key_type &key) const
		{
			return const_iterator (_upper_bound(key));
		}

		ft::Pair<iterator,iterator> equal_range( const key_type & key )
		{
			return Pair<iterator,iterator>(iterator(_lower_bound(key)), iterator(_upper_bound(key)));
		}

		ft::Pair<const_iterator,const_iterator> equal_range( const key_type & key ) const
		{
			return Pair<const_iterator,const_iterator>(const_iterator(_lower_bound(key)), const_iterator(_upper_bound(key)));
		}
		#pragma endregion
		///

		/// Observers
		#pragma region observers
		key_compare key_comp() const
		{return _compare;}

		value_compare value_comp() const
		{return (value_compare(key_compare()));}
		#pragma endregion // observers
		///

	};

	#pragma region not_member_operators
	template< class T, class Alloc >
	bool operator==( const ft::Map<T,Alloc>& lhs,
					 const ft::Map<T,Alloc>& rhs ){
		if(lhs.size() != rhs.size())
			return false;
		typename ft::Map<T,Alloc>::const_iterator it_l = lhs.begin();
		typename ft::Map<T,Alloc>::const_iterator it_r = rhs.begin();
		while(it_l != lhs.end())
		{
			if (*it_l != *it_r)
				return false;
			it_l++;
			it_r++;
		}
		return true;
	}

	template< class T, class Alloc >
	bool operator!=( const ft::Map<T,Alloc>& lhs,
					 const ft::Map<T,Alloc>& rhs ){
		return !(lhs == rhs);
	}

	template< class T, class Alloc >
	bool operator<( const ft::Map<T,Alloc>& lhs,
					const ft::Map<T,Alloc>& rhs ){
		typename ft::Map<T,Alloc>::const_iterator pl = lhs.begin();
		typename ft::Map<T,Alloc>::const_iterator pr = rhs.begin();
		while (pl != lhs.end() && pr != rhs.end()){
			if (*pl < *pr)
				return true;
			pl++;
			pr++;
		}
		return lhs.size() < rhs.size();
	}

	template< class T, class Alloc >
	bool operator>( const ft::Map<T,Alloc>& lhs,
					const ft::Map<T,Alloc>& rhs ){
		typename ft::Map<T,Alloc>::const_iterator pl = lhs.begin();
		typename ft::Map<T,Alloc>::const_iterator pr = rhs.begin();
		while (pl != lhs.end() && pr != rhs.end()){
			if (*pl > *pr)
				return true;
			pl++;
			pr++;
		}
		return lhs.size() > rhs.size();
	}

	template< class T, class Alloc >
	bool operator>=( const ft::Map<T,Alloc>& lhs,
					 const ft::Map<T,Alloc>& rhs ){
		return !(lhs < rhs);
	}

	template< class T, class Alloc >
	bool operator<=( const ft::Map<T,Alloc>& lhs,
					 const ft::Map<T,Alloc>& rhs ){
		return !(lhs > rhs);
	}
	#pragma endregion // not_member_operators
}
#endif //MAP_HPP
