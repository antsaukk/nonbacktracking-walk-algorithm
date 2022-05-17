#include "vectorization.h"

#include <iostream>

int main() {
	std::unique_ptr<int8_vt, FreeAligned<int8_vt>> vectorized0 = aligned_malloc<int8_vt>(10 * 10);

	for (size_t i = 0; i < 10*10; i++) {
		for (size_t j = 0; j < 8; j++) {
			vectorized0.get()[i][j] = i*j;
		}
	}

	for (size_t i = 0; i < 10*10; i++) {
		for (size_t j = 0; j < 8; j++) {
			std::cout << vectorized0.get()[i][j] << " ";
		}
		std::cout << "\n";
	}

	std::unique_ptr<float8_t, FreeAligned<float8_t>> vectorized1 = aligned_malloc<float8_t>(10 * 10);

	std::unique_ptr<double4_t, FreeAligned<double4_t>> vectorized2 = aligned_malloc<double4_t>(10 * 10);
	
	return 0;
}