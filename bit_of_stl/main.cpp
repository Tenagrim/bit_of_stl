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
		std::cout << *it << ((it + 1 == c.end()) ? "" : " , ");
	std::cout << "]\n";
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

	//print_header("Assign");
	int test[] = {1,5,7,8};
	ft::Vector<int> v1;
	std::vector<int> v2;
	v1.assign(test, test + 4);
	v2.assign(test, test + 4);

	print(v1);
	print(v2);


	//check("v1 == v2", v1 == v2);
	v1.assign((size_t)10, 9);
	v2.assign((size_t)10, 9);
	//check("v1 == v2", v1 == v2);

	std::cout << "======================\n";
	print(v1);
	print(v2);
	return (0);

}
