//
// Created by Gerry Shona on 5/14/21.
//

#ifndef FT_CONTAINERS_UTILS_HPP
#define FT_CONTAINERS_UTILS_HPP

namespace ft {
	template<typename T>
	void swap(T&a, T&b) {
		T c = a;
		a = b;
		b = c;
	}
}

#endif //FT_CONTAINERS_UTILS_HPP
