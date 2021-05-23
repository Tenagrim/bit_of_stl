#ifndef VECTOR_HPP
#define VECTOR_HPP

# include <memory>
# include <limits>
# include "Utils.hpp"

namespace ft {

#pragma region iterators

	template<class T>
	class VectorIterator {
	private:
		VectorIterator() {};
	public:
		typedef T value_type;
	protected:
		value_type *_p;
	public:
		VectorIterator(const VectorIterator &other) : _p(other._p) {}
		VectorIterator(value_type *p) : _p(p){}
		VectorIterator &operator=(const VectorIterator &other) {
			if (&other == this)
				return *this;
			_p = other._p;
			return (*this);
		}

		~VectorIterator() {}

		VectorIterator &operator++() {
			_p += 1;
			return *this;
		}

		VectorIterator &operator--() {
			_p -= 1;
			return *this;
		}

		VectorIterator operator++(int) {
			VectorIterator tmp(*this);
			_p += 1;
			return tmp;
		}

		VectorIterator operator--(int) {
			VectorIterator tmp(*this);
			_p -= 1;
			return tmp;
		}

		bool operator==(const VectorIterator &other) {
			return _p == other._p;
		}

		bool operator!=(const VectorIterator &other) {
			return _p != other._p;
		}

		value_type &operator*() {
			return *_p;
		}

		value_type *operator->() {
			return _p;
		}

		VectorIterator &operator+=(int n) {
			_p += n;
			return *this;
		}

		VectorIterator &operator-=(int n) {
			_p -= n;
			return *this;
		}

		VectorIterator operator+(int n) {
			VectorIterator p(*this);
			p += n;
			return p;
		}

		VectorIterator operator-(int n) {
			VectorIterator p(*this);
			p -= n;
			return p;
		}
	};

	template<class T>
	class VectorReverseIterator {
	private:
		VectorReverseIterator() {};
	public:
		typedef T value_type;
	protected:
		value_type *_p;
	public:
		VectorReverseIterator(const VectorReverseIterator &other) : _p(other._p) {}
		VectorReverseIterator(const T* p) : _p(p){}
		VectorReverseIterator &operator=(const VectorReverseIterator &other) {
			if (&other == this)
				return *this;
			_p = other._p;
			return (*this);
		}

		~VectorReverseIterator() {}

		VectorReverseIterator &operator++() {
			_p -= 1;
			return *this;
		}

		VectorReverseIterator &operator--() {
			_p += 1;
			return *this;
		}

		VectorReverseIterator operator++(int) {
			VectorReverseIterator tmp(*this);
			_p -= 1;
			return tmp;
		}

		VectorReverseIterator operator--(int) {
			VectorReverseIterator tmp(*this);
			_p += 1;
			return tmp;
		}

		bool operator==(const VectorReverseIterator &other) {
			return _p == other._p;
		}

		bool operator!=(const VectorReverseIterator &other) {
			return _p != other._p;
		}

		value_type &operator*() {
			return *_p;
		}

		value_type *operator->() {
			return _p;
		}

		VectorReverseIterator &operator+=(int n) {
			_p -= n;
			return *this;
		}

		VectorReverseIterator &operator-=(int n) {
			_p += n;
			return *this;
		}

		VectorReverseIterator operator+(int n) {
			VectorReverseIterator p(*this);
			p -= n;
			return p;
		}

		VectorReverseIterator operator-(int n) {
			VectorReverseIterator p(*this);
			p += n;
			return p;
		}
	};

	template<class T>
	class VectorConstIterator {
	private:
		VectorConstIterator() {};
	public:
		typedef T value_type;
	protected:
		value_type *_p;
	public:
		VectorConstIterator(const VectorConstIterator &other) : _p(other._p) {}
		VectorConstIterator(value_type *p) : _p(p){}
		VectorConstIterator &operator=(const VectorConstIterator &other) {
			if (&other == this)
				return *this;
			_p = other._p;
			return (*this);
		}

		~VectorConstIterator() {}

		VectorConstIterator &operator++() {
			_p += 1;
			return *this;
		}

		VectorConstIterator &operator--() {
			_p -= 1;
			return *this;
		}

		VectorConstIterator operator++(int) {
			VectorConstIterator tmp(*this);
			_p += 1;
			return tmp;
		}

		VectorConstIterator operator--(int) {
			VectorConstIterator tmp(*this);
			_p -= 1;
			return tmp;
		}

		bool operator==(const VectorConstIterator &other) {
			return _p == other._p;
		}

		bool operator!=(const VectorConstIterator &other) {
			return _p != other._p;
		}

		const value_type &operator*() {
			return *_p;
		}

		const value_type *operator->() {
			return _p;
		}

		VectorConstIterator &operator+=(int n) {
			_p += n;
			return *this;
		}

		VectorConstIterator &operator-=(int n) {
			_p -= n;
			return *this;
		}

