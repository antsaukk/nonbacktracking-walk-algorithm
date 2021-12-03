#pragma once

#include "matrix.h"

#include <numeric>

using namespace std;

template <typename T, size_t N>
class SpectralGraph {
public:
	explicit SpectralGraph(size_t size) : 
	size_(size), 
	e_(size, 1) {
		if (size_ > N) throw invalid_argument("Sizes must be equal.");
	}
	~SpectralGraph() {}

	void nbtw_naive(size_t n, size_t k);
	void adjacency_matrix(vector<T>& nodes);
	void delta_matrix();
	void pA_2();

	const Matrix<T, N>& getp2_A();
	const Matrix<T, N>& get_A();

	const vector<T>& get_delta() const { return delta; }

	size_t get_size() { return size_; }
private:
	size_t size_ = 0; 
	Matrix<T, N> A;
	Matrix<T, N> A2;
	vector<size_t> e_;
	vector<T> delta;
	Matrix<T, N> nbtw_;
};

template <typename T, size_t N>
void SpectralGraph<T, N>::delta_matrix()  {
	assert(!A.empty());
	delta.resize(get_size());
	for(size_t i = 0; i < size_; i++) {
		delta[i] = A.sum_row(A.rowFirst(i), A.rowLast(i));
	}
}

template <typename T, size_t N>
void SpectralGraph<T, N>::adjacency_matrix(vector<T>& nodes) {
	assert(!A.empty());
	if (A.get_type() != TypeMatrix::adjacency) {
		A.clear();
		A.am(nodes);
	}
}

template <typename T, size_t N>
void SpectralGraph<T, N>::pA_2() {
	assert(!A.empty());
	assert(A.get_type() == TypeMatrix::adjacency);
	assert(!A2.empty());
	if (A2.get_type() != TypeMatrix::mexp2) {
		A2.clear();
		A2.exp2(A);
	}
}


template <typename T, size_t N>
const Matrix<T, N>& SpectralGraph<T, N>::getp2_A() {
	pA_2();
	return A2;
}

template <typename T, size_t N>
const Matrix<T, N>& SpectralGraph<T, N>::get_A() {
	assert(!A.empty());
	return A;
}

template <typename T, size_t N>
void SpectralGraph<T, N>::nbtw_naive(size_t n, size_t k) {
	Matrix<T, N> At = get_A();
	Matrix<T, N> p1 = getp2_A();

	delta_matrix();
}