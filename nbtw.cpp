
#include "profile.h" 
#include "test_runner.h"
#include "nbtw.h"

#include "nbtw_tests.cpp"
#include "matrix_tests.cpp"

int main() {
	TestRunner tr; 
	RUN_TEST(tr, test_mat_mul);
	RUN_TEST(tr, test_mat_mul1);
	RUN_TEST(tr, test_exp2); 
	RUN_TEST(tr, test_exp2_1); 
	RUN_TEST(tr, test_mat_sum);
	RUN_TEST(tr, test_mat_sum1);
	return 0;
}