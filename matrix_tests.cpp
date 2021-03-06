void test_constructor() 
{
	vector<int> v1 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	Matrix<int, 3, 3> mx1;

	vector<int> r1; 
	copy(mx1.data(), mx1.data() + mx1.matrix_length(), back_inserter(r1));

	ASSERT_EQUAL(r1, v1);
	ASSERT_EQUAL(mx1.get_ny(), 3u);
	ASSERT_EQUAL(mx1.get_nx(), 3u);
	ASSERT_EQUAL(mx1.get_matrix_type(), TypeMatrix::EMPTY);
}

void test_constructor1() 
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	Matrix<int, 3, 3> mx1;
	mx1.fill(v1.data(), v1.size());

	vector<int> r1; 
	copy(mx1.data(), mx1.data() + mx1.matrix_length(), back_inserter(r1));

	ASSERT_EQUAL(r1, v1);
	ASSERT_EQUAL(mx1.get_ny(), 3u);
	ASSERT_EQUAL(mx1.get_nx(), 3u);
	ASSERT_EQUAL(mx1.get_matrix_type(), TypeMatrix::NONEMPTY);
}

void test_constructor2() 
{
	vector<int> v1 = {0, 0, 0, 0, 0, 0};
	Matrix<int, 3, 2> mx1;

	vector<int> r1; 
	copy(mx1.data(), mx1.data() + mx1.matrix_length(), back_inserter(r1));

	ASSERT_EQUAL(r1, v1);
	ASSERT_EQUAL(mx1.get_ny(), 3u);
	ASSERT_EQUAL(mx1.get_nx(), 2u);
	ASSERT_EQUAL(mx1.get_matrix_type(), TypeMatrix::EMPTY);
}

void test_constructor3() 
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4};
	Matrix<int, 3, 4> mx1;
	mx1.fill(v1.data(), v1.size());

	vector<int> r1; 
	copy(mx1.data(), mx1.data() + mx1.matrix_length(), back_inserter(r1));

	ASSERT_EQUAL(r1, v1);
	ASSERT_EQUAL(mx1.get_ny(), 3u);
	ASSERT_EQUAL(mx1.get_nx(), 4u);
	ASSERT_EQUAL(mx1.get_matrix_type(), TypeMatrix::NONEMPTY);
}

void test_copy_constructor() 
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	Matrix<int, 3, 3> mx1;
	mx1.fill(v1.data(), v1.size());

	Matrix<int, 3, 3> mx2 = mx1;

	vector<int> r1; 
	copy(mx1.data(), mx1.data() + mx1.matrix_length(), back_inserter(r1));

	vector<int> r2; 
	copy(mx2.data(), mx2.data() + mx2.matrix_length(), back_inserter(r2));

	ASSERT_EQUAL(r1, r2);
	ASSERT_EQUAL(mx1.get_ny(), mx2.get_ny());
	ASSERT_EQUAL(mx1.get_nx(), mx2.get_nx());
	ASSERT_EQUAL(mx1.get_matrix_type(), mx2.get_matrix_type());
}

void test_copy_constructor1() 
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 10, 12, 13, 15, 16};

	Matrix<int, 4, 4> mx1;
	mx1.fill(v1.data(), v1.size());

	Matrix<int, 4, 4> mx2 = mx1;

	vector<int> r1; 
	copy(mx1.data(), mx1.data() + mx1.matrix_length(), back_inserter(r1));

	vector<int> r2; 
	copy(mx2.data(), mx2.data() + mx2.matrix_length(), back_inserter(r2));

	ASSERT_EQUAL(r1, r2);
	ASSERT_EQUAL(mx1.get_ny(), mx2.get_ny());
	ASSERT_EQUAL(mx1.get_nx(), mx2.get_nx());
	ASSERT_EQUAL(mx1.get_matrix_type(), mx2.get_matrix_type());
}

