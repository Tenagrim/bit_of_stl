#pragma once
#include <memory>

#include <iostream> // <----------------- fixme

namespace ft
{
	template <typename T>
	struct list_node
	{
		list_node	*_prev;
		list_node	*_next;
		T			_data;

		explicit list_node(const T &__data = T()) : _data(__data), _next(NULL), _prev(NULL){}
		//list_node(const )
	};

	template <typename T>
	struct list_iterator
	{
		typedef	list_iterator<T>		_self_type;
		typedef	list_node<T>			_node_type;

		typedef	T						value_type;
		typedef	T*						pointer;
		typedef	T&						reference;


		const _node_type				*_node;

		list_iterator() : _node() {}
		list_iterator(list_node<T> *n) : _node(n) {}

		reference		operator*() const {return _node->_data;}
		_self_type		&operator++() {_node = _node->_next; return *this;}
		_self_type		operator++(int) {_self_type tmp = *this; _node = _node->_next; return tmp;}
		_self_type		&operator--() {_node = _node->_prev; return *this;}
		_self_type		operator--(int) {_self_type tmp = *this; _node = _node->_prev; return tmp;}
		bool			operator==(const _self_type &_x) const {return (_node == _x._node);}
		bool			operator!=(const _self_type &_x) const {return (_node != _x._node);}
	};
	
	template<class T, class Allocator = std::allocator<T> >
	class list
	{
		public:
			typedef T															value_type;	
			typedef typename Allocator::pointer									pointer;
			typedef size_t														size_type;
		private:
			typedef	list_iterator<T>											_iterator_type;
			typedef	list_node<T>												_node_type;
			typedef Allocator													_alloc_type;
			typedef typename Allocator::template rebind<list_node<T> >::other	_node_alloc_type;
			typedef list_node<T>												*_node_pointer;

			_node_type															*_nodes;
			_alloc_type															_alloc;
			_node_alloc_type													_node_alloc;
			size_type															_len;

			_node_type															*create_node(const value_type &x)
			{
				_node_type	*res = _node_alloc.allocate(1);
				std::cout << "node created\n";
				return (res);
			}
		public:
			explicit list(const _alloc_type &__alloc = _alloc_type()) : _alloc(__alloc), _len(0)
			{
				_nodes = create_node(1);
			}
			~list(){}
			list(const list &ref){}
			list &operator=(const list &ref){return (*this);}; 
	};
}