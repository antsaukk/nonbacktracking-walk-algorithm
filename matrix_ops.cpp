#include "matrix_ops.h"

template <typename M, size_t N>
void matmul_naive(Matrix<M, N>& result, const Matrix<M, N>& mx1, const Matrix<M,N>& mx2) {
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
void sum(Matrix<M, N>& result, const Matrix<M, N>& mx1, const Matrix<M,N>& mx2) {
	assert(!empty());
	#pragma omp parallel for schedule(static, 1)
	for(size_t y = 0; y < get_size(); y++) {
		for(size_t x = 0; x < get_size(); x++) {
			auto val = mx1.getv(y, x) + mx2.getv(y, x);
			set_v(y, x, val);
		}
	}

}

template <typename M, size_t N>
void matmul_optimized(Matrix<M, N>& result, const Matrix<M, N>& mx1, const Matrix<M,N>& mx2) {
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

template <typename T, size_t N>
void delta_matrix(const Matrix<T, N>& matrix)  {
	assert(!matrix.empty());

	/*delta.resize(get_size());
	for(size_t i = 0; i < size_; i++) {
		delta[i] = A.sum_row(A.rowFirst(i), A.rowLast(i));
	}*/
}

template <typename T, size_t N>
void adjacency_matrix(vector<T>& nodes) {}