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

	print_m(m);

	ft::Map<int,int>::iterator p =m.find(79);

	std::cout << "find(9): ";
	if (p == m.end())
		std::cout << "not found\n";
	else
		std::cout  << p->second << "\n";

	m.clear();

	m.insert(ft::Pair<int,int>(200,3000));

	print_m(m);
	return (0);

}
