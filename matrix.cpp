//#include "matrix.h"

template<typename M, size_t N>
void Matrix<M, N>::allocate(size_t n)
{
	matrix_ = new M[n * n];
	clear(); // ?
}

template<typename M, size_t N>
void Matrix<M, N>::clear() 
{
	for (size_t y = 0; y < get_size(); y++) {
		for (size_t x = 0; x < get_size(); x++) {
			set_v(y, x, 0);
		}
	}
}

template<typename M, size_t N>
inline void Matrix<M, N>::identity()
{
	for (size_t y = 0; y < get_size(); y++){
		set_v(y, y, 1);
	}
}

template<typename M, size_t N>
inline M Matrix<M, N>::sum_row(M start, M end)
{
	M sum = 0u;
	for(int i = start; i < end; i++) {
		sum += matrix_[i];
	}
	return sum;
}

template<typename M, size_t N>
inline const M* Matrix<M, N>::data() const
{
	return matrix_;
}

template<typename M, size_t N>
inline const M Matrix<M, N>::getv(const size_t y, const size_t x) const 
{  
	return matrix_[index(y, x)]; 
}

template<typename M, size_t N>
inline void Matrix<M, N>::set_v(size_t y, size_t x, M val)
{ 
	matrix_[index(y, x)] = val;
}

template<typename M, size_t N>
inline void Matrix<M, N>::add_v(size_t y, size_t x, M val)
{ 
	matrix_[index(y, x)] += val;
}

template<typename M, size_t N>
inline const size_t Matrix<M, N>::get_size() const 
{ 
	return size_;
}

template<typename M, size_t N>
inline const size_t Matrix<M, N>::index(size_t y, size_t x)  const 
{
	return x + y * get_size();
}

template<typename M, size_t N>
inline const size_t Matrix<M, N>::ind(size_t i) const 
{ 
	return i - 1;
}

template<typename M, size_t N>
inline const size_t Matrix<M, N>::matrix_length() const 
{ 
	return get_size()*get_size();
}

template<typename M, size_t N>
inline M Matrix<M, N>::rowFirst(size_t index)
{ 
	return index*get_size();
}

template<typename M, size_t N>
inline M Matrix<M, N>::rowLast(size_t index)
{ 
	return index*get_size() + get_size();
}

template<typename M, size_t N>
inline const TypeMatrix Matrix<M, N>::get_type() const
{ 
	return type_;
}

template<typename M, size_t N>
inline bool Matrix<M, N>::empty()
{ 
	return (size_ == 0);
}