void test_copy_constructor2() 
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8};
	Matrix<int, 4, 2> mx1;
	mx1.fill(v1.data(), v1.size());

	Matrix<int, 4, 2> mx2 = mx1;

	vector<int> r1; 
	copy(mx1.data(), mx1.data() + mx1.matrix_length(), back_inserter(r1));

	vector<int> r2; 
	copy(mx2.data(), mx2.data() + mx2.matrix_length(), back_inserter(r2));

	ASSERT_EQUAL(r1, r2);
	ASSERT_EQUAL(mx1.get_ny(), mx2.get_ny());
	ASSERT_EQUAL(mx1.get_nx(), mx2.get_nx());
	ASSERT_EQUAL(mx1.get_matrix_type(), mx2.get_matrix_type());
}

void test_copy_constructor3() 
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 10, 12, 13, 15, 16};

	Matrix<int, 1, 16> mx1;
	mx1.fill(v1.data(), v1.size());

	Matrix<int, 1, 16> mx2 = mx1;

	vector<int> r1; 
	copy(mx1.data(), mx1.data() + mx1.matrix_length(), back_inserter(r1));

	vector<int> r2; 
	copy(mx2.data(), mx2.data() + mx2.matrix_length(), back_inserter(r2));

	ASSERT_EQUAL(r1, r2);
	ASSERT_EQUAL(mx1.get_ny(), mx2.get_ny());
	ASSERT_EQUAL(mx1.get_nx(), mx2.get_nx());
	ASSERT_EQUAL(mx1.get_matrix_type(), mx2.get_matrix_type());
}

void test_copy_assignment() 
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	Matrix<int, 3, 3> mx1;
	mx1.fill(v1.data(), v1.size());

	Matrix<int, 3, 3> mx2;

	mx2 = mx1;

	vector<int> r1; 
	copy(mx1.data(), mx1.data() + mx1.matrix_length(), back_inserter(r1));

	vector<int> r2; 
	copy(mx2.data(), mx2.data() + mx2.matrix_length(), back_inserter(r2));

	ASSERT_EQUAL(r1, r2);
	ASSERT_EQUAL(mx1.get_ny(), mx2.get_ny());
	ASSERT_EQUAL(mx1.get_nx(), mx2.get_nx());
	ASSERT_EQUAL(mx1.get_matrix_type(), mx2.get_matrix_type());
}

void test_copy_assignment1() 
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 10, 12, 13, 15, 16};

	Matrix<int, 4, 4> mx1;
	mx1.fill(v1.data(), v1.size());

	Matrix<int, 4, 4> mx2;
	mx2 = mx1;

	vector<int> r1; 
	copy(mx1.data(), mx1.data() + mx1.matrix_length(), back_inserter(r1));

	vector<int> r2; 
	copy(mx2.data(), mx2.data() + mx2.matrix_length(), back_inserter(r2));

	ASSERT_EQUAL(r1, r2);
	ASSERT_EQUAL(mx1.get_ny(), mx2.get_ny());
	ASSERT_EQUAL(mx1.get_nx(), mx2.get_nx());
	ASSERT_EQUAL(mx1.get_matrix_type(), mx2.get_matrix_type());
}

void test_copy_assignment2() 
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	Matrix<int, 2, 5> mx1;
	mx1.fill(v1.data(), v1.size());

	Matrix<int, 2, 5> mx2;
	mx2 = mx1;

	vector<int> r1; 
	copy(mx1.data(), mx1.data() + mx1.matrix_length(), back_inserter(r1));

	vector<int> r2; 
	copy(mx2.data(), mx2.data() + mx2.matrix_length(), back_inserter(r2));

	ASSERT_EQUAL(r1, r2);
	ASSERT_EQUAL(mx1.get_ny(), mx2.get_ny());
	ASSERT_EQUAL(mx1.get_nx(), mx2.get_nx());
	ASSERT_EQUAL(mx1.get_matrix_type(), mx2.get_matrix_type());
}

