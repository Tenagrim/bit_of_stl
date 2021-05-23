#ifndef LIST_HPP
# define LIST_HPP

# include "Utils.hpp"
# include <memory>
# include <limits>

//# include <iostream> // TODO: remove

namespace ft {

	template<class T>
	struct Node
	{
		Node	*next;
		Node	*prev;
		T		data;
		Node(T&data): data(data), next(0), prev(0){}
	};

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

	template<typename T>
	class ListReverseIterator {
	private:
		typedef Node<T> *node_pointer;

		ListReverseIterator() {}

	protected:
		node_pointer _p;
	public:
		typedef T *pointer;
		typedef T &reference;
		typedef T value_type;

		~ListReverseIterator() {};

		ListReverseIterator(const ListReverseIterator &other) : _p(other._p) {}

		explicit ListReverseIterator(node_pointer p) : _p(p) {}

		ListReverseIterator &operator=(const ListReverseIterator &other) {
			this->_p = other._p;
			return *this;
		}

		ListReverseIterator &operator++() {
			_p = _p->prev;
			return *this;
		}

		ListReverseIterator &operator--() {
			_p = _p->next;
			return *this;
		}

		ListReverseIterator operator++(int) {
			ListReverseIterator tmp(*this);
			_p = _p->prev;
			return tmp;
		}

		ListReverseIterator operator--(int) {
			ListReverseIterator tmp(*this);
			_p = _p->next;
			return tmp;
		}

		bool operator==(const ListReverseIterator &other) {
			return _p == other._p;
		}

		node_pointer _node(){return _p;}

		bool operator!=(const ListReverseIterator &other) {
			return _p != other._p;
		}

		value_type &operator*() {
			return _p->data;
		}

		value_type *operator->() {
			return _p->data;
		}

