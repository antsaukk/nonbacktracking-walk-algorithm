#include "profile.h" 
#include "test_runner.h"

//#include "nbtw_algorithm.h"
#include "matrix.h"

//#include "matrix.cpp"

#include "matrix_tests.cpp"
#include "matrix_benchmark.cpp"
//#include "nbtw_tests.cpp"

void matrix_tests(TestRunner tr) {
	RUN_TEST(tr, test_constructor);
	RUN_TEST(tr, test_constructor1);
	RUN_TEST(tr, test_constructor2);
	RUN_TEST(tr, test_constructor3);

	RUN_TEST(tr, test_copy_constructor);
	RUN_TEST(tr, test_copy_constructor1);
	RUN_TEST(tr, test_copy_constructor2);
	RUN_TEST(tr, test_copy_constructor3);

	RUN_TEST(tr, test_copy_assignment);
	RUN_TEST(tr, test_copy_assignment1);
	RUN_TEST(tr, test_copy_assignment2);
	RUN_TEST(tr, test_copy_assignment3);

	RUN_TEST(tr, test_move_constructor);
	RUN_TEST(tr, test_move_constructor1);
	RUN_TEST(tr, test_move_constructor3);
	RUN_TEST(tr, test_move_constructor4);

	RUN_TEST(tr, test_move_assignment);
	RUN_TEST(tr, test_move_assignment1);
	RUN_TEST(tr, test_move_assignment2);
	RUN_TEST(tr, test_move_assignment3);

	/*RUN_TEST(tr, test_mat_mul);
	RUN_TEST(tr, test_mat_mul1);
	RUN_TEST(tr, test_exp2); 
	RUN_TEST(tr, test_exp2_1); 
	RUN_TEST(tr, test_mat_sum);
	RUN_TEST(tr, test_mat_sum1);*/
}

void matrix_benchmarks()
{
	benchmark_copy_constructor();
	benchmark_move_constructor();
	benchmark_copy_assignment();
	benchmark_move_assignment();
}

/*void spectral_tests(TestRunner tr) {
	RUN_TEST(tr, test_delta);
	RUN_TEST(tr, test_delta1);
	RUN_TEST(tr, test_exp);
	RUN_TEST(tr, test_exp1);
	RUN_TEST(tr, test_nbtw);
}*/

int main() {
	TestRunner tr;
	matrix_tests(tr);
	matrix_benchmarks();
	//algorithm_tests(tr);
	return 0;
}