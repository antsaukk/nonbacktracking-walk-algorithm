#ifndef PADDER_H
#define PADDER_H

#include "vectorization.h"

#include <memory>

template <typename T, typename NY, typename NX>
struct Padder {
public:
	Padder() :
	ny_(NY),
	nx_(NX),
	nyy_(0u),
	nxx_(0u)
	{}

	inline void pad_column()
	{
		nyy_ = (ny_ + padding_value_ - 1) / padding_value_;
	}

	inline void pad_row()
	{
		nxx_ = (nx_ + padding_value_ - 1) / padding_value_;
	}

	inline size_t column_vectorized_size() 		 { return nyy_*nx_; }

	inline size_t row_vectorized_size() 		 { return nyy_*nx_; }

	inline size_t column_length() const   		 { return ny_; }

	inline size_t row_length() const 			 { return nx_; }

	inline size_t pvertical_axis_length() const  { return nyy_; }

	inline std::unique_ptr<T, FreeAligned<T>> AllocateVectorized(size_t num_elements)
	{
		return aligned_malloc<T>(num_elements);
	}

private:
	size_t ny_;
	size_t nx_;
	size_t nyy_;
	size_t nxx_;
	static const int padding_value_ = 8; // this is not generalized

	std::unique_ptr<T, FreeAligned<T>>   vectorized_p;
};

#endif