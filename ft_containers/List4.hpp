//
// Created by Gerry Shona on 5/11/21.
//
#ifndef FT_CONTAINERS_LIST4_HPP
#define FT_CONTAINERS_LIST4_HPP

# include "Node.hpp"
#include "Utils.hpp"
# include <memory>
#include <limits>

namespace ft {

#pragma region iterators
	template<typename T>
	class ListIterator {
	private:
		typedef Node<T> *node_pointer;

		ListIterator() {}

	protected:
		node_pointer _p;
	public:
		typedef T *pointer;
		typedef T &reference;
		typedef T value_type;

		~ListIterator() {};

		ListIterator(const ListIterator &other) : _p(other._p) {}

		explicit ListIterator(node_pointer p) : _p(p) {}

		ListIterator &operator=(const ListIterator &other) {
			this->_p = other._p;
			return *this;
		}

		ListIterator &operator++() {
			_p = _p->next;
			return *this;
		}

		ListIterator &operator--() {
			_p = _p->prev;
			return *this;
		}

		ListIterator operator++(int) {
			ListIterator tmp(*this);
			_p = _p->next;
			return tmp;
		}

		ListIterator operator--(int) {
			ListIterator tmp(*this);
			_p = _p->prev;
			return tmp;
		}

		bool operator==(const ListIterator &other) {
			return _p == other._p;
		}

		node_pointer _node(){return _p;}

		bool operator!=(const ListIterator &other) {
			return _p != other._p;
		}

		value_type &operator*() {
			return _p->data;
		}

		value_type *operator->() {
			return _p->data;
		}

		ListIterator &operator+=(int n) {
			while (n < 0) {
				_p = _p->prev;
				n++;
			}
			while (n > 0) {
				_p = _p->next;
				n--;
			}
			return *this;
		}

		ListIterator &operator-=(int n) {
			while (n < 0) {
				_p = _p->next;
				n++;
			}
			while (n > 0) {
				_p = _p->prev;
				n--;
			}
			return *this;
		}

		ListIterator operator+(int n) {
			ListIterator p(*this);
			p += n;
			return p;
		}

		ListIterator operator-(int n) {
			ListIterator p(*this);
			p -= n;
			return p;
		}
	};

	template<typename T>
	class ListConstIterator {
	private:
		typedef Node<T> *node_pointer;

		ListConstIterator() {}

	protected:
		node_pointer _p;
	public:
		typedef T *pointer;
		typedef T &reference;
		typedef T value_type;

		~ListConstIterator() {};

		ListConstIterator(const ListConstIterator &other) : _p(other._p) {}

		explicit ListConstIterator(node_pointer p) : _p(p) {}

		ListConstIterator &operator=(const ListConstIterator &other) {
			this->_p = other._p;
			return *this;
		}

		ListConstIterator &operator++() {
			_p = _p->next;
			return *this;
		}

		ListConstIterator &operator--() {
			_p = _p->prev;
			return *this;
		}

		ListConstIterator operator++(int) {
			ListConstIterator tmp(*this);
			_p = _p->next;
			return tmp;
		}

		ListConstIterator operator--(int) {
			ListConstIterator tmp(*this);
			_p = _p->prev;
			return tmp;
		}

		bool operator==(const ListConstIterator &other) {
			return _p == other._p;
		}

		node_pointer _node(){return _p;}

		bool operator!=(const ListConstIterator &other) {
			return _p != other._p;
		}

		const value_type &operator*() {
			return _p->data;
		}

		const value_type *operator->() {
			return _p->data;
		}

		ListConstIterator &operator+=(int n) {
			while (n < 0) {
				_p = _p->prev;
				n++;
			}
			while (n > 0) {
				_p = _p->next;
				n--;
			}
			return *this;
		}

		ListConstIterator &operator-=(int n) {
			while (n < 0) {
				_p = _p->next;
				n++;
			}
			while (n > 0) {
				_p = _p->prev;
				n--;
			}
			return *this;
		}

		ListConstIterator operator+(int n) {
			ListConstIterator p(*this);
			p += n;
			return p;
		}

		ListConstIterator operator-(int n) {
			ListConstIterator p(*this);
			p -= n;
			return p;
		}
	};


#pragma endregion // iterators

	template<typename T, typename allocator=std::allocator<T> >
	class List {
	public:
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef List<T, allocator> container_type;
		typedef allocator allocator_type;
		typedef size_t size_type;
		typedef ListIterator<value_type> iterator;
		typedef ListConstIterator<value_type> const_iterator;
	private:
		typedef Node<value_type> node;
		typedef typename allocator::template rebind<Node<T> >::other
				node_allocator_type;

		size_type _len;
		allocator_type _alloc;
		node_allocator_type _node_alloc;
		node *_begin;
		node *_end;

		template<class P>
		struct Comp_Less {
			bool operator()(const P &a, const P &b) { return a > b; }
		};

