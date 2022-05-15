#include "matrix.h"

template <typename M, size_t N>
void exp2(const Matrix<M,N>& mx) {
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
void matmul(const Matrix<M,N>& mx1, const Matrix<M,N>& mx2) {
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
void sum(const Matrix<M,N>& mx1, const Matrix<M,N>& mx2) {
	assert(!empty());
	#pragma omp parallel for schedule(static, 1)
	for(size_t y = 0; y < get_size(); y++) {
		for(size_t x = 0; x < get_size(); x++) {
			auto val = mx1.getv(y, x) + mx2.getv(y, x);
			set_v(y, x, val);
		}
	}

}