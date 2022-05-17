//https://stackoverflow.com/questions/29410064/aligned-dynamic-array-and-smart-pointer
#ifndef VECTORIZATION_H
#define VECTORIZATION_H

#include <cstdlib>
#include <memory>

typedef float float4_t __attribute__((vector_size(16)));
typedef float float8_t __attribute__((vector_size(32)));
typedef double double4_t __attribute__((vector_size(32)));
typedef int int8_vt __attribute__((vector_size(32)));

constexpr float4_t float4_0 = {0, 0, 0, 0};
constexpr float8_t float8_0 = {0, 0, 0, 0, 0, 0, 0, 0};
constexpr double4_t double4_0 = {0, 0, 0, 0};
constexpr int8_vt int8_0 = {0, 0, 0, 0, 0, 0, 0, 0};

template<typename T>
struct FreeAligned
{
    void operator()(T * data) const
    {
        free(data);
    }
};

template<typename T>
inline std::unique_ptr<T, FreeAligned<T>> aligned_malloc(std::size_t n) { //std::size_t alignment = 32
    T *ret = nullptr;
    if (posix_memalign((void **)&ret, 32, sizeof(T) * n)) {
        return nullptr;
    }
    return std::unique_ptr<T, FreeAligned<T>>{ret};
}

/*inline void *aligned_malloc(std::size_t bytes) {
    void *ret = nullptr;
    if (posix_memalign(&ret, 32, bytes)) {
        return nullptr;
    }
    return ret;
}

/*inline float4_t *float4_alloc(std::size_t n) {
    return static_cast<float4_t *>(aligned_malloc(sizeof(float4_t) * n));
}

inline float8_t *float8_alloc(std::size_t n) {
    return static_cast<float8_t *>(aligned_malloc(sizeof(float8_t) * n));
}

inline double4_t *double4_alloc(std::size_t n) {
    return static_cast<double4_t *>(aligned_malloc(sizeof(double4_t) * n));
}

inline int8_vt *int8_vt_alloc(std::size_t n) {
    return static_cast<int8_vt *>(aligned_malloc(sizeof(int8_vt) * n));
}*/

#endif