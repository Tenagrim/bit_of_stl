#pragma once
#include <memory>

#include <iostream> // <----------------- fixme

namespace ft
{
	template <typename T>
	struct list_node
	{
		list_node	*prev;
		list_node	*next;
		T			*data;

		list_node() {prev = NULL; next = NULL; data = NULL; std::cout << "node default constructor\n"; }
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
			typedef T								value_type;
			typedef typename Allocator::pointer		pointer;
		private:
			typedef	list_iterator<T>				_iterator_type;
			typedef	list_node<T>					_node_type;
			list_node								*_nodes;

			_node_type	*create_node(const value_type &x)
			{
				

			}
		public:



			list(){}
			~list(){}
			list(const list &ref){}
			list &operator=(const list &ref){return (*this);}; 
	};
}