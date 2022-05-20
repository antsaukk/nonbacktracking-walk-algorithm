#pragma once

#include "padder.h"
#include "util.h"

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

template <typename M, size_t NY, size_t NX>
class Matrix {
public:
	 //explicit default constructor
	explicit Matrix() : 
	ny_(NY),
	nx_(NX),
	matrix_(nullptr),
	unity_(1u),
	type_mat_(TypeMatrix::EMPTY),
	type_avx_(TypeAVX::NONE)
	{
		allocate(ny_, nx_);
	}

	//copy constructor
	Matrix(const Matrix<M, NY, NX>& mat) :
	ny_(mat.ny_),
	nx_(mat.nx_),
	matrix_(new M[mat.ny_ * mat.nx_]),
	unity_(1u), 
	type_mat_(mat.type_mat_),
	type_avx_(mat.type_avx_)
	{
		memcpy(matrix_, mat.data(), sizeof(M) * mat.ny_ * mat.nx_);
	}

	//copy assignment -- not safely implemented
	void operator=(Matrix<M, NY, NX>& mat)
	{	
		ny_   = mat.ny_;
		nx_   = mat.nx_;
		memcpy(matrix_, mat.data(), sizeof(M) * mat.ny_ * mat.nx_);
		unity_  = mat.unity_;
		type_mat_   = mat.type_mat_;
	}

	//move constructor
	Matrix(Matrix<M, NY, NX>&& mat) :
	ny_(mat.ny_), 
	nx_(mat.nx_),
	matrix_(mat.matrix_), 
	unity_(mat.unity_),
	type_mat_(mat.type_mat_),
	type_avx_(mat.type_avx_)
	{
		mat.ny_   = 0;
		mat.nx_   = 0;
		mat.matrix_ = nullptr;
		mat.type_mat_	= TypeMatrix::EMPTY;
	}

	//move assigment
	void operator=(Matrix<M, NY, NX>&& mat)
	{
		swap(ny_, mat.ny_);
		swap(nx_, mat.nx_);
		swap(matrix_, mat.matrix_);
		swap(unity_, mat.unity_);
		swap(type_mat_, mat.type_mat_);
		swap(type_avx_, mat.type_avx_);
	}

	//destructor
	~Matrix()
	{ 
		kill(); 
	}

	void fill(const M* data, size_t dsize);

	inline void identity();

	inline void vectorize();

	inline M sum_row(M start, M end);

	inline const M* data() const;
	
	inline const M getv(const size_t y, const size_t x) const;

	inline void set_v(size_t y, size_t x, M val);
	
	inline void add_v(size_t y, size_t x, M val);

	inline const size_t get_ny() const;

	inline const size_t get_nx() const;

	inline const size_t index(size_t y, size_t x)  const;

	inline const size_t ind(size_t i) const;

	inline const size_t matrix_length() const;

	inline M rowFirst(size_t index);

	inline M rowLast(size_t index);

	inline const TypeMatrix get_matrix_type() const;

	inline const TypeAVX get_avx_type() const;

	inline bool empty();

private:
	size_t ny_;
	size_t nx_;
	M* matrix_;
	M unity_;
	TypeMatrix type_mat_;
	TypeAVX type_avx_;

	typedef M vectorized_t __attribute__((vector_size(32)));

	Padder<vectorized_t, NY, NX> vect;

	void allocate(size_t ny, size_t nx);

	void clear();

	void kill() {
		//assert(!empty()); ? fixing
		delete[] matrix_; 
	}
	
};

template <typename M, size_t NY, size_t NX>
void Matrix<M, NY, NX>::allocate(size_t ny, size_t nx)
{
	matrix_ = new M[ny * nx];
	clear();
}

template <typename M, size_t NY, size_t NX>
void Matrix<M, NY, NX>::clear() 
{
	for (size_t y = 0; y < ny_; y++) {
		for (size_t x = 0; x < nx_; x++) {
			set_v(y, x, 0);
		}
	}
}

template <typename M, size_t NY, size_t NX>
void Matrix<M, NY, NX>::fill(const M* data, size_t dsize) 
{
	assert(dsize == matrix_length());
	for (size_t y = 0; y < ny_; y++) {
		for (size_t x = 0; x < nx_; x++) {
			M val = data[index(y, x)]; 
			set_v(y, x, val);
		}
	}
	type_mat_ = TypeMatrix::NONEMPTY;
}

template <typename M, size_t NY, size_t NX>
inline void Matrix<M, NY, NX>::vectorize()
{ }

/*template <typename M, size_t NY, size_t NX>
inline void Matrix<M, NY, NX>::identity()
{
	for (size_t y = 0; y < get_size(); y++){
		set_v(y, y, 1);
	}
}*/

template <typename M, size_t NY, size_t NX>
inline M Matrix<M, NY, NX>::sum_row(M start, M end)
{
	M sum = 0u;
	for(int i = start; i < end; i++) {
		sum += matrix_[i];
	}
	return sum;
}

template <typename M, size_t NY, size_t NX>
inline const M* Matrix<M, NY, NX>::data() const
{
	return matrix_;
}

template <typename M, size_t NY, size_t NX>
inline const M Matrix<M, NY, NX>::getv(const size_t y, const size_t x) const 
{  
	return matrix_[index(y, x)]; 
}

template <typename M, size_t NY, size_t NX>
inline void Matrix<M, NY, NX>::set_v(size_t y, size_t x, M val)
{ 
	matrix_[index(y, x)] = val;
}

template <typename M, size_t NY, size_t NX>
inline void Matrix<M, NY, NX>::add_v(size_t y, size_t x, M val)
{ 
	matrix_[index(y, x)] += val;
}

template <typename M, size_t NY, size_t NX>
inline const size_t Matrix<M, NY, NX>::get_ny() const 
{ 
	return ny_;
}

template <typename M, size_t NY, size_t NX>
inline const size_t Matrix<M, NY, NX>::get_nx() const 
{ 
	return nx_;
}

template <typename M, size_t NY, size_t NX>
inline const size_t Matrix<M, NY, NX>::index(size_t y, size_t x)  const 
{
	return x + y * nx_;
}

template <typename M, size_t NY, size_t NX>
inline const size_t Matrix<M, NY, NX>::ind(size_t i) const 
{ 
	return i - 1;
}

template <typename M, size_t NY, size_t NX>
inline const size_t Matrix<M, NY, NX>::matrix_length() const 
{ 
	return ny_*nx_;
}

/*template <typename M, size_t NY, size_t NX>
inline M Matrix<M, NY, NX>::rowFirst(size_t index)
{ 
	return index*get_size();
}

template <typename M, size_t NY, size_t NX>
inline M Matrix<M, NY, NX>::rowLast(size_t index)
{ 
	return index*get_size() + get_size();
}*/

template <typename M, size_t NY, size_t NX>
inline const TypeMatrix Matrix<M, NY, NX>::get_matrix_type() const
{ 
	return type_mat_;
}

template <typename M, size_t NY, size_t NX>
inline const TypeAVX Matrix<M, NY, NX>::get_avx_type() const
{ 
	return type_avx_;
}

template <typename M, size_t NY, size_t NX>
inline bool Matrix<M, NY, NX>::empty()
{ 
	return (get_matrix_type() == TypeMatrix::EMPTY);
}