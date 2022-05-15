#pragma once 

#include "matrix.h"

template <typename M, size_t N>
void matmul_naive(Matrix<M, N>& result, const Matrix<M, N>& mx1, const Matrix<M,N>& mx2);

template <typename M, size_t N>
void matmul_optimized(Matrix<M, N>& result, const Matrix<M, N>& mx1, const Matrix<M,N>& mx2);

template <typename M, size_t N>
void sum(Matrix<M, N>& result, const Matrix<M, N>& mx1, const Matrix<M,N>& mx2);

template <typename T, size_t N>
void delta_matrix(const Matrix<T, N>& matrix);

template <typename T, size_t N>
void adjacency_matrix(vector<T>& nodes);