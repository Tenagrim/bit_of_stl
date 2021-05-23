#ifndef STACK_HPP
#define STACK_HPP

#include "List.hpp"

namespace ft
{
	template<
			class T,
			class Container = ft::List<T>
	> class Stack
	{
	public:
		typedef T				value_type;
		typedef Container		container_type;
		typedef size_t 			size_type;
	protected:
		container_type 			c;
	public:
		explicit Stack(const container_type &cnt = container_type()){}
		Stack(const Stack &other) : c(other.c){}
		~Stack(){}
		Stack &operator=(const Stack &other){
			this->c = other.c;
			return *this;
		}
		size_type size(){return c.size();}
		bool empty(){return c.empty();}
		value_type &top(){return c.front;}
		void push(const value_type &value){c.push_front(value);}
		void pop(){c.pop_front();}
		void swap(Stack &other){c.swap(other.c);}

		//template< class T, class Container >
		friend bool operator==( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs );

		//template< class T, class Container >
		friend bool operator!=( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs );

		//template< class T, class Container >
		friend bool operator<( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs );

		//template< class T, class Container >
		friend bool operator<=( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs );

		//template< class T, class Container >
		friend bool operator>( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs );

		//template< class T, class Container >
		friend bool operator>=( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs );
	};

	template< class T, class Container >
	bool operator==( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs ){
		return lhs.c == rhs.c;
	}

	template< class T, class Container >
	bool operator!=( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs ) {
		return lhs.c != rhs.c;
	}

	template< class T, class Container >
	bool operator<( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs ) {
		return lhs.c < rhs.c;
	}

	template< class T, class Container >
	bool operator<=( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs ) {
		return lhs.c <= rhs.c;
	}

	template< class T, class Container >
	bool operator>( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs ) {
		return lhs.c > rhs.c;
	}

	template< class T, class Container >
	bool operator>=( const ft::Stack<T,Container>& lhs, const ft::Stack<T,Container>& rhs ) {
		return lhs.c >= rhs.c;
	}

}

#endif //STACK_HPP
