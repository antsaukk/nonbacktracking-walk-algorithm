#include <matrix.h>

void allocate(size_t n)
{
	matrix_ = new M[n * n];
	clear(); // ?
}

void clear() 
{
	for (size_t y = 0; y < get_size(); y++) {
		for (size_t x = 0; x < get_size(); x++) {
			set_v(y, x, 0);
		}
	}
}

inline void identity()
{
	for (size_t y = 0; y < get_size(); y++){
		set_v(y, y, 1);
	}
}

inline M sum_row(M start, M end)
{
	M sum = 0u;
	for(int i = start; i < end; i++) {
		sum += matrix_[i];
	}
	return sum;
}

inline const M* data() const
{
	return matrix_;
}

inline const M getv(const size_t y, const size_t x) const 
{  
	return matrix_[index(y, x)]; 
}

inline void set_v(size_t y, size_t x, M val)
{ 
	matrix_[index(y, x)] = val;
}

inline void add_v(size_t y, size_t x, M val)
{ 
	matrix_[index(y, x)] += val;
}

inline const size_t get_size() const 
{ 
	return size_;
}

inline const size_t index(size_t y, size_t x)  const 
{
	return x + y * get_size();
}

inline const size_t ind(size_t i) const 
{ 
	return i - 1;
}

inline const size_t matrix_length() const 
{ 
	return get_size()*get_size();
}

inline M rowFirst(size_t index)
{ 
	return index*get_size();
}

inline M rowLast(size_t index)
{ 
	return index*get_size() + get_size();
}

inline const TypeMatrix get_type() const
{ 
	return type_;
}

inline bool empty()
{ 
	return (size_ == 0);
}