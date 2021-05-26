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
	std::cout << "size: " << c.size()<<"\n";
}

template <class Container>
void print_m(Container c)
{
	std::cout << "[";
	typename Container::iterator it = c.begin();
	for(; it != c.end(); it++)
		std::cout << "["<< (*it).first <<"|" << (*it).second << ( "] , ");
	std::cout << "]\n";
	std::cout << "size: " << c.size()<<"\n";
}

static bool compare(int a, int b)
{
	return (a >= b);
}

int	main(void)
{
	ft::Map<int,int> m;
//	std::srand(time(0));
	std::srand(100);

	print_m(m);

	for (int i = 0 ; i < 5; i++)
		m.deb_insert();
		/*
	m[0] =0;

	m[5] =0;
	m[4] =0;
	m[10] =0;
	m[8] =0;
	m[9] =0;
	m[6] =0;
	m[15] =0;
*/
	print_m(m);

	ft::Map<int,int>::iterator  p =m.lower_bound(76);

	std::cout << "lower_bound: ";
	if (p == m.end())
		std::cout << "not found\n";
	else
		std::cout  << p->first << "\n";



	return (0);

}
