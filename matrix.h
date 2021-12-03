#pragma once

#include <cassert>
#include <stdexcept>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <omp.h>

using namespace std;

enum TypeMatrix { empty, adjacency, mexp2, pA };

template <typename M, size_t N>
class Matrix {
public: 
	explicit Matrix() : 
	size_(N),
	matrix_(nullptr),
	unity_(1u),
	type_(TypeMatrix::empty) {
		allocate(size_);
	}

	Matrix(const Matrix<M, N>& mat) : 
	size_(mat.get_size()),
	matrix_(new M[mat.get_size() * mat.get_size()]),
	unity_(1u), 
	type_(mat.get_type()) {
		memcpy(matrix_, mat.data(), sizeof(M) * mat.get_size() * mat.get_size());
	}

	~Matrix() { kill(); }

	void clear(){
		for (size_t y = 0; y < get_size(); y++)
			for (size_t x = 0; x < get_size(); x++)
				set_v(y, x, 0);
	}

	void allocate(size_t n) {
		matrix_ = new M[n * n];
		clear();
	}

	void am(const std::vector<M>& nodes) {
		assert(!empty());
		set_type(TypeMatrix::adjacency);
		for (size_t i = 0; i < nodes.size(); i+=2) {
			M y = ind(nodes[i]);
			M x = ind(nodes[i+1]);
			set_v(y, x, unity_); 
			set_v(x, y, unity_);
		}
	}

	void identity() {
		for (size_t y = 0; y < get_size(); y++)
			set_v(y, y, 1);
	}

	M sum_row(M start, M end) {
		M sum = 0u;
		for(int i = start; i < end; i++) {
			sum += matrix_[i];
		}
		return sum;
	}

	void exp2(const Matrix<M,N>& mx);
	void matmul(const Matrix<M,N>& mx1, const Matrix<M,N>& mx2);
	void sum(const Matrix<M,N>& mx1,const Matrix<M,N>& mx2);

	const M* data() const { return matrix_; } 
	const M getv(const size_t y, const size_t x) const { return matrix_[index(y, x)]; }

	void set_v(size_t y, size_t x, M val) { 
		matrix_[index(y, x)] = val;
	}

	void add_v(size_t y, size_t x, M val) { 
		matrix_[index(y, x)] += val;
	}

	const size_t get_size() const { return size_; }
	const size_t index(size_t y, size_t x) const { return x + y * get_size(); }
	const size_t ind(size_t i) const { return i-1; }
	const size_t matrix_length() const { return get_size()*get_size(); }

	M rowFirst(size_t index) { return index*get_size(); }
	M rowLast(size_t index) { return index*get_size() + get_size(); }

	const TypeMatrix get_type() const { return type_; }

	void set_type(TypeMatrix t) {
		type_ = t;
	}

	bool empty() { return (size_ == 0); }

	void kill() {
		assert(!empty());
		delete[] matrix_; 
	}

private:
	size_t size_; 
	M* matrix_;
	M unity_;
	TypeMatrix type_;
};

template <typename M, size_t N>
void Matrix<M, N>::exp2(const Matrix<M,N>& mx) {
	assert(!empty());
	set_type(TypeMatrix::mexp2);
	#pragma omp parallel for schedule(dynamic, 1)
	for(size_t y = 0; y < get_size(); y++) {
		for(size_t x = 0; x < get_size(); x++) {
			for(size_t k = 0; k < get_size(); k++) {
				auto val = mx.getv(y, k) * mx.getv(k, x);
				add_v(y, x, val);
			}
		}
	}
}

template <typename M, size_t N>
void Matrix<M, N>::matmul(const Matrix<M,N>& mx1, const Matrix<M,N>& mx2) {
	assert(!empty());
	#pragma omp parallel for schedule(dynamic, 1)
	for(size_t y = 0; y < get_size(); y++) {
		for(size_t x = 0; x < get_size(); x++) {
			for(size_t k = 0; k < get_size(); k++) {
				auto val = mx1.getv(y, k) * mx2.getv(k, x);
				add_v(y, x, val);
			}
		}
	}
}

template <typename M, size_t N>
void Matrix<M, N>::sum(const Matrix<M,N>& mx1, const Matrix<M,N>& mx2) {
	assert(!empty());
	#pragma omp parallel for schedule(static, 1)
	for(size_t y = 0; y < get_size(); y++) {
		for(size_t x = 0; x < get_size(); x++) {
			auto val = mx1.getv(y, x) + mx2.getv(y, x);
			set_v(y, x, val);
		}
	}

}