#ifndef NODE_H
# define NODE_H
namespace ft
{
	template<class T>
	struct Node
	{
		Node	*next;
		Node	*prev;
		T		*data;
	};
}
#endif