#include <x86intrin.h>

#include "util.h"
#include "matrix_ops.h"
#include "vectorization.h"

template <typename M, size_t NY, size_t NX>
void matmul_naive(Matrix<M, NY, NX>& result,
					const Matrix<M, NY, NX>& mx1,
					const Matrix<M, NY, NX>& mx2)
{
	assert(mx1.get_ny() == mx2.get_ny());
	assert(mx1.get_nx() == mx2.get_nx());
	//assert(result.get_ny() == mx2.get_nx()); more asserts

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

template <typename M, size_t NY, size_t NX>
void sum(Matrix<M, NY, NX>& result,
		const Matrix<M, NY, NX>& mx1,
		const Matrix<M, NY, NX>& mx2) 
{

	assert(mx1.get_ny() == mx2.get_ny());
	assert(mx1.get_nx() == mx2.get_nx());
	//assert(result.get_ny() == mx2.get_nx()); more asserts

	#pragma omp parallel for schedule(static, 1)
	for(size_t y = 0; y < get_size(); y++) {
		for(size_t x = 0; x < get_size(); x++) {
			auto val = mx1.getv(y, x) + mx2.getv(y, x);
			set_v(y, x, val);
		}
	}

}

template <typename M, size_t NY, size_t NX>
void matmul_optimized(Matrix<M, NY, NX>& result,
						const Matrix<M, NY, NX>& mx1,
						const Matrix<M, NY, NX>& mx2)
{
	
}

template <typename M, size_t NY, size_t NX>
void delta_matrix(constMatrix<M, NY, NX>& matrix) 
{

	/*delta.resize(get_size());
	for(size_t i = 0; i < size_; i++) {
		delta[i] = A.sum_row(A.rowFirst(i), A.rowLast(i));
	}*/
}

template <typename M, size_t NY, size_t NX>
void adjacency_matrix(vector<T>& nodes) {}