#pragma once

#include "matrix.h"
#include "size_handler.h"
#include "zorder.h"

#include <assert.h>
#include <numeric>

using namespace std;

template <typename T, size_t N>
class NBTW {
public:
	explicit NBTW(size_t asize, 
				  size_t nbt_walks) : 
	adjacence_size_(asize), 
	nbt_walks_(nbt_walks) 
	{
		if (adjacence_size_ > N) throw invalid_argument("Sizes must be equal.");
	}

	~NBTW() {}

	void run();

	void ZerothOrderNBTW();

	void FirstOrderNBTW();

	void SecondOrderNBTW();

	void HigherOrderNBTW();

	inline size_t get_size() const 	 	{ return adjacence_size_; }

	inline size_t get_nbt_walks() const { return nbt_walks_; }
private:
	size_t 			adjacence_size_;
	size_t 			     nbt_walks_;
	Matrix<T, N> 			  nbtw_;
	SizeHandler<N>    size_handler_;
};


template <typename T, size_t N>
void delta_matrix(const Matrix<T, N>& matrix);

template <typename T, size_t N>
void adjacency_matrix(vector<T>& nodes);