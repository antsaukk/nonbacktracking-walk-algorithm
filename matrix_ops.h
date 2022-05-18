#pragma once 

// store templates in one file

#include "matrix.h"

template <typename M, size_t NY, size_t NX>
void matmul_naive(Matrix<M, N>& result, const Matrix<M, N>& mx1, const Matrix<M,N>& mx2);

template <typename M, size_t NY, size_t NX>
void matmul_optimized(Matrix<M, N>& result, const Matrix<M, N>& mx1, const Matrix<M,N>& mx2);

template <typename M, size_t NY, size_t NX>
void sum(Matrix<M, N>& result, const Matrix<M, N>& mx1, const Matrix<M,N>& mx2);

template <typename M, size_t NY, size_t NX>
void delta_matrix(const Matrix<T, N>& matrix);

template <typename M, size_t NY, size_t NX>
void adjacency_matrix(vector<T>& nodes);