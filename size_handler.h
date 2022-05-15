#pragma once

using namespace std;

template <size_t N>
struct SizeHandler {
	SizeHandler() : 
	nx_(N), 
	ny_(N), 
	padding_value_(8),
	nny_(0) 
	{
		pad();
	}

	inline void pad()
	{
		nny_ = (ny_ + padding_value_ - 1) / padding_value_;
	}

	inline size_t vectorized_size() 		     { return nny_*nx_; }

	inline size_t vertical_axis_length() const   { return ny_; }

	inline size_t pvertical_axis_length() const  { return nny_; }

	inline size_t horizontal_axis_length() const { return nx_; }

private:
	size_t 				 	    nx_;
	size_t 				 	    ny_;
	static const int padding_value_;
	size_t 					   nny_;		
};