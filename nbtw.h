#include <vector> 
#include <iostream>
#include <algorithm>
#include <cassert>
#include <omp.h>

using namespace std;

template <typename M>
class Matrix {
public: 
	explicit Matrix() {}
	~Matrix() { kill(); }

	void set_to_zero(){
		for (size_t i = 0; i < get_size()*get_size(); i++)
			matrix[i] = 0;
	}

	void allocate(size_t n) {
		size_ = n;
		matrix = new M[n * n];
		set_to_zero();
	}

	void am(vector<M>& nodes) {
		assert(!empty());
		for (size_t i = 0; i < nodes.size(); i+=2) {
			matrix[index(ind(nodes[i]), ind(nodes[i+1]))] = unity;
			matrix[index(ind(nodes[i+1]), ind(nodes[i]))] = unity;
		}
	}

	void exp2(M* mx);
	void matmul(M* mx1, M* mx2);
	void sum(M* mx1, M* mx2);

	M* get() { return matrix; }

	size_t get_size() { return size_; }
	size_t index(size_t y, size_t x) { return x + y * get_size(); }
	size_t ind(size_t i) { return i-1; }

	bool empty() { return (size_ == 0); }

	void kill() {
		assert(!empty());
		delete[] matrix; 
	}

private: 
	size_t size_ = 0;; 
	M* matrix = nullptr;
	M unity = 1;
};

template <typename M>
void Matrix<M>::exp2(M* mx) {
	assert(!empty());

	//#pragma omp parallel for schedule(dynamic, 1)
	for(size_t y = 0; y < get_size(); y++) {
		for(size_t x = 0; x < get_size(); x++) {
			for(size_t k = 0; k < get_size(); k++) {
				matrix[index(y, x)] += mx[index(y, k)] * mx[index(k, x)];
			}
		}
	}
}

template <typename M>
void Matrix<M>::matmul(M* mx1, M* mx2) {
	assert(!empty());

	//#pragma omp parallel for schedule(dynamic, 1)
	for(size_t y = 0; y < get_size(); y++) {
		for(size_t x = 0; x < get_size(); x++) {
			for(size_t k = 0; k < get_size(); k++) {
				matrix[index(y, x)] += mx1[index(y, k)] * mx2[index(k, x)];
			}
		}
	}
}

template <typename M>
void Matrix<M>::sum(M* mx1, M* mx2) {
	assert(!empty());

	for(size_t y = 0; y < get_size(); y++) {
		for(size_t x = 0; x < get_size(); x++) {
			matrix[index(y, x)] = mx1[index(y, x)] + mx2[index(y, x)];
		}
	}

}

template <typename T>
class SpectralGraph {
public:
	explicit SpectralGraph(size_t size) : 
	size_(size), 
	e_(size, 1) {}

	~SpectralGraph() {}

	T* nbtw_naive(size_t n, size_t k);

	void adjacency_matrix(vector<T>& nodes) {
		A.allocate(get_size());
		A.am(nodes);
	}

	void delta_matrix() {
		assert(A != nullptr);
		delta.resize(get_size());
		for(size_t i = 0; i < size_; i++) {
			delta[i] = accumulate(A.get() + i*get_size(), A.get() + i*get_size() + get_size());
		}
	}

	void p2_A() {
		assert(A != nullptr);
		A2.exp2(A);
	}

	size_t get_size() { return size_; }
private:
	size_t size_; 
	Matrix<T>* A = nullptr;
	Matrix<T>* A2 = nullptr;
	vector<size_t> e_;
	vector<T> delta;
	Matrix<T>* nbtw_ = nullptr;
};

/*template <typename T>
T* SpectralGraph<T>::nbtw_naive(size_t n, size_t k) {
	nbtw_ = new T[get_size() * get_size()];
	T* pA1 = A;
	T* pA2 = new T[get_size() * get_size()];

	pA2 = 


	return nbtw_;
}*/