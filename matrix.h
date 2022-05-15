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
	}

	//copy constructor
	Matrix(const Matrix<M, N>& mat) : 
	size_(mat.get_size()),
	matrix_(new M[mat.get_size() * mat.get_size()]),
	unity_(1u), 
	type_(mat.get_type())
	{
		memcpy(matrix_, mat.data(), sizeof(M) * mat.get_size() * mat.get_size());
	}

	//copy assignment
	void operator=(const Matrix<M, N>& mat)
	{	
		size_   = mat.size_;
		unity_  = mat.unity_;
		type_   = mat.type_;
		matrix_ = new M[mat.get_size() * mat.get_size()];
		memcpy(matrix_, mat.data(), sizeof(M) * mat.get_size() * mat.get_size());
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
	}

	//move assigment
	void operator=(Matrix<M, N>&& mat)
	{
		delete[] matrix_;
		size_   = mat.size_;
		matrix_ = mat.matrix_; 
		unity_ 	= mat.unity_;
		type_ 	= mat.type;
	}

	//destructor
	~Matrix()
	{ 
		kill(); 
	}

	void allocate(size_t n);

	void clear();

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
		assert(!empty());
		delete[] matrix_; 
	}
};

