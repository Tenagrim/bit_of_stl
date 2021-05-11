//
// Created by Gerry Shona on 5/11/21.
//

#ifndef FT_CONTAINERS_LIST4_HPP
#define FT_CONTAINERS_LIST4_HPP

# include "Node.hpp"
# include <memory>

namespace ft {

	template<typename T, typename allocator=std::allocator<T> >
	class List {
	public:
		typedef T value_type;
		typedef List<T, allocator> container_type;
		typedef allocator allocator_type;
		typedef size_t size_type;
	private:
		typedef Node<value_type> node;
		typedef typename allocator::template rebind<Node<T> >::other
				node_allocator_type;

		size_type _len;
		allocator_type _alloc;
		node_allocator_type _node_alloc;
		node *_begin;
		node *_end;

		node *_create_node(node *next, node *prev, value_type data) {
			node *res = _node_alloc.allocate(1);
			res->data = data;
			res->next = next;
			res->prev = prev;
			return res;
		}

		void _init() {
			_begin = _create_node(0, 0, value_type());
			_end = _create_node(0, _begin, value_type());
			_begin->next = _end;
		}

	public:
		explicit List(const allocator_type &alloc = allocator_type()) :
				_len(0),
				_alloc(alloc),
				_end(0),
				_begin(0) {
			_init();
		}

		explicit List(size_type n, const value_type &value = value_type(),
					  const allocator_type &alloc = allocator_type()) :
				_len(0),
				_alloc(alloc),
				_begin(0),
				_end(0) {

		}

		void clear() {
			node *p = _begin->next;
			node *p2;
			while (p != _end) {
				p2 = p;
				p = p->next;
				_node_alloc.deallocate(p2, 1);
			}
			_begin->next = _end;
			_end->prev = _begin;
			_len = 0;
		}

		void push_back(const value_type &value) {
			node *add = _create_node(_end, _end->prev, value);
			_end->prev->next = add;
			_end->prev = add;
			_len++;
		}

		void push_front(const value_type &value) {
			node *add = _create_node(_begin->next, _begin, value);
			_begin->next->prev = add;
			_begin->next = add;
			_len++;
		}

		void pop_back() {
			node *p;
			if (_end->prev != _begin)
			{
				p = _end->prev->prev;
				_node_alloc.deallocate(_end->prev, 1);
				_end->prev = p;
				p->next = _end;
				_len--;
			}
		}

		void pop_front() {
			node *p;
			if (_end != _begin->next)
			{
				p = _begin->next->next;
				_node_alloc.deallocate(_begin->next, 1);
				_begin->next = p;
				p->prev = _begin;
				_len--;
			}
		}
	};
}

#endif //FT_CONTAINERS_LIST4_HPP
