#pragma once

#include <utility>
#include <cassert>
#include <stdexcept>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <omp.h>

using namespace std;

enum TypeMatrix { 
	EMPTY,
	NONEMPTY,
	ADJACENCY,
	ADJACENCY_SQUARED,
	NBTW_ADJACENCY 
};

template <typename M, size_t N>
class Matrix {
public:
	 //explicit default constructor
	explicit Matrix() : 
	size_(N),
	matrix_(nullptr),
	unity_(1u),
	type_(TypeMatrix::EMPTY) 
	{
		allocate(size_);
		//cout << "\nDefault const called\n";
	}

	//copy constructor
	Matrix(const Matrix<M, N>& mat) : 
	size_(mat.get_size()),
	matrix_(new M[mat.get_size() * mat.get_size()]),
	unity_(1u), 
	type_(mat.get_type())
	{
		memcpy(matrix_, mat.data(), sizeof(M) * mat.get_size() * mat.get_size());
		//cout << "\nCopy const called\n";
	}

	//copy assignment
	void operator=(const Matrix<M, N>& mat)
	{	
		size_   = mat.size_;
		unity_  = mat.unity_;
		type_   = mat.type_;
		matrix_ = new M[mat.get_size() * mat.get_size()];
		memcpy(matrix_, mat.data(), sizeof(M) * mat.get_size() * mat.get_size());
		//cout << "\nCopy ass called\n";
	}

	//move constructor
	Matrix(Matrix<M, N>&& mat) : 
	size_(mat.size_),
	matrix_(mat.matrix_), 
	unity_(mat.unity_),
	type_(mat.type_)
	{
		mat.size_   = 0;
		mat.matrix_ = nullptr;
		mat.type_	= TypeMatrix::EMPTY;
		//cout << "\nMove const called\n";
	}

	//move assigment
	void operator=(Matrix<M, N>&& mat)
	{
		//delete[] matrix_;
		//kill();
		swap(size_, mat.size_);
		swap(matrix_, mat.matrix_);
		swap(unity_, mat.unity_);
		swap(type_, mat.type_);
		//cout << "\nMove ass called\n";
	}

	//destructor
	~Matrix()
	{ 
		kill(); 
	}

	void allocate(size_t n);

	void clear();

	void fill(const M* data, size_t dsize);

	inline void identity();

	inline M sum_row(M start, M end);

	inline const M* data() const;
	
	inline const M getv(const size_t y, const size_t x) const;

	inline void set_v(size_t y, size_t x, M val);
	
	inline void add_v(size_t y, size_t x, M val);

	inline const size_t get_size() const;

	inline const size_t index(size_t y, size_t x)  const;

	inline const size_t ind(size_t i) const;

	inline const size_t matrix_length() const;

	inline M rowFirst(size_t index);

	inline M rowLast(size_t index);

	inline const TypeMatrix get_type() const;

	inline bool empty();

private:
	size_t size_; 
	M* matrix_;
	M unity_;
	TypeMatrix type_;

	void kill() {
		//assert(!empty()); ?fixing
		delete[] matrix_; 
	}
};

template<typename M, size_t N>
void Matrix<M, N>::allocate(size_t n)
{
	matrix_ = new M[n * n];
	clear(); // ?
}

template<typename M, size_t N>
void Matrix<M, N>::clear() 
{
	for (size_t y = 0; y < get_size(); y++) {
		for (size_t x = 0; x < get_size(); x++) {
			set_v(y, x, 0);
		}
	}
}

template<typename M, size_t N>
void Matrix<M, N>::fill(const M* data, size_t dsize) 
{
	assert(dsize == matrix_length());
	for (size_t y = 0; y < get_size(); y++) {
		for (size_t x = 0; x < get_size(); x++) {
			M val = data[x + y * get_size()]; //this is bad place

			set_v(y, x, val);
		}
	}
	type_ = TypeMatrix::NONEMPTY;
}

template<typename M, size_t N>
inline void Matrix<M, N>::identity()
{
	for (size_t y = 0; y < get_size(); y++){
		set_v(y, y, 1);
	}
}

template<typename M, size_t N>
inline M Matrix<M, N>::sum_row(M start, M end)
{
	M sum = 0u;
	for(int i = start; i < end; i++) {
		sum += matrix_[i];
	}
	return sum;
}

template<typename M, size_t N>
inline const M* Matrix<M, N>::data() const
{
	return matrix_;
}

template<typename M, size_t N>
inline const M Matrix<M, N>::getv(const size_t y, const size_t x) const 
{  
	return matrix_[index(y, x)]; 
}

template<typename M, size_t N>
inline void Matrix<M, N>::set_v(size_t y, size_t x, M val)
{ 
	matrix_[index(y, x)] = val;
}

template<typename M, size_t N>
inline void Matrix<M, N>::add_v(size_t y, size_t x, M val)
{ 
	matrix_[index(y, x)] += val;
}

template<typename M, size_t N>
inline const size_t Matrix<M, N>::get_size() const 
{ 
	return size_;
}

template<typename M, size_t N>
inline const size_t Matrix<M, N>::index(size_t y, size_t x)  const 
{
	return x + y * get_size();
}

template<typename M, size_t N>
inline const size_t Matrix<M, N>::ind(size_t i) const 
{ 
	return i - 1;
}

template<typename M, size_t N>
inline const size_t Matrix<M, N>::matrix_length() const 
{ 
	return get_size()*get_size();
}

template<typename M, size_t N>
inline M Matrix<M, N>::rowFirst(size_t index)
{ 
	return index*get_size();
}

template<typename M, size_t N>
inline M Matrix<M, N>::rowLast(size_t index)
{ 
	return index*get_size() + get_size();
}

template<typename M, size_t N>
inline const TypeMatrix Matrix<M, N>::get_type() const
{ 
	return type_;
}

template<typename M, size_t N>
inline bool Matrix<M, N>::empty()
{ 
	return (get_type() == TypeMatrix::EMPTY);
}