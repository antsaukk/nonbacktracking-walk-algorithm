#pragma once

#include <x86intrin.h>
#include <algorithm>
#include <tuple>

typedef std::vector<std::tuple<size_t, size_t, size_t>> Z_order_index_sequence;

struct ZOrder { 
	ZOrder(size_t n) : n_(n)
	{
		z_curve_.resize(compute_sequence_size(n));
	}

	void generate_Zorder() {

		#pragma omp parallel for schedule(static, 1)
	 	for (size_t ia = 0; ia < get_size(); ia++) {
	 		for (size_t ja = ia; ja < get_size(); ja++) { 
	 			size_t ija    = generate_Z_Key(ia, ja);
	 			size_t ind 	  = sequence_index(ia, ja);
	 			z_curve_[ind] = std::make_tuple(ija, ia, ja);
	 		}
	 	}
		
		std::sort(z_curve_.begin(), z_curve_.end());
	}

	inline size_t compute_sequence_size(size_t n)
	{ 
		return n * (n + 1) / 2;
	}

	inline size_t get_size() const
	{ 
		return n_; 
	}

	inline size_t sequence_index(size_t index_i, size_t index_j)
	{
		return index_j + index_i * get_size() - index_i * (index_i + 1) / 2;
	}

	inline size_t generate_Z_Key(size_t index_i, size_t index_j) 
	{
		return _pdep_u32(index_i, maskA) | _pdep_u32(index_j, maskB); //_pdep32 change
	}

	inline Z_order_index_sequence get_Z_curve_() const
	{
		return z_curve_;
	}

private:
	size_t n_;
	Z_order_index_sequence z_curve_;
	const int maskA = 0x55555555; 
	const int maskB = 0xAAAAAAAA;
};