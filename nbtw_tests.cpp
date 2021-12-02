void test_delta() {
	SpectralGraph<int, 3> g(3);
	vector<int> v1 = {1, 2, 1, 3, 2, 3};
	g.adjacency_matrix(v1);

	vector<int> r1; 
	copy(g.get_A().data(), g.get_A().data() + 9, back_inserter(r1));

	ASSERT_EQUAL(r1, vector({0,1,1, 1,0,1, 1,1,0}));

	g.delta_matrix();
	ASSERT_EQUAL(g.get_delta(), vector({2, 2, 2}));
}

void test_delta1() {
	SpectralGraph<int, 4> g(4);
	vector<int> v1 = {1, 2, 1, 3, 1, 4, 3, 4}; 
	g.adjacency_matrix(v1);

	vector<int> r1; 
	copy(g.get_A().data(), g.get_A().data() + 16, back_inserter(r1));

	ASSERT_EQUAL(r1, vector({0,1,1,1, 1,0,0,0, 1,0,0,1, 1,0,1,0}));

	g.delta_matrix();
	ASSERT_EQUAL(g.get_delta(), vector({3, 1, 2, 2}));
}

void test_exp() {
	SpectralGraph<int, 3> g(3);
	vector<int> v1 = {1, 2, 1, 3, 2, 3};
	g.adjacency_matrix(v1);

	vector<int> r1; 
	copy(g.get_A().data(), g.get_A().data() + 9, back_inserter(r1));

	ASSERT_EQUAL(r1, vector({0,1,1, 1,0,1, 1,1,0}));

	vector<int> r2;
	copy(g.getp2_A().data(), g.getp2_A().data() + 9, back_inserter(r2));

	ASSERT_EQUAL(r2, vector({2,1,1, 1,2,1, 1,1,2}));
}

void test_exp1() {
	SpectralGraph<int, 4> g(4);
	vector<int> v1 = {1, 2, 1, 3, 1, 4, 3, 4};
	g.adjacency_matrix(v1);

	vector<int> r1; 
	copy(g.get_A().data(), g.get_A().data() + 16, back_inserter(r1));

	ASSERT_EQUAL(r1, vector({0,1,1,1, 1,0,0,0, 1,0,0,1, 1,0,1,0}));

	vector<int> r2;
	copy(g.getp2_A().data(), g.getp2_A().data() + 16, back_inserter(r2));

	ASSERT_EQUAL(r2, vector({3,0,1,1, 0,1,1,1, 1,1,2,1, 1,1,1,2}));
}

void test_nbtw() {
	SpectralGraph<int, 3> g(3);
	vector<int> v1 = {1, 2, 1, 3, 2, 3};
	g.adjacency_matrix(v1);
	g.nbtw_naive(1, 1);
}