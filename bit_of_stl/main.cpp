#include <List.hpp>
#include "Vector.hpp"
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
//
//	std::vector<int> slist;
//	ft::Vector<int> list;
//	ft::Vector<int> list2;
//
//
//	for(int i = 0 ; i < 10; i++)
//	{
//		int r  = i + rand() % 10;
//		list.push_back(r);
//		slist.push_back(r);
//	}
//
//	list2 = list;
//	ft::Vector<int> list3(list);
//
//	print(list);
//	print(list2);
//	print(list3);
//
//	print(slist);
//

	ft::List<std::string> list;

	print(list);

/////////
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::List<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);

	print(l1);
	print(l2);
	std::cout << "before unique ^ ===\n";

	l1.unique();
	l2.unique();

	print(l1);
	print(l2);
	std::cout << "after unique ^ ===\n";


	l1.assign(test, test + 14);
	l2.assign(test, test + 14);

	print(l1);
	print(l2);

	std::cout << "===\n";

	l1.unique(compare);
	l2.unique(compare);

	print(l1);
	print(l2);

//////
//	std::cout << "l1 == l2: " << (l1 == l2) << ;


//////

//	ft::List<std::string> list;

	return (0);

}
