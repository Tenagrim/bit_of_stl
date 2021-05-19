//
// Created by Gerry Shona on 5/19/21.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

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
			p += n;
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
	}

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
			p -= n;
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
	}

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
			p += n;
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
	}

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
			p -= n;
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
	private:
		allocator_type 							_alloc;
	public:
		Vector() {}

		Vector(const Vector &other) {}

		Vector &operator=(const Vector &other) {}

		~Vector() {}
		allocator_type get_allocator() const{return _alloc;}

	};
}

#endif //FT_CONTAINERS_VECTOR_HPP
