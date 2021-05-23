//
// Created by Gerry Shona on 5/23/21.
//

#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include "Utils.hpp"

namespace ft
{
	template <
	        class Key,
			class T
	> class M_Node{


	};


	template<
			class Key,
			class T,
			class Compare = ft::less<Key>,
			class Allocator = std::allocator<ft::Pair<const Key, T> >
	> class map{
	public:
		typedef Key						key_type;
		typedef	T						mapped_type;
		typedef	std::pair<const Key, T> value_type;
		typedef size_t 					size_type;

	};
}
#endif //MAP_HPP
