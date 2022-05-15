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

// all methods fill up nbtw_ 
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