		template<class P>
		struct Pred_equals {
			bool operator()(const P &a, const P &b) { return a == b; }
		};

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

		void _unlink(node *n){
			n->prev->next = n->next;
			n->next->prev = n->prev;
		}

		void _delete(node *n)
		{
			_unlink(n);
			_node_alloc.destroy(n);
			_node_alloc.deallocate(n, 1);
		}

		template<class Comparator>
		node *partition(node *l, node *h, Comparator comparator) {
			T x = h->data;

			node *i = l->prev;

			for (node *j = l; j != h; j = j->next) {
				if (!comparator(j->data, x)) {
					i = (i == NULL) ? l : i->next;
					ft::swap((i->data), (j->data));
				}
			}
			i = (i == NULL) ? l : i->next;
			ft::swap((i->data), (h->data));
			return i;
		}

		template<class Comparator>
		void _quickSort(node *l, node *h, Comparator comparator) {
			if (h != NULL && l != h && l != h->next) {
				node *p = partition(l, h, comparator);
				_quickSort(l, p->prev, comparator);
				_quickSort(p->next, h, comparator);
			}
		}

		template<class Comparator>
		void quickSort(Comparator comparator) {
			if (_len < 2)
				return;
			_quickSort(_begin->next, _end->prev, comparator);
		}

	public:
		void assign(size_type count, const T &value) {
			clear();
			while (count--)
				push_back(value);
		}

		template<class InputIt>
		void assign(InputIt first, InputIt last) {
			clear();
			value_type  tmp = *first;
			while (first != last)
				push_back(*(first++));
		}

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

		template<class InputIt>
		List(InputIt first, InputIt last, const allocator_type &alloc = allocator_type()) : _len(0) {
			_init();
			assign(first, last);
		}

		List(const List &other) : _len(other._len)
		{
			_init();
			assign(other.begin(), other.end());
		}

		List &operator=(const List &other)
		{
			clear();
			assign(other.begin(), other.end());
			_len = other._len;
			return *this;
		}

		~List() {
			clear();
			_node_alloc.destroy(_begin);
			_node_alloc.deallocate(_begin, 1);
			_node_alloc.destroy(_end);
			_node_alloc.deallocate(_end, 1);
		}

		iterator begin() { return iterator(_begin->next); }
		const_iterator begin() const{return const_iterator(_begin->next);}

		iterator end() { return iterator(_end); }
		const_iterator end() const { return const_iterator(_end); }

		reference front() { return _begin->next->data; }

		reference back() { return _end->prev->data; }

		void swap(List &other)
		{
			ft::swap(_begin, other._begin);
			ft::swap(_end, other._end);
			ft::swap(_len, other._len);
			ft::swap(_alloc);
			ft::swap(_node_alloc);
		}

		bool empty() const {
			return _len == 0;
		}

		size_type size() const {
			return _len;
		}

		void clear() {
			node *p = _begin->next;
			node *p2;
			while (p != _end) {
				p2 = p;
				p = p->next;
				_node_alloc.destroy(p2);
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
			if (_end->prev != _begin) {
				p = _end->prev->prev;
				_node_alloc.destroy(_end->prev);
				_node_alloc.deallocate(_end->prev, 1);
				_end->prev = p;
				p->next = _end;
				_len--;
			}
		}

		void pop_front() {
			node *p;
			if (_end != _begin->next) {
				p = _begin->next->next;
				_node_alloc.destroy(_begin->next);
				_node_alloc.deallocate(_begin->next, 1);
				_begin->next = p;
				p->prev = _begin;
				_len--;
			}
		}

		void resize(int n, value_type value = value_type())
		{
			while (n < _len)
				pop_back();
			while (n > _len)
				push_back(value);
		}

		allocator_type get_allocator() const {
			return _alloc;
		}

		size_type max_size() const {
			return std::numeric_limits<size_type>::max();
		}

		void sort() {
			quickSort(Comp_Less<value_type>());
		}

		template<class Comparator>
		void sort(Comparator comparator) {
			quickSort(comparator);
		};

		iterator erase(iterator pos)
		{
			iterator res = pos++;
			_delete(pos._node());
			return res;
		}

		iterator erase(iterator first, iterator last)
		{
			iterator res = last++;
			while (first != last)
				_delete((first++)._node);
			return res;
		}

		void unique()
		{
			unique(Pred_equals<value_type>());
		}

		template< class BinaryPredicate >
		void unique( BinaryPredicate p )
		{
				node *prev = _begin->next;
				node *next = prev;
				while(next->next != _end)
				{
					next = next->next;
					if (p(prev->data, next->data))
					{
						_delete(next);
						next = prev;
					}
					else
						prev = next;
				}
		}

		void remove(const value_type &value){

		}

	};
}

#endif //FT_CONTAINERS_LIST4_HPP