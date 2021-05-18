//
// Created by Gerry Shona on 5/18/21.
//

#ifndef FT_CONTAINERS_QUEUE_HPP
#define FT_CONTAINERS_QUEUE_HPP

#include "List.hpp"

namespace ft
{
	template<
			class T,
			class Container = ft::List<T>
	> class Queue
	{
	public:
		typedef T				value_type;
		typedef Container		container_type;
		typedef size_t 			size_type;
	protected:
		container_type 			c;
	public:
		explicit Queue(const container_type &cnt = container_type()){}
		Queue(const Queue &other) : c(other.c){}
		~Queue(){}
		Queue &operator=(const Queue &other){
			this->c = other.c;
			return *this;
		}
		size_type size(){return c.size();}
		bool empty(){return c.empty();}
		value_type &front(){return c.front;}
		value_type &back(){return c.back;}
		void push(const value_type &value){c.push_back(value);}
		void pop(){c.pop_front();}
		void swap(Queue &other){c.swap(other.c);}

		template< class T, class Container >
		friend bool operator==( const ft::Queue<T,Container>& lhs, const ft::Queue<T,Container>& rhs );

		template< class T, class Container >
		friend bool operator!=( const ft::Queue<T,Container>& lhs, const ft::Queue<T,Container>& rhs );

		template< class T, class Container >
		friend bool operator<( const ft::Queue<T,Container>& lhs, const ft::Queue<T,Container>& rhs );

		template< class T, class Container >
		friend bool operator<=( const ft::Queue<T,Container>& lhs, const ft::Queue<T,Container>& rhs );

		template< class T, class Container >
		friend bool operator>( const ft::Queue<T,Container>& lhs, const ft::Queue<T,Container>& rhs );

		template< class T, class Container >
		friend bool operator>=( const ft::Queue<T,Container>& lhs, const ft::Queue<T,Container>& rhs );

	};

	template< class T, class Container >
	bool operator==( const ft::Queue<T,Container>& lhs, const ft::Queue<T,Container>& rhs ){
		return lhs.c == rhs.c;
	}

	template< class T, class Container >
	bool operator!=( const ft::Queue<T,Container>& lhs, const ft::Queue<T,Container>& rhs ) {
		return lhs.c != rhs.c;
	}

	template< class T, class Container >
	bool operator<( const ft::Queue<T,Container>& lhs, const ft::Queue<T,Container>& rhs ) {
		return lhs.c < rhs.c;
	}

	template< class T, class Container >
	bool operator<=( const ft::Queue<T,Container>& lhs, const ft::Queue<T,Container>& rhs ) {
		return lhs.c <= rhs.c;
	}

	template< class T, class Container >
	bool operator>( const ft::Queue<T,Container>& lhs, const ft::Queue<T,Container>& rhs ) {
		return lhs.c > rhs.c;
	}

	template< class T, class Container >
	bool operator>=( const ft::Queue<T,Container>& lhs, const ft::Queue<T,Container>& rhs ) {
		return lhs.c >= rhs.c;
	}

}

#endif //FT_CONTAINERS_QUEUE_HPP
