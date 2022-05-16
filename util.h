#include <x86intrin.h>

enum TypeAVX { 
	INT4B,
	INT8B,
	FLOAT4B,
	FLOAT8B,
	FLOAT16B,
	DOUBLE4B,
	DOUBLE8B 
};

static inline int8_vt swap4(int8_vt x) { return _mm256_permute2f128_ps(x, x, 0b00000001); }

static inline int8_vt swap2(int8_vt x) { return _mm256_permute_ps(x, 0b01001110); }

static inline int8_vt swap1(int8_vt x) { return _mm256_permute_ps(x, 0b10110001); }