		ListReverseIterator &operator+=(int n) {
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

		ListReverseIterator &operator-=(int n) {
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

		ListReverseIterator operator+(int n) {
			ListReverseIterator p(*this);
			p += n;
			return p;
		}

		ListReverseIterator operator-(int n) {
			ListReverseIterator p(*this);
			p -= n;
			return p;
		}

		ListIterator<value_type> base(){
			return ListIterator<value_type>(_p);
		}
	};

	template<typename T>
	class ListConstReverseIterator {
	private:
		typedef Node<T> *node_pointer;

		ListConstReverseIterator() {}

	protected:
		node_pointer _p;
	public:
		typedef T *pointer;
		typedef T &reference;
		typedef T value_type;

		~ListConstReverseIterator() {};

		ListConstReverseIterator(const ListConstReverseIterator &other) : _p(other._p) {}

		explicit ListConstReverseIterator(node_pointer p) : _p(p) {}

		ListConstReverseIterator &operator=(const ListConstReverseIterator &other) {
			this->_p = other._p;
			return *this;
		}

		ListConstReverseIterator &operator++() {
			_p = _p->prev;
			return *this;
		}

		ListConstReverseIterator &operator--() {
			_p = _p->next;
			return *this;
		}

		ListConstReverseIterator operator++(int) {
			ListConstReverseIterator tmp(*this);
			_p = _p->prev;
			return tmp;
		}

		ListConstReverseIterator operator--(int) {
			ListConstReverseIterator tmp(*this);
			_p = _p->next;
			return tmp;
		}

		bool operator==(const ListConstReverseIterator &other) {
			return _p == other._p;
		}

		node_pointer _node(){return _p;}

		bool operator!=(const ListConstReverseIterator &other) {
			return _p != other._p;
		}

		const value_type &operator*() {
			return _p->data;
		}

	 	const value_type *operator->() {
			return _p->data;
		}

		ListConstReverseIterator &operator+=(int n) {
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

		ListConstReverseIterator &operator-=(int n) {
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

		ListConstReverseIterator operator+(int n) {
			ListConstReverseIterator p(*this);
			p += n;
			return p;
		}

		ListConstReverseIterator operator-(int n) {
			ListConstReverseIterator p(*this);
			p -= n;
			return p;
		}

		ListConstIterator<value_type> base(){
			return ListConstIterator<value_type>(_p);
		}
	};



#pragma endregion // iterators

	template<class T, class allocator=std::allocator<T> >
	class List {
	public:
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef const T& const_reference;
		typedef List<T, allocator> container_type;
		typedef allocator allocator_type;
		typedef size_t size_type;
		typedef ListIterator<value_type> iterator;
		typedef ListConstIterator<value_type> const_iterator;
		typedef ListReverseIterator<value_type> reverse_iterator;
		typedef ListConstReverseIterator<value_type> const_reverse_iterator;
	private:
		typedef Node<value_type> node;

		typedef typename allocator::template rebind<Node<T> >::other
				node_allocator_type;

		typedef typename node_allocator_type::pointer _node_pointer;

		size_type				_len;
		allocator_type			_alloc;
		node_allocator_type		_node_alloc;
		node					*_begin;
		node					*_end;

		template<class P>
		struct Comp_Less {
			bool operator()(const P &a, const P &b) { return a > b; }
		};
		template<class P>
		struct Pred_equals {
			bool operator()(const P &a, const P &b) { return a == b; }
		};

		void _deallocate(node *n)
		{
			_node_alloc.destroy(n);
			_node_alloc.deallocate(n, 1);
//			delete n;
		}

		node *_allocate(value_type &data = value_type())
		{
			node *res = _node_alloc.allocate(1);
			_node_alloc.construct(res, node(data));
			return res;
//			return new node;
		}

		node *_create_node(node *next, node *prev, value_type data) {
//			node *res = _node_alloc.allocate(1);
			node *res = _allocate(data);
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
			//_node_alloc.destroy(n);
			_deallocate(n);
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
//			value_type  tmp = *first;
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
			_init();
			assign(n, value);
		}

		template<class InputIt>
		List(InputIt first, InputIt last, const allocator_type &alloc = allocator_type()) : _len(0), _alloc(alloc) {
			_init();
			assign(first, last);
		}

		List(const List &other) : _len(other._len), _alloc(other._alloc)
		{
			_init();
			assign(other.begin(), other.end());
		}

		List &operator=(const List &other)
		{
			if (&other == this)
				return *this;
			clear();
			assign(other.begin(), other.end());
			_len = other._len;
			return *this;
		}

		~List() {
			clear();
			//_node_alloc.destroy(_begin); //TODO:
//			_node_alloc.deallocate(_begin, 1);
			//_node_alloc.destroy(_end);
//			_node_alloc.deallocate(_end, 1);
			_deallocate(_begin);
			_deallocate(_end);
		}

		iterator begin() { return iterator(_begin->next); }
		const_iterator begin() const{return const_iterator(_begin->next);}

		iterator end() { return iterator(_end); }
		const_iterator end() const { return const_iterator(_end); }

		reverse_iterator rbegin() { return reverse_iterator(_begin); }
		const_reverse_iterator rbegin() const{return const_reverse_iterator(_begin);}

		reverse_iterator rend() { return reverse_iterator(_end->prev); }
		const_reverse_iterator rend() const { return const_reverse_iterator(_end->prev); }

		reference front() { return _begin->next->data; }

		reference back() { return _end->prev->data; }

		const_reference front() const { return _begin->next->data; }

		const_reference back() const { return _end->prev->data; }

		void swap(List &other)
		{
			ft::swap(_begin, other._begin);
			ft::swap(_end, other._end);
			ft::swap(_len, other._len);
			ft::swap(_alloc, other._alloc);
			ft::swap(_node_alloc, other._node_alloc);
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
				//_node_alloc.destroy(p2);
//				_node_alloc.deallocate(p2, 1);
				_deallocate(p2);
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
				//_node_alloc.destroy(_end->prev);
//				_node_alloc.deallocate(_end->prev, 1);
				_deallocate(_end->prev);
				_end->prev = p;
				p->next = _end;
				_len--;
			}
		}

		void pop_front() {
			node *p;
			if (_end != _begin->next) {
				p = _begin->next->next;
				//_node_alloc.destroy(_begin->next);
//				_node_alloc.deallocate(_begin->next, 1);
				_deallocate(_begin->next);
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
			return std::numeric_limits<size_type>::max() / sizeof(Node<T>);
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
			iterator res = pos + 1;
			_delete(pos._node());
			_len--;
			return res;
		}

		iterator erase(iterator first, iterator last)
		{
			//iterator res = last++;
			while (first != last)
				erase(first++);
//				_delete((first++)._node());
//			return res;
			return first;
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
					if (p(prev->data, next->data)){
						_delete(next);
						_len--;
						next = prev;
					}
					else
						prev = next;
				}
		}

		void remove(const value_type &value){
			node	*p = _begin->next;
			node	*p2 ;
			while(p != _end ){
				p2 = p;
				p = p->next;
				if(p2->data == value)
				{
					_delete(p2);
					_len--;
				}
			}
		}

		template<class Predicate>
		void remove_if(Predicate predicate){
			node	*p = _begin->next;
			node	*p2 ;
			while(p != _end ){
				p2 = p;
				p = p->next;
				if(predicate(p2->data))
				{
					_len--;
					_delete(p2);
				}
			}
		}

		void reverse()
		{
			node	*p = _begin;
			while(p != _end ){
				ft::swap(p->next, p->prev);

				p = p->prev;
			}
			ft::swap(_end->next, _end->prev);
			ft::swap(_begin, _end);
		}

		iterator insert( iterator pos, const value_type &value ){
			if (pos._node() == _begin->next)
			{
				push_front(value);
				return (begin());
			}
			if (pos._node() == _end)
			{
				push_back(value);
				return (end());
			}
			node *n = pos._node();
			node *p = n->prev;
			node *ins = _create_node(n, p, value);
			n->prev = ins;
			p->next = ins;
			_len++;
			return iterator(ins);
		}

		template< class InputIt >
		void insert( iterator pos, InputIt first, InputIt last){
			while (first != last)
			{
				pos = insert(pos, *(first++));
				if (pos != end())
					pos++;
			}
		}

		void insert( iterator pos, size_type count, const value_type &value ){
			while (count--)
				pos = insert(pos, value);
		}

		void splice(iterator pos, List& other ){
			splice(pos, other, other.begin(), other.end());
		}

		void splice(iterator pos, List& other, iterator it ){
			insert(pos, *it);
			other.erase(it);
		}

		void splice(iterator pos, List& other, iterator first, iterator last){
			insert(pos, first, last);
			other.erase(first, last);
		}

		void merge( List& other ){
			merge(other, Comp_Less<value_type>());
		}

		template <class Compare>
		void merge( List& other, Compare comp ){
			if (&other == this)
				return;
			insert(end(), other.begin(), other.end());
			other.clear();
			sort(comp);
		}
	};

	template< class T, class Alloc >
	bool operator==( const ft::List<T,Alloc>& lhs,
					 const ft::List<T,Alloc>& rhs ){
		if(lhs.size() != rhs.size())
			return false;
		typename ft::List<T,Alloc>::const_iterator it_l = lhs.begin();
		typename ft::List<T,Alloc>::const_iterator it_r = rhs.begin();
		while(it_l != lhs.end())
		{
			if (*it_l != *it_r)
				return false;
			it_l++;
			it_r++;
		}
		return true;
	}

	template< class T, class Alloc >
	bool operator!=( const ft::List<T,Alloc>& lhs,
					 const ft::List<T,Alloc>& rhs ){
		return !(lhs == rhs);
		return !(lhs == rhs);
	}

	template< class T, class Alloc >
	bool operator<( const ft::List<T,Alloc>& lhs,
					const ft::List<T,Alloc>& rhs ){
		typename ft::List<T,Alloc>::const_iterator pl = lhs.begin();
		typename ft::List<T,Alloc>::const_iterator pr = rhs.begin();
		while (pl != lhs.end() && pr != rhs.end()){
			if (*pl < *pr)
				return true;
			pl++;
			pr++;
		}
		return lhs.size() < rhs. size();
	}

	template< class T, class Alloc >
	bool operator>( const ft::List<T,Alloc>& lhs,
					const ft::List<T,Alloc>& rhs ){
		typename ft::List<T,Alloc>::const_iterator pl = lhs.begin();
		typename ft::List<T,Alloc>::const_iterator pr = rhs.begin();
		while (pl != lhs.end() && pr != rhs.end()){
			if (*pl > *pr)
				return true;
			pl++;
			pr++;
		}
		return lhs.size() > rhs. size();
	}

	template< class T, class Alloc >
	bool operator>=( const ft::List<T,Alloc>& lhs,
					 const ft::List<T,Alloc>& rhs ){
		return !(lhs < rhs);
	}

	template< class T, class Alloc >
	bool operator<=( const ft::List<T,Alloc>& lhs,
					 const ft::List<T,Alloc>& rhs ){
		return !(lhs > rhs);
	}

	template <class T, class Alloc>
	void swap(List<T, Alloc> &a, List<T, Alloc> &b)
	{
		a.swap(b);
	};
}

#endif //LIST_HPP