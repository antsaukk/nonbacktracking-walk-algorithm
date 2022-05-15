//#include "matrix.h"

template <typename M, size_t NY, size_t NX>
void Matrix<M, NY, NX>::allocate(size_t ny, size_t nx)
{
	matrix_ = new M[ny * nx];
	clear(); // ?
}

template <typename M, size_t NY, size_t NX>
void Matrix<M, NY, NX>::clear() 
{
	for (size_t y = 0; y < ny_; y++) {
		for (size_t x = 0; x < nx_; x++) {
			set_v(y, x, 0);
		}
	}
}

template <typename M, size_t NY, size_t NX>
void Matrix<M, NY, NX>::fill(const M* data, size_t dsize) 
{
	assert(dsize == matrix_length());
	for (size_t y = 0; y < ny_; y++) {
		for (size_t x = 0; x < nx_; x++) {
			M val = data[index(y, x)]; 
			set_v(y, x, val);
		}
	}
	type_ = TypeMatrix::NONEMPTY;
}

/*template <typename M, size_t NY, size_t NX>
inline void Matrix<M, NY, NX>::identity()
{
	for (size_t y = 0; y < get_size(); y++){
		set_v(y, y, 1);
	}
}*/

template <typename M, size_t NY, size_t NX>
inline M Matrix<M, NY, NX>::sum_row(M start, M end)
{
	M sum = 0u;
	for(int i = start; i < end; i++) {
		sum += matrix_[i];
	}
	return sum;
}

template <typename M, size_t NY, size_t NX>
inline const M* Matrix<M, NY, NX>::data() const
{
	return matrix_;
}

template <typename M, size_t NY, size_t NX>
inline const M Matrix<M, NY, NX>::getv(const size_t y, const size_t x) const 
{  
	return matrix_[index(y, x)]; 
}

template <typename M, size_t NY, size_t NX>
inline void Matrix<M, NY, NX>::set_v(size_t y, size_t x, M val)
{ 
	matrix_[index(y, x)] = val;
}

template <typename M, size_t NY, size_t NX>
inline void Matrix<M, NY, NX>::add_v(size_t y, size_t x, M val)
{ 
	matrix_[index(y, x)] += val;
}

template <typename M, size_t NY, size_t NX>
inline const size_t Matrix<M, NY, NX>::get_ny() const 
{ 
	return ny_;
}

template <typename M, size_t NY, size_t NX>
inline const size_t Matrix<M, NY, NX>::get_nx() const 
{ 
	return nx_;
}

template <typename M, size_t NY, size_t NX>
inline const size_t Matrix<M, NY, NX>::index(size_t y, size_t x)  const 
{
	return x + y * nx_;
}

template <typename M, size_t NY, size_t NX>
inline const size_t Matrix<M, NY, NX>::ind(size_t i) const 
{ 
	return i - 1;
}

template <typename M, size_t NY, size_t NX>
inline const size_t Matrix<M, NY, NX>::matrix_length() const 
{ 
	return ny_*nx_;
}

/*template <typename M, size_t NY, size_t NX>
inline M Matrix<M, NY, NX>::rowFirst(size_t index)
{ 
	return index*get_size();
}

template <typename M, size_t NY, size_t NX>
inline M Matrix<M, NY, NX>::rowLast(size_t index)
{ 
	return index*get_size() + get_size();
}*/

template <typename M, size_t NY, size_t NX>
inline const TypeMatrix Matrix<M, NY, NX>::get_type() const
{ 
	return type_;
}

template <typename M, size_t NY, size_t NX>
inline bool Matrix<M, NY, NX>::empty()
{ 
	return (get_type() == TypeMatrix::EMPTY);
}