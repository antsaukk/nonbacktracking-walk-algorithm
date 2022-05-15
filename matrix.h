#pragma once

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
	explicit Matrix() : 
	size_(N),
	matrix_(nullptr),
	unity_(1u),
	type_(TypeMatrix::EMPTY) 
	{
		allocate(size_);
	}

	Matrix(const Matrix<M, N>& mat) : 
	size_(mat.get_size()),
	matrix_(new M[mat.get_size() * mat.get_size()]),
	unity_(1u), 
	type_(mat.get_type())
	{
		memcpy(matrix_, mat.data(), sizeof(M) * mat.get_size() * mat.get_size());
	}

	//оператор присваивания 

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

	void operator=(Matrix<M, N>&& mat)
	{
		delete[] matrix_;
		size_   = mat.size_;
		matrix_ = mat_.matrix_; 
		unity_ 	= mat_.unity_;
		type_ 	= mat_.type;
	}

	~Matrix()
	{ 
		kill(); 
	}

	void allocate(size_t n)
	{
		matrix_ = new M[n * n];
		clear(); // ?
	}

	void clear() 
	{
		for (size_t y = 0; y < get_size(); y++) {
			for (size_t x = 0; x < get_size(); x++) {
				set_v(y, x, 0);
			}
		}
	}

	/*void am(const std::vector<M>& nodes) {
		assert(!empty());
		set_type(TypeMatrix::adjacency);
		for (size_t i = 0; i < nodes.size(); i+=2) {
			M y = ind(nodes[i]);
			M x = ind(nodes[i+1]);
			set_v(y, x, unity_); 
			set_v(x, y, unity_);
		}
	}*/

	inline void identity()
	{
		for (size_t y = 0; y < get_size(); y++){
			set_v(y, y, 1);
		}
	}

	inline M sum_row(M start, M end)
	{
		M sum = 0u;
		for(int i = start; i < end; i++) {
			sum += matrix_[i];
		}
		return sum;
	}

	inline inline const M* data() const
	{
		return matrix_;
	}

	inline const M getv(const size_t y, const size_t x) const {  return matrix_[index(y, x)]; }

	inline void set_v(size_t y, size_t x, M val)
	{ 
		matrix_[index(y, x)] = val;
	}

	inline void add_v(size_t y, size_t x, M val)
	{ 
		matrix_[index(y, x)] += val;
	}

	inline const size_t get_size() 			       const { return size_; }
	inline const size_t index(size_t y, size_t x)  const { return x + y * get_size(); }
	inline const size_t ind(size_t i) 			   const { return i - 1; }
	inline const size_t matrix_length() 		   const { return get_size()*get_size(); }

	inline M rowFirst(size_t index) 				     { return index*get_size(); }
	inline M rowLast(size_t index) 					     { return index*get_size() + get_size(); }

	inline const TypeMatrix get_type() 			   const { return type_; }

	inline bool empty() { return (size_ == 0); }

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

template <typename M, size_t N>
void exp2(const Matrix<M, N>& mx);

template <typename M, size_t N>
void matmul(const Matrix<M, N>& mx1, const Matrix<M,N>& mx2);

template <typename M, size_t N>
void sum(const Matrix<M, N>& mx1, const Matrix<M,N>& mx2);