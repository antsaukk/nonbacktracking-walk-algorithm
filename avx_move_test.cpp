#include "vectorization.h"
#include "profile.h"
#include <iostream>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

class Test {
public:
	Test() {
		vectorized = int8_vt_alloc(10 * 10);
		cout << "Def constructor called\n";
	}

	Test(const Test& t) {
		vectorized = int8_vt_alloc(10 * 10);
		memcpy(vectorized, t.vectorized, sizeof(Test) * 10 * 10);
		cout << "Copy constructor called\n";
	}

	friend void swap(Test& t1, Test& t2)
    {
        std::swap(t1.vectorized, t2.vectorized);
    }

	void operator=(Test& t) {
		swap(*this, t);
		cout << "Copy ass called\n";
	}

	Test(Test&& t) :
	vectorized(t.vectorized)
	{
		t.vectorized = nullptr;
		cout << "Move constructor called\n";
	}

	void operator=(Test&& t) {
		swap(vectorized, t.vectorized);
		cout << "Move ass called\n";
	}

	~Test() {
		free(vectorized);
	}

private:
	int8_vt *vectorized;
};

void test1(){
	int8_vt *vectorized = int8_vt_alloc(10 * 10);
	for (size_t i = 0; i < 10*10; i++) {
		for (size_t j = 0; j < 8; j++) {
			vectorized[i][j] = i*j;
		}
	}

	/*for (size_t i = 0; i < 10*10; i++) {
		for (size_t j = 0; j < 8; j++) {
			cout << vectorized[i][j];
		}
	}*/

	int8_vt *vectorized2 = int8_vt_alloc(10 * 10);

	vectorized2 		 = move(vectorized);
	//cout << vectorized2[0][0];
	//std::free(vectorized);
	std::free(vectorized2);
}

void test2() {
	int *vectorized = new int[10 * 10];
	for (size_t i = 0; i < 10*10; i++) {
		vectorized[i] = i;
	}

	/*for (size_t i = 0; i < 10*10; i++) {
		cout << vectorized[i];
	}*/

	int *vectorized2 = new int[10 * 10];

	vectorized2 		 = move(vectorized); 
	//cout << vectorized2[0][0];
	//delete [] vectorized;
	delete [] vectorized2;
}

void test3() {
	Test t1;
	Test t2;

	Test t3 = t1;

	Test t4 = move(t2);

	Test t5; 
	t5 = move(t1);
}

void test4() {
	Test t1;
	Test t2;

	t2 = t1;
}

int main() {
	test3();
	test4();
	return 0;
}