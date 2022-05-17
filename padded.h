#ifndef PADDED_H
#define PADDED_H

#include "vectorization.h"

#include <memory>

struct PaddedAndVectorized {
public:
	PaddedAndVectorized(size_t ny, size_t nx) :
	ny_(ny),
	nx_(nx)
	{}

	std::unique_ptr<float4_t > AllocateFloat4(size_t bytes)
	{
		return std::make_unique<float4_alloc(bytes)>;
	}

	std::unique_ptr<float8_t > AllocateFloat8(size_t bytes)
	{
		return std::make_unique<float8_alloc(bytes)>;
	}

	std::unique_ptr<double4_t > AllocateFloat8(size_t bytes)
	{
		return std::make_unique<double4_alloc(bytes)>;
	}

	std::unique_ptr<int8_vt> AllocateInt8(size_t bytes)
	{
		return std::make_unique<int8_vt_alloc(bytes)>;
	}

private:
	size_t ny_;
	size_t nx_;
	size_t nyy_;
	size_t nxx_;

	// std_unique_ptr
	std::unique_ptr<float4_t>  vectorized_ps4;
	std::unique_ptr<float8_t>  vectorized_ps8;
	std::unique_ptr<double4_t> vectorized_pd4;
	std::unique_ptr<int8_vt>   vectorized_pi8;
};

#endif