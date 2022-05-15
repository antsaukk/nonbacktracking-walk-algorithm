#include "nbtw_algorithm.h"

template <typename T, size_t N>
void NBTW<T, N>::run()
{	
	size_t walks = get_nbt_walks();

	if (walks == 0) {
		//do something
		ZerothOrderNBTW();
	} else if (walks == 1) {
		//do something
		FirstOrderNBTW();
	} else if (walks == 2) {
		// do something
		SecondOrderNBTW();
	} else {
		// 
		HigherOrderNBTW();
	}
}

// all method fill up nbtw_ 
template <typename T, size_t N>
void NBTW<T, N>::ZerothOrderNBTW()
{	
	
}

template <typename T, size_t N>
void NBTW<T, N>::FirstOrderNBTW()
{	
	
}

template <typename T, size_t N>
void NBTW<T, N>::SecondOrderNBTW()
{	
	
}

template <typename T, size_t N>
void NBTW<T, N>::HigherOrderNBTW()
{	
	
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