void test_copy_assignment3() 
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 10, 12, 13, 15, 16};

	Matrix<int, 8, 2> mx1;
	mx1.fill(v1.data(), v1.size());

	Matrix<int, 8, 2> mx2;
	mx2 = mx1;

	vector<int> r1; 
	copy(mx1.data(), mx1.data() + mx1.matrix_length(), back_inserter(r1));

	vector<int> r2; 
	copy(mx2.data(), mx2.data() + mx2.matrix_length(), back_inserter(r2));

	ASSERT_EQUAL(r1, r2);
	ASSERT_EQUAL(mx1.get_ny(), mx2.get_ny());
	ASSERT_EQUAL(mx1.get_nx(), mx2.get_nx());
	ASSERT_EQUAL(mx1.get_matrix_type(), mx2.get_matrix_type());
}

void test_move_constructor() 
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	Matrix<int, 3, 3> mx1;
	mx1.fill(v1.data(), v1.size());

	Matrix<int, 3, 3> mx2 = move(mx1);

	vector<int> r1; 
	copy(mx2.data(), mx2.data() + mx2.matrix_length(), back_inserter(r1));

	ASSERT_EQUAL(r1, v1);
	ASSERT_EQUAL(mx2.get_ny(), 3u);
	ASSERT_EQUAL(mx2.get_nx(), 3u);
	ASSERT_EQUAL(mx2.get_matrix_type(), TypeMatrix::NONEMPTY);
}

void test_move_constructor1() 
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 10, 12, 13, 15, 16};

	Matrix<int, 4, 4> mx1;
	mx1.fill(v1.data(), v1.size());

	Matrix<int, 4, 4> mx2 = move(mx1);

	vector<int> r1; 
	copy(mx2.data(), mx2.data() + mx2.matrix_length(), back_inserter(r1));

	ASSERT_EQUAL(r1, v1);
	ASSERT_EQUAL(mx2.get_ny(), 4u);
	ASSERT_EQUAL(mx2.get_nx(), 4u);
	ASSERT_EQUAL(mx2.get_matrix_type(), TypeMatrix::NONEMPTY);
}

void test_move_constructor3() 
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 12};

	Matrix<int, 1, 10> mx1;
	mx1.fill(v1.data(), v1.size());

	Matrix<int, 1, 10> mx2 = move(mx1);

	vector<int> r1; 
	copy(mx2.data(), mx2.data() + mx2.matrix_length(), back_inserter(r1));

	ASSERT_EQUAL(r1, v1);
	ASSERT_EQUAL(mx2.get_ny(), 1u);
	ASSERT_EQUAL(mx2.get_nx(), 10u);
	ASSERT_EQUAL(mx2.get_matrix_type(), TypeMatrix::NONEMPTY);
}

void test_move_constructor4() 
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 10, 12, 13, 15, 16, 17, 18, 19, 20, 21};

	Matrix<int, 7, 3> mx1;
	mx1.fill(v1.data(), v1.size());

	Matrix<int, 7, 3> mx2 = move(mx1);

	vector<int> r1; 
	copy(mx2.data(), mx2.data() + mx2.matrix_length(), back_inserter(r1));

	ASSERT_EQUAL(r1, v1);
	ASSERT_EQUAL(mx2.get_ny(), 7u);
	ASSERT_EQUAL(mx2.get_nx(), 3u);
	ASSERT_EQUAL(mx2.get_matrix_type(), TypeMatrix::NONEMPTY);
}

void test_move_assignment() 
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	Matrix<int, 3, 3> mx1;
	mx1.fill(v1.data(), v1.size());

	Matrix<int, 3, 3> mx2;
	mx2 = move(mx1);

	vector<int> r1; 
	copy(mx2.data(), mx2.data() + mx2.matrix_length(), back_inserter(r1));

	ASSERT_EQUAL(r1, v1);
	ASSERT_EQUAL(mx2.get_ny(), 3u);
	ASSERT_EQUAL(mx2.get_nx(), 3u);
	ASSERT_EQUAL(mx2.get_matrix_type(), TypeMatrix::NONEMPTY);
}

