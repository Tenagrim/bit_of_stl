#include <List.hpp>
#include "Vector.hpp"
#include "Map.hpp"
#include <list>
#include <vector>
//#include <list>
#include <iostream>

template <class Container>
void print(Container c)
{
	std::cout << "[";
	typename Container::iterator it = c.begin();
	for(; it != c.end(); it++)
		std::cout << *it << ( " , ");
	std::cout << "]\n";
}

static bool compare(int a, int b)
{
	return (a >= b);
}

int	main(void)
{
	ft::Map<int,int> m;

	return (0);

}