		VectorConstIterator operator+(int n) {
			VectorConstIterator p(*this);
			p += n;
			return p;
		}

		VectorConstIterator operator-(int n) {
			VectorConstIterator p(*this);
			p -= n;
			return p;
		}
	};

	template<class T>
	class VectorConstReverseIterator {
	private:
		VectorConstReverseIterator() {};
	public:
		typedef T value_type;
	protected:
		value_type *_p;
	public:
		VectorConstReverseIterator(const VectorConstReverseIterator &other) : _p(other._p) {}
		VectorConstReverseIterator(const T* p) : _p(p){}
		VectorConstReverseIterator &operator=(const VectorConstReverseIterator &other) {
			if (&other == this)
				return *this;
			_p = other._p;
			return (*this);
		}

		~VectorConstReverseIterator() {}

		VectorConstReverseIterator &operator++() {
			_p -= 1;
			return *this;
		}

		VectorConstReverseIterator &operator--() {
			_p += 1;
			return *this;
		}

		VectorConstReverseIterator operator++(int) {
			VectorConstReverseIterator tmp(*this);
			_p -= 1;
			return tmp;
		}

		VectorConstReverseIterator operator--(int) {
			VectorConstReverseIterator tmp(*this);
			_p += 1;
			return tmp;
		}

		bool operator==(const VectorConstReverseIterator &other) {
			return _p == other._p;
		}

		bool operator!=(const VectorConstReverseIterator &other) {
			return _p != other._p;
		}

		const value_type &operator*() {
			return *_p;
		}

		const value_type *operator->() {
			return _p;
		}

		VectorConstReverseIterator &operator+=(int n) {
			_p -= n;
			return *this;
		}

		VectorConstReverseIterator &operator-=(int n) {
			_p += n;
			return *this;
		}

		VectorConstReverseIterator operator+(int n) {
			VectorConstReverseIterator p(*this);
			p -= n;
			return p;
		}

		VectorConstReverseIterator operator-(int n) {
			VectorConstReverseIterator p(*this);
			p += n;
			return p;
		}


	};

#pragma endregion // iterators

	template<class T, class Allocator = std::allocator <T> >
	class Vector {
	public:
		typedef T								value_type;
		typedef Allocator						allocator_type;
		typedef size_t							size_type;
		typedef VectorIterator<T>				iterator;
		typedef VectorReverseIterator<T>		reverse_iterator;
		typedef VectorConstIterator<T>			const_iterator;
		typedef VectorConstReverseIterator<T>	const_reverse_iterator;
		typedef T&								reference;
		typedef const T&						const_reference;
		typedef T*								pointer;
		typedef const T*						const_pointer;
	private:
		allocator_type 							_alloc;
		size_type								_len;
		size_type								_cap;
		T*										_content;

		void _double_cap_if_need(size_type n = 1)
		{
			if (_len + n > _cap)
			{
				int new_cap = _len > 0 ? _len * 2 : 1;
				reserve(new_cap);
			}
		}

		void check_out_of_range(size_type n)
		{
			if (n >= _len)
				throw (std::out_of_range("index is out of range"));
		}
	public:
		explicit Vector(const allocator_type &alloc = allocator_type()) :
		_len(0), _cap(0), _content(0), _alloc(alloc) {}
		
		explicit Vector(size_type n, const value_type &value = value_type (),
				  const allocator_type &alloc = allocator_type()) :
				_len(0), _cap(0), _content(0), _alloc(alloc) {
			_content = _alloc.allocate(n);
			T	*p = _content;
			while(n--)
			{
				_alloc.construct(p, value);
				p++;
			}
		}

		template<class InputIterator>
		explicit Vector(InputIterator first, InputIterator last,
						const allocator_type &alloc = allocator_type()) :
				_len(0), _cap(0), _content(0), _alloc(alloc) {
			assign(first, last);
		}

		Vector(const Vector &other) : _len(0), _cap(0) {
			assign(other.begin(), other.end());
		}

		Vector &operator=(const Vector &other) {
			if (&other == this)
				return *this;
			clear();
			assign(other.begin(), other.end());
			return *this;
		}

		~Vector() { _alloc.deallocate(_content, _len);}

		size_type max_size() const {
			return std::numeric_limits<size_type>::max() / sizeof(value_type);
		}

		allocator_type get_allocator() const{return _alloc;}

		iterator begin() { return iterator(_content); }
		const_iterator begin() const{return const_iterator(_content);}

		iterator end() { return iterator(_content + _len); }
		const_iterator end() const { return const_iterator(_content + _len); }

		reverse_iterator rbegin() { return reverse_iterator(_content + _len - 1); }
		const_reverse_iterator rbegin() const{return const_reverse_iterator(_content + _len - 1);}

		reverse_iterator rend() { return reverse_iterator(_content - 1); }
		const_reverse_iterator rend() const { return const_reverse_iterator(_content - 1); }

		reference front() { return *_content; }