void test_move_assignment1() 
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 10, 12, 13, 15, 16};

	Matrix<int, 4, 4> mx1;
	mx1.fill(v1.data(), v1.size());

	Matrix<int, 4, 4> mx2;
	mx2 = move(mx1);

	vector<int> r1; 
	copy(mx2.data(), mx2.data() + mx2.matrix_length(), back_inserter(r1));

	ASSERT_EQUAL(r1, v1);
	ASSERT_EQUAL(mx2.get_ny(), 4u);
	ASSERT_EQUAL(mx2.get_nx(), 4u);
	ASSERT_EQUAL(mx2.get_matrix_type(), TypeMatrix::NONEMPTY);
}

void test_move_assignment2() 
{
	vector<int> v1 = {1, 2, 3};

	Matrix<int, 3, 1> mx1;
	mx1.fill(v1.data(), v1.size());

	Matrix<int, 3, 1> mx2;
	mx2 = move(mx1);

	vector<int> r1; 
	copy(mx2.data(), mx2.data() + mx2.matrix_length(), back_inserter(r1));

	ASSERT_EQUAL(r1, v1);
	ASSERT_EQUAL(mx2.get_ny(), 3u);
	ASSERT_EQUAL(mx2.get_nx(), 1u);
	ASSERT_EQUAL(mx2.get_matrix_type(), TypeMatrix::NONEMPTY);
}

void test_move_assignment3() 
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 10, 12, 13, 15, 16, 17, 18};

	Matrix<int, 3, 6> mx1;
	mx1.fill(v1.data(), v1.size());

	Matrix<int, 3, 6> mx2;
	mx2 = move(mx1);

	vector<int> r1; 
	copy(mx2.data(), mx2.data() + mx2.matrix_length(), back_inserter(r1));

	ASSERT_EQUAL(r1, v1);
	ASSERT_EQUAL(mx2.get_ny(), 3u);
	ASSERT_EQUAL(mx2.get_nx(), 6u);
	ASSERT_EQUAL(mx2.get_matrix_type(), TypeMatrix::NONEMPTY);
}

