void test_1() {
	vvi adj(4);

	adj[0].push_back(1);
	adj[1].push_back(0);
	adj[1].push_back(2);
	adj[2].push_back(3);
	adj[3].push_back(2);

	int* scc = tarjan_scc(adj);

	assert_equal(scc[0], scc[1]);
	assert_equal(scc[2], scc[3]);
	assert_not_equal(scc[0], scc[2]);

	delete[] scc;
}

void test_2() {
	vvi adj(2);

	adj[0].push_back(1);

	int* scc = tarjan_scc(adj);

	assert_not_equal(scc[0], scc[1]);

	delete[] scc;
}

void test_3() {
	vvi adj(5);

	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[2].push_back(3);
	adj[3].push_back(4);
	adj[4].push_back(0);

	int* scc = tarjan_scc(adj);

	assert_equal(scc[0], scc[1]);
	assert_equal(scc[2], scc[1]);
	assert_equal(scc[2], scc[3]);
	assert_equal(scc[4], scc[3]);

	delete[] scc;
}

void test_4() {
	vvi adj(5);

	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[2].push_back(3);
	adj[3].push_back(4);

	int* scc = tarjan_scc(adj);

	assert_not_equal(scc[0], scc[1]);
	assert_not_equal(scc[0], scc[2]);
	assert_not_equal(scc[0], scc[3]);
	assert_not_equal(scc[0], scc[4]);
	assert_not_equal(scc[1], scc[2]);
	assert_not_equal(scc[1], scc[3]);
	assert_not_equal(scc[1], scc[4]);
	assert_not_equal(scc[2], scc[3]);
	assert_not_equal(scc[2], scc[4]);
	assert_not_equal(scc[3], scc[4]);

	delete[] scc;
}

void test_5() {
	vvi adj(5);

	int* scc = tarjan_scc(adj);

	assert_not_equal(scc[0], scc[1]);
	assert_not_equal(scc[0], scc[2]);
	assert_not_equal(scc[0], scc[3]);
	assert_not_equal(scc[0], scc[4]);
	assert_not_equal(scc[1], scc[2]);
	assert_not_equal(scc[1], scc[3]);
	assert_not_equal(scc[1], scc[4]);
	assert_not_equal(scc[2], scc[3]);
	assert_not_equal(scc[2], scc[4]);
	assert_not_equal(scc[3], scc[4]);

	delete[] scc;
}

void test_6() {
	vvi adj(2);

	for (int i = 0; i < 100; i++)
	{
		adj[0].push_back(0);
		adj[1].push_back(1);
	}

	int* scc = tarjan_scc(adj);

	assert_not_equal(scc[0], scc[1]);

	delete[] scc;
}

void test_7() {
	vvi adj(2);

	for (int i = 0; i < 100; i++)
	{
		adj[0].push_back(0);
		adj[1].push_back(1);
	}

	adj[0].push_back(1);

	int* scc = tarjan_scc(adj);

	assert_not_equal(scc[0], scc[1]);

	delete[] scc;
}

void test_8() {
	vvi adj(2);

	for (int i = 0; i < 100; i++)
	{
		adj[0].push_back(0);
		adj[1].push_back(1);
	}

	adj[1].push_back(0);

	int* scc = tarjan_scc(adj);

	assert_not_equal(scc[0], scc[1]);

	delete[] scc;
}

void test_9() {
	vvi adj(2);

	for (int i = 0; i < 100; i++)
	{
		adj[0].push_back(0);
		adj[1].push_back(1);
	}

	adj[0].push_back(1);
	adj[1].push_back(0);

	int* scc = tarjan_scc(adj);

	assert_equal(scc[0], scc[1]);

	delete[] scc;
}

void test() {
	test_1();
	test_2();
	test_3();
	test_4();
	test_5();
	test_6();
	test_7();
	test_8();
	test_9();
}