		reference back() { return *(_content + _len - 1); }

		iterator erase(iterator position)
		{
			T	*p1 = &(*position);
			while(p1 + 1 != _content + _len)
			{
				*p1 = *(p1 + 1);
				p1++;
			}
			_len--;
			return iterator(position);
		}

		iterator erase(iterator first, iterator last)
		{
			while(first != last)
			{
				erase(first);
				last--;
			}
			return iterator(first);
		}

		void clear()
		{
			for(int i = 0; i < _len; i++)
				_alloc.destroy(_content + i);
			_len = 0;
		}

		reference operator[](size_type n){return _content[n];}
		const_reference operator[](size_type n) const {return _content[n];}

		reference at(size_type n)
		{
			check_out_of_range(n);
			return _content[n];
		}

		const_reference at(size_type n) const
		{
			check_out_of_range(n);
			return _content[n];
		}

		size_type	size()		const	{return _len;}
		size_type	capacity()	const	{return _cap;}
		bool		empty()		const	{return _len == 0;}


		void reserve(size_type new_cap)
		{
			if (new_cap > max_size())
				throw (std::length_error("new_cap is too big"));
			int i = -1;
			if (new_cap > _cap)
			{
				T* tmp = _alloc.allocate(new_cap);
				while(++i < _len)
					_alloc.construct(tmp + i, _content[i]);
				if (_len)
				_alloc.deallocate(_content, _len);
				_content  = tmp;
				_cap = new_cap;
			}
		}

		void resize(size_type count , value_type value = value_type())
		{
			while (count < _len)
				pop_back();
			while (count > _len)
				push_back(value);
		}

		void push_back(const value_type &value)
		{
			_double_cap_if_need();
			_alloc.construct(_content + _len , value);
			_len++;
		}

		void pop_back()
		{
			if (_len  > 0)
			{
				_alloc.destroy(_content + _len -1);
				_len--;
			}
		}

		iterator insert(iterator position, const value_type &value)
		{
			int pos =  &(*position) - _content;
			_double_cap_if_need();
			for(int i = _len; i > pos; i--)
				_content[i] = _content[i -1];
			_alloc.construct(_content + pos, value);
			_len++;
			return iterator(_content + pos);
		}

		void insert(iterator position, size_type n, const value_type &value)
		{
			while (n--)
				position = insert(position, value);
		}

		template<class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				position = insert(position, *first) + 1;
				first++;
			}
		}

		template<class InputIterator>
		void assign(InputIterator first, InputIterator last){
			clear();
			insert(begin(), first, last);
		}

		void assign(size_type n, const value_type &value)
		{
			clear();
			insert(begin(), n , value);
		}

		void swap(Vector &other)
		{
			ft::swap(_content, other._content);
			ft::swap(_len, other._len);
			ft::swap(_cap, other._cap);
			ft::swap(_alloc, other._alloc);
		}
	};


	template< class T, class Alloc >
	bool operator==( const ft::Vector<T,Alloc>& lhs,
					 const ft::Vector<T,Alloc>& rhs ){
		if(lhs.size() != rhs.size())
			return false;
		typename ft::Vector<T,Alloc>::const_iterator it_l = lhs.begin();
		typename ft::Vector<T,Alloc>::const_iterator it_r = rhs.begin();
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
	bool operator!=( const ft::Vector<T,Alloc>& lhs,
					 const ft::Vector<T,Alloc>& rhs ){
		return !(lhs == rhs);
	}

	template< class T, class Alloc >
	bool operator<( const ft::Vector<T,Alloc>& lhs,
					const ft::Vector<T,Alloc>& rhs ){
		typename ft::Vector<T,Alloc>::const_iterator pl = lhs.begin();
		typename ft::Vector<T,Alloc>::const_iterator pr = rhs.begin();
		while (pl != lhs.end() && pr != rhs.end()){
			if (*pl < *pr)
				return true;
			pl++;
			pr++;
		}
		return lhs.size() < rhs.size();
	}

	template< class T, class Alloc >
	bool operator>( const ft::Vector<T,Alloc>& lhs,
					const ft::Vector<T,Alloc>& rhs ){
		typename ft::Vector<T,Alloc>::const_iterator pl = lhs.begin();
		typename ft::Vector<T,Alloc>::const_iterator pr = rhs.begin();
		while (pl != lhs.end() && pr != rhs.end()){
			if (*pl > *pr)
				return true;
			pl++;
			pr++;
		}
		return lhs.size() > rhs.size();
	}

	template< class T, class Alloc >
	bool operator>=( const ft::Vector<T,Alloc>& lhs,
					 const ft::Vector<T,Alloc>& rhs ){
		return !(lhs < rhs);
	}

	template< class T, class Alloc >
	bool operator<=( const ft::Vector<T,Alloc>& lhs,
					 const ft::Vector<T,Alloc>& rhs ){
		return !(lhs > rhs);
	}
}

#endif //VECTOR_HPP
