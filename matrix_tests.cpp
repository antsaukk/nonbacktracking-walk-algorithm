void test_mat_mul() {
	vector<int> v1 = {1, 2, 1, 3, 2, 3}; 
	Matrix<int> mx1; 
	mx1.allocate(3);
	mx1.am(v1);

	vector<int> r1; 
	copy(mx1.get(), mx1.get() + 9, back_inserter(r1));

	ASSERT_EQUAL(r1, vector({0,1,1, 1,0,1, 1,1,0}));

	vector<int> v2 = {1, 2, 1, 3};
	Matrix<int> mx2; 
	mx2.allocate(3);
	mx2.am(v2);

	vector<int> r2; 
	copy(mx2.get(), mx2.get() + 9, back_inserter(r2));

	ASSERT_EQUAL(r2, vector({0,1,1, 1,0,0, 1,0,0}));

	Matrix<int> res;
	res.allocate(3);
	res.matmul(mx1.get(), mx2.get());

	vector<int> r3; 
	copy(res.get(), res.get() + 9, back_inserter(r3));

	ASSERT_EQUAL(r3, vector({2,0,0,1,1,1,1,1,1}));
}

void test_mat_mul1() {
	vector<int> v1 = {1, 2, 1, 3, 1, 4, 3, 4}; 
	Matrix<int> mx1; 
	mx1.allocate(4);
	mx1.am(v1);

	vector<int> r1; 
	copy(mx1.get(), mx1.get() + 16, back_inserter(r1));

	ASSERT_EQUAL(r1, vector({0,1,1,1, 1,0,0,0, 1,0,0,1, 1,0,1,0}));

	vector<int> v2 = {1, 2, 1, 3, 1, 4, 2, 3, 2, 4};
	Matrix<int> mx2; 
	mx2.allocate(4);
	mx2.am(v2);

	vector<int> r2; 
	copy(mx2.get(), mx2.get() + 16, back_inserter(r2));

	ASSERT_EQUAL(r2, vector({0,1,1,1, 1,0,1,1, 1,1,0,0, 1,1,0,0}));

	Matrix<int> res;
	res.allocate(4);
	res.matmul(mx1.get(), mx2.get());

	vector<int> r3; 
	copy(res.get(), res.get() + 16, back_inserter(r3));

	ASSERT_EQUAL(r3, vector({3,2,1,1, 0,1,1,1, 1,2,1,1, 1,2,1,1}));
}

void test_exp2() {
	vector<int> v = {1, 2, 1, 3, 2, 3}; 
	Matrix<int> mx; 
	mx.allocate(3);
	mx.am(v);

	vector<int> r; 
	copy(mx.get(), mx.get() + 9, back_inserter(r));

	ASSERT_EQUAL(r, vector({0,1,1, 1,0,1, 1,1,0}));

	Matrix<int> res;
	res.allocate(3);
	res.exp2(mx.get());

	vector<int> r2; 
	copy(res.get(), res.get() + 9, back_inserter(r2));

	ASSERT_EQUAL(r2, vector({2,1,1, 1,2,1, 1,1,2}));
}

void test_exp2_1() {
	vector<int> v = {1, 2, 1, 3, 1, 4, 2, 3, 2, 4};
	Matrix<int> mx; 
	mx.allocate(4);
	mx.am(v);

	vector<int> r; 
	copy(mx.get(), mx.get() + 16, back_inserter(r));

	ASSERT_EQUAL(r, vector({0,1,1,1, 1,0,1,1, 1,1,0,0, 1,1,0,0}));

	Matrix<int> res;
	res.allocate(4);
	res.exp2(mx.get());

	vector<int> r3; 
	copy(res.get(), res.get() + 16, back_inserter(r3));

	ASSERT_EQUAL(r3, vector({3,2,1,1, 2,3,1,1, 1,1,2,2, 1,1,2,2}));
}

void test_mat_sum() {
	vector<int> v1 = {1, 2, 1, 3, 2, 3}; 
	Matrix<int> mx1; 
	mx1.allocate(3);
	mx1.am(v1);

	vector<int> r1; 
	copy(mx1.get(), mx1.get() + 9, back_inserter(r1));

	ASSERT_EQUAL(r1, vector({0,1,1, 1,0,1, 1,1,0}));

	vector<int> v2 = {1, 2, 1, 3};
	Matrix<int> mx2; 
	mx2.allocate(3);
	mx2.am(v2);

	vector<int> r2; 
	copy(mx2.get(), mx2.get() + 9, back_inserter(r2));

	ASSERT_EQUAL(r2, vector({0,1,1, 1,0,0, 1,0,0}));

	Matrix<int> res;
	res.allocate(3);
	res.sum(mx1.get(), mx2.get());

	vector<int> r3; 
	copy(res.get(), res.get() + 9, back_inserter(r3));

	ASSERT_EQUAL(r3, vector({0,2,2,2,0,1,2,1,0}));
}

void test_mat_sum1() {
	vector<int> v1 = {1, 2, 1, 3, 1, 4, 3, 4}; 
	Matrix<int> mx1; 
	mx1.allocate(4);
	mx1.am(v1);

	vector<int> r1; 
	copy(mx1.get(), mx1.get() + 16, back_inserter(r1));

	ASSERT_EQUAL(r1, vector({0,1,1,1, 1,0,0,0, 1,0,0,1, 1,0,1,0}));

	vector<int> v2 = {1, 2, 1, 3, 1, 4, 2, 3, 2, 4};
	Matrix<int> mx2; 
	mx2.allocate(4);
	mx2.am(v2);

	vector<int> r2; 
	copy(mx2.get(), mx2.get() + 16, back_inserter(r2));

	ASSERT_EQUAL(r2, vector({0,1,1,1, 1,0,1,1, 1,1,0,0, 1,1,0,0}));

	Matrix<int> res;
	res.allocate(4);
	res.sum(mx1.get(), mx2.get());

	vector<int> r3; 
	copy(res.get(), res.get() + 16, back_inserter(r3));

	ASSERT_EQUAL(r3, vector({0,2,2,2, 2,0,1,1, 2,1,0,1, 2,1,1,0}));
}