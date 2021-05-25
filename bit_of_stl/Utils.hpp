#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft {

	template<typename T>
	void swap(T&a, T&b) {
		T c = a;
		a = b;
		b = c;
	}

	template<
			class T1,
			class T2
	> struct Pair{
		typedef		T1	first_type;
		typedef		T2	second_type;

		first_type 		first;
		second_type		second;

		Pair(): first(), second(){}
		Pair(const T1 &first, const T2 &second): first(first), second(second){}
		Pair &operator=(const Pair &other) { first = other.first; second = other.second;}
		void swap(Pair &other) {ft::swap(first, other.first); ft::swap(second, other.second);}
	};

	template< class T1, class T2 >
	bool operator==( const ft::Pair<T1,T2>& lhs, const ft::Pair<T1,T2>& rhs ){
		return lhs.first == rhs.second && lhs.first == rhs.second;
	}

	template< class T1, class T2 >
	bool operator!=( const ft::Pair<T1,T2>& lhs, const ft::Pair<T1,T2>& rhs ){
		return !(lhs == rhs);
	}

	template< class T1, class T2 >
	bool operator<( const ft::Pair<T1,T2>& lhs, const ft::Pair<T1,T2>& rhs ){
		return lhs.first < rhs.second || lhs.first < rhs.second;
	}

	template< class T1, class T2 >
	bool operator<=( const ft::Pair<T1,T2>& lhs, const ft::Pair<T1,T2>& rhs ){
		return !(lhs > rhs);
	}

	template< class T1, class T2 >
	bool operator>( const ft::Pair<T1,T2>& lhs, const ft::Pair<T1,T2>& rhs ){
		return lhs.first > rhs.second || lhs.first > rhs.second;
	}

	template< class T1, class T2 >
	bool operator>=( const ft::Pair<T1,T2>& lhs, const ft::Pair<T1,T2>& rhs ){
		return !(lhs < rhs);
	}

	template< class T >
	struct less
	{
		bool operator()( const T& lhs, const T& rhs ) const{
			return lhs < rhs;
		}
	};



}

#endif //UTILS_HPP
