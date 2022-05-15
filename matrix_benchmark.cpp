#include <algorithm>

void benchmark_copy_constructor() 
{
	size_t ny = 9000;
	size_t nx = 9000;
	vector<uint64_t> v1(ny*nx);
	fill(v1.begin(), v1.end(), 1);

	Matrix<uint64_t, 9000, 9000> mx1;
	mx1.fill(v1.data(), v1.size());

	LOG_DURATION("Copy constructor running time: ")
	{
		Matrix<uint64_t, 9000, 9000> mx2 = mx1;
	}
}

void benchmark_move_constructor() 
{
	size_t ny = 9000;
	size_t nx = 9000;
	vector<uint64_t> v1(ny*nx);
	fill(v1.begin(), v1.end(), 1);

	Matrix<uint64_t, 9000, 9000> mx1;
	mx1.fill(v1.data(), v1.size());

	LOG_DURATION("Move constructor running time: ")
	{
		Matrix<uint64_t, 9000, 9000> mx2 = move(mx1);
	}
}

void benchmark_copy_assignment() 
{
	size_t ny = 9000;
	size_t nx = 9000;
	vector<uint64_t> v1(ny*nx);
	fill(v1.begin(), v1.end(), 1);

	Matrix<uint64_t, 9000, 9000> mx1;
	mx1.fill(v1.data(), v1.size());

	Matrix<uint64_t, 9000, 9000> mx2;

	LOG_DURATION("Copy assignment running time: ")
	{
		mx2 = mx1;
	}
}

void benchmark_move_assignment() 
{
	size_t ny = 9000;
	size_t nx = 9000;
	vector<uint64_t> v1(ny*nx);
	fill(v1.begin(), v1.end(), 1);

	Matrix<uint64_t, 9000, 9000> mx1;
	mx1.fill(v1.data(), v1.size());

	Matrix<uint64_t, 9000, 9000> mx2;

	LOG_DURATION("Move assignment running time: ")
	{
		mx2 = move(mx1);
	}
}