/*void test_mat_mul() {
	vector<int> v1 = {1, 2, 1, 3, 2, 3};
	Matrix<int, 3> mx1; 
	mx1.am(v1);

	vector<int> r1; 
	copy(mx1.data(), mx1.data() + 9, back_inserter(r1));

	ASSERT_EQUAL(r1, vector({0,1,1, 1,0,1, 1,1,0}));

	vector<int> v2 = {1, 2, 1, 3};
	Matrix<int, 3> mx2; 
	mx2.am(v2);

	vector<int> r2; 
	copy(mx2.data(), mx2.data() + 9, back_inserter(r2));

	ASSERT_EQUAL(r2, vector({0,1,1, 1,0,0, 1,0,0}));

	Matrix<int, 3> res;
	res.matmul(mx1, mx2);

	vector<int> r3; 
	copy(res.data(), res.data() + 9, back_inserter(r3));

	ASSERT_EQUAL(r3, vector({2,0,0,1,1,1,1,1,1}));
}

void test_mat_mul1() {
	vector<int> v1 = {1, 2, 1, 3, 1, 4, 3, 4};
	Matrix<int, 4> mx1; 
	mx1.am(v1);

	vector<int> r1; 
	copy(mx1.data(), mx1.data() + 16, back_inserter(r1));

	ASSERT_EQUAL(r1, vector({0,1,1,1, 1,0,0,0, 1,0,0,1, 1,0,1,0}));

	vector<int> v2 = {1, 2, 1, 3, 1, 4, 2, 3, 2, 4};
	Matrix<int, 4> mx2; 
	mx2.am(v2);

	vector<int> r2; 
	copy(mx2.data(), mx2.data() + 16, back_inserter(r2));

	ASSERT_EQUAL(r2, vector({0,1,1,1, 1,0,1,1, 1,1,0,0, 1,1,0,0}));

	Matrix<int, 4> res;
	res.matmul(mx1, mx2);

	vector<int> r3; 
	copy(res.data(), res.data() + 16, back_inserter(r3));

	ASSERT_EQUAL(r3, vector({3,2,1,1, 0,1,1,1, 1,2,1,1, 1,2,1,1}));
}

void test_exp2() {
	vector<int> v = {1, 2, 1, 3, 2, 3}; 
	Matrix<int, 3> mx; 
	mx.am(v);

	vector<int> r; 
	copy(mx.data(), mx.data() + 9, back_inserter(r));

	ASSERT_EQUAL(r, vector({0,1,1, 1,0,1, 1,1,0}));

	Matrix<int, 3> res;
	res.exp2(mx);

	vector<int> r2; 
	copy(res.data(), res.data() + 9, back_inserter(r2));

	ASSERT_EQUAL(r2, vector({2,1,1, 1,2,1, 1,1,2}));
}

void test_exp2_1() {
	vector<int> v = {1, 2, 1, 3, 1, 4, 2, 3, 2, 4};
	Matrix<int, 4> mx; 
	mx.am(v);

	vector<int> r; 
	copy(mx.data(), mx.data() + 16, back_inserter(r));

	ASSERT_EQUAL(r, vector({0,1,1,1, 1,0,1,1, 1,1,0,0, 1,1,0,0}));

	Matrix<int, 4> res;
	res.exp2(mx);

	vector<int> r3; 
	copy(res.data(), res.data() + 16, back_inserter(r3));

	ASSERT_EQUAL(r3, vector({3,2,1,1, 2,3,1,1, 1,1,2,2, 1,1,2,2}));
}

void test_mat_sum() {
	vector<int> v1 = {1, 2, 1, 3, 2, 3}; 
	Matrix<int, 3> mx1; 
	mx1.am(v1);

	vector<int> r1; 
	copy(mx1.data(), mx1.data() + 9, back_inserter(r1));

	ASSERT_EQUAL(r1, vector({0,1,1, 1,0,1, 1,1,0}));

	vector<int> v2 = {1, 2, 1, 3};
	Matrix<int, 3> mx2; 
	mx2.am(v2);

	vector<int> r2; 
	copy(mx2.data(), mx2.data() + 9, back_inserter(r2));

	ASSERT_EQUAL(r2, vector({0,1,1, 1,0,0, 1,0,0}));

	Matrix<int, 3> res;
	res.sum(mx1, mx2);

	vector<int> r3; 
	copy(res.data(), res.data() + 9, back_inserter(r3));

	ASSERT_EQUAL(r3, vector({0,2,2,2,0,1,2,1,0}));
}

void test_mat_sum1() {
	vector<int> v1 = {1, 2, 1, 3, 1, 4, 3, 4}; 
	Matrix<int, 4> mx1; 
	mx1.am(v1);

	vector<int> r1; 
	copy(mx1.data(), mx1.data() + 16, back_inserter(r1));

	ASSERT_EQUAL(r1, vector({0,1,1,1, 1,0,0,0, 1,0,0,1, 1,0,1,0}));

	vector<int> v2 = {1, 2, 1, 3, 1, 4, 2, 3, 2, 4};
	Matrix<int, 4> mx2; 
	mx2.am(v2);

	vector<int> r2; 
	copy(mx2.data(), mx2.data() + 16, back_inserter(r2));

	ASSERT_EQUAL(r2, vector({0,1,1,1, 1,0,1,1, 1,1,0,0, 1,1,0,0}));

	Matrix<int, 4> res;
	res.sum(mx1, mx2);

	vector<int> r3; 
	copy(res.data(), res.data() + 16, back_inserter(r3));

	ASSERT_EQUAL(r3, vector({0,2,2,2, 2,0,1,1, 2,1,0,1, 2,1,1,0}));
}*/