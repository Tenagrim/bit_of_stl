#pragma once
#include <memory>

namespace ft
{
	struct _List_node_base
	{
		_List_node_base	*_prev;
		_List_node_base	*_next;
		static void			swap(_List_node_base &a, _List_node_base &b);
	};
	
	void		_List_node_base::swap(_List_node_base &a, _List_node_base &b)
	{
		_List_node_base	c = a;
		a = b;
		b = c;
	}

	template <typename T>
	struct _List_node : public _List_node_base
	{
		T								_data;
	};
	
	template <typename T>
	struct _List_iterator
	{
		typedef	_List_iterator<T>		_Self;
		typedef	_List_node<T>			_Node;

		typedef	T						value_type;
		typedef	T*						pointer;
		typedef	T&						reference;

		_List_node_base					*_node;

		_List_iterator() : _node() {}
		_List_iterator(_List_node_base *_n) : _node(_n) {}
		
		reference	operator*() const {return static_cast<_Node *>(_node)->_data;}
		_Self		&operator++() {_node = _node->_next; return *this;}
		_Self		operator++(int) {_Self tmp = *this; _node = _node->_next; return tmp;}
		_Self		&operator--() {_node = _node->_prev; return *this;}
		_Self		operator--(int) {_Self tmp = *this; _node = _node->_prev; return tmp;}
		bool		operator==(const _Self &_x) const {return (_node == _x._node);}
		bool		operator!=(const _Self &_x) const {return (_node != _x._node);}
	};

	template <typename T>
	struct _List_const_iterator
	{
		typedef	_List_const_iterator<T>	_Self;
		typedef	_List_node<T>			_Node;

		typedef	T						value_type;
		typedef	T*						pointer;
		typedef	T&						reference;

		_List_node_base					*_node;

		_List_const_iterator() : _node() {}
		_List_const_iterator(_List_node_base *_n) : _node(_n) {}
		
		reference	operator*() const {return static_cast<_Node *>(_node)->_data;}
		_Self		&operator++() {_node = _node->_next; return *this;}
		_Self		operator++(int) {_Self tmp = *this; _node = _node->_next; return tmp;}
		_Self		&operator--() {_node = _node->_prev; return *this;}
		_Self		operator--(int) {_Self tmp = *this; _node = _node->_prev; return tmp;}
		bool		operator==(const _Self &_x) const {return (_node == _x._node);}
		bool		operator!=(const _Self &_x) const {return (_node != _x._node);}
	};

	template <class T, class Allocator = std::allocator<T> >
	class _list_base
	{
		protected:
			typedef typename Allocator::template rebind<_List_node<T> >::other	_node_alloc_type;

			struct _list_impl : public _node_alloc_type
			{
				_List_node_base	_node;
				_list_impl(const _node_alloc_type &_a) : _node_alloc_type(_a){}
			};

			_list_impl		_impl;
			_List_node<T>	*_get_node(){return _impl._node_alloc_type::allocate(1);}
			void			_put_node(_List_node<T> *p){_impl._node_alloc_type::deallocate(_p, 1);}
		public:
		
	};

	template <class T, class Allocator = std::allocator<T> >
	class list
	{

	public:
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef size_t											size_type;

		list(){}
		~list(){}
		list(const ft::list<T, Allocator> &ref){}
		list<T, Allocator> &operator=(const ft::list<T, Allocator> &ref){return (*this);}


	private:
		allocator_type								_alloc;
	};
}