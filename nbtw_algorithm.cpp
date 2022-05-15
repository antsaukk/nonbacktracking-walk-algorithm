#include "nbtw_algorithm.h"

template <typename T, size_t N>
void delta_matrix(const Matrix<T, N> matrix)  {
	assert(!matrix.empty());

	/*delta.resize(get_size());
	for(size_t i = 0; i < size_; i++) {
		delta[i] = A.sum_row(A.rowFirst(i), A.rowLast(i));
	}*/
}

/*template <typename T, size_t N>
void NBTW_Algorithm<T, N>::adjacency_matrix(vector<T>& nodes) {
	assert(!A.empty());
	if (A.get_type() != TypeMatrix::adjacency) {
		A.clear();
		A.am(nodes);
	}
}

template <typename T, size_t N>
void NBTW_Algorithm<T, N>::pA_2() {
	assert(!A.empty());
	assert(A.get_type() == TypeMatrix::adjacency);
	assert(!A2.empty());
	if (A2.get_type() != TypeMatrix::mexp2) {
		A2.clear();
		A2.exp2(A);
	}
}


template <typename T, size_t N>
const Matrix<T, N>& NBTW_Algorithm<T, N>::getp2_A() {
	pA_2();
	return A2;
}

template <typename T, size_t N>
const Matrix<T, N>& NBTW_Algorithm<T, N>::get_A() {
	assert(!A.empty());
	return A;
}

template <typename T, size_t N>
void NBTW_Algorithm<T, N>::nbtw_naive(size_t n, size_t k) {
	Matrix<T, N> At = get_A();
	Matrix<T, N> p1 = getp2_A();

	delta_matrix();
}*/