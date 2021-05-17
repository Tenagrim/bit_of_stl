
#include <List4.hpp>
#include <list>
//#include <list>
#include <iostream>

int	main(void)
{

	std::list<int> slist;
	ft::List<int> list;



	std::cout << "std front: " << slist.front() << "\n";
	std::cout << "std back:  " << slist.back() << "\n";

	std::cout << "my  front: " << list.front() << "\n";
	std::cout << "my  back:  " << list.back() << "\n";

	for(int i = 0 ; i < 10; i++)
		list.push_back(i + rand() % 10);

	ft::List<int>::iterator it = list.begin();
	for(; it != list.end(); it++)
		std::cout << *it << " ]\n";


	std::cout << "front: " << list.front() << "\n";
	std::cout << "back:  " << list.back() << "\n";

	list.sort();
	ft::List<int> list2 = list;

	it = list2.begin();
	for(; it != list2.end(); it++)
		std::cout << *it << " ]\n";
std::cout << "unique : ===============\n";
	list2.unique();
	it = list2.begin();
	for(; it != list2.end(); it++)
		std::cout << *it << " ]\n";

	std::cout << "reverse : ===============\n";
	list2.reverse();
	it = list2.begin();
	for(; it != list2.end(); it++)
		std::cout << *it << " ]\n";
	std::cout << "===============\n";
	it = list2.end() - 1;
	for(; it != list2.begin() - 1; it--)
		std::cout << *it << " ]\n";

	std::cout << "remove(10) : ===============\n";
	list2.remove(10);
	it = list2.begin();
	for(; it != list2.end(); it++)
		std::cout << *it << " ]\n";
	return (0);

}
