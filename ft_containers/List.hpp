#pragma once
#include <memory>

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class list
	{
	private:
		class	Node
		{
				private:
					T		content;
					Node	*next;
					Node	*prev;
				public:
					Node();
					~Node();
					Node(const Node &ref);
					Node &operator=(const Node &ref); 
		};
	public:
		typedef T									value_type;
		typedef Allocator							allocator_type;
		typedef allocator_type::reference			reference;
		typedef allocator_type::const_reference		const_reference;
		typedef allocator_type::pointer				pointer;
		typedef allocator_type::const_pointer		const_pointer;
		typedef size_t								size_type;
		list();
		~list();
		list(const ft::list<T, Allocator> &ref);
		list<T, Allocator> &operator=(const ft::list<T, Allocator> &ref); 
	};
}
template <class T, class Allocator>
ft::list<T, Allocator>::Node()
{

}

template <class T, class Allocator>
ft::list<T, Allocator>::Node()
{
	Allocator.
}

template <class T, class Allocator>
ft::list<T, Allocator>::list()
{

}

template <class T, class Allocator>
ft::list<T, Allocator>::~list()
{

}

template <class T, class Allocator>
ft::list<T, Allocator>::list(const ft::list<T, Allocator> &ref)
{

}

template <class T, class Allocator>
ft::list<T, Allocator>	&ft::list<T, Allocator>::operator=(const ft::list<T, Allocator> &ref)
{
	return (*this);
}


