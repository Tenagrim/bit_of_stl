//
// Created by Gerry Shona on 4/18/21.
//

#ifndef FT_CONTAINERS_LIST_HPP
#define FT_CONTAINERS_LIST_HPP

#include <memory>

namespace ft {

	template <typename T>
	class ListNode
	{
	public:
		typedef 			T									value_type;
		ListNode() : _prev(NULL), _next(NULL), _data(NULL){}
		ListNode(const ListNode<T> &ref) : _prev(ref._prev), _next(ref._next), _data(ref._data){}
		//explicit ListNode(T *data): _data(data), _next(NULL), _prev(NULL){}
		explicit ListNode(const T &data) : _data(&data), _prev(NULL), _next(NULL){}
		ListNode(ListNode<T> *prev, ListNode<T> *next, T *data) : _prev(prev), _next(next), _data(_data){}
	private:
		ListNode<T> 			*_prev;
		ListNode<T> 			*_next;
		T 						_data;
	};


	template<typename T, typename allocator=std::allocator<T> >
	class List {
	public:
		typedef				T									value_type;
		typedef				List<T, allocator>					container_type;
		typedef				allocator							allocator_type;
		typedef typename	allocator_type::reference			reference;
		typedef typename	allocator_type::const_reference		const_reference;
		typedef typename	allocator_type::pointer				pointer;
		typedef typename	allocator_type::const_pointer		const_pointer;
		typedef				size_t								size_type;

		List()
		{
			len = 0;

		}

		~List() {}

		List(const container_type &ref){}
		List<T, allocator> &operator=(const container_type){return (*this);}

	private:
		typedef 			typename allocator::template rebind<ListNode<T> >::other
																node_allocator_type;
		typedef 			node_allocator_type::pointer		node_pointer;

		ListNode<T>			*_content;
		size_type 			_len;
		allocator_type 		_allocator;
		node_allocator_type _node_allocator;
	};

}
#endif //FT_CONTAINERS_LIST_HPP
