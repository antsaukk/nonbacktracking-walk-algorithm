#pragma once

#include "matrix.h"

#include <numeric>

using namespace std;

template <size_t N>
struct SizeHandler {
	SizeHandler() : 
	nx_(N), 
	ny_(N), 
	padding_value_(8),
	nny_(0) 
	{
		pad();
	}

	inline void pad()
	{
		nny_ = (ny_ + padding_value_ - 1) / padding_value_;
	}

	inline size_t vectorized_size() { return nny_*nx_; }

private:
	size_t 				 	 nx_;
	size_t 				 	 ny_;
	constexpr int padding_value_;
	size_t 					nny_;			
};

template <typename T,
		  size_t N>
class NBTW_Algorithm {
public:
	explicit NBTW_Algorithm(size_t asize, 
							size_t nbt_walks) : 
	adjacence_size_(asize), 
	nbt_walks_(nbt_walks) 
	{
		if (adjacence_size_ > N) throw invalid_argument("Sizes must be equal.");
	}

	~NBTW_Algorithm() {}

	inline size_t get_size() const 	 	{ return adjacence_size_; }

	inline size_t get_nbt_walks() const { return nbt_walks_; }
private:
	size_t 			adjacence_size_;
	size_t 			     nbt_walks_;
	Matrix<T, N> 			  nbtw_;
	SizeHandler<N>    size_handler_;
};


template <typename T, size_t N>
void delta_matrix(const Matrix<T, N> matrix);

template <typename T, size_t N>
void adjacency_matrix(vector<T>& nodes);