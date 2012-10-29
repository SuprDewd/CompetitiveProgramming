map<int, ii> res;

void test_1() {
	int n = 2;
	vvii adj_list(n);

	res = dijkstra_path(0, adj_list);
	assert_true(res.find(1) == res.end());
	assert_true(res.find(0) != res.end());
	assert_equal(0, res[0].first);
	assert_equal(0, res[0].second);

	res = dijkstra_path(1, adj_list);
	assert_true(res.find(0) == res.end());
	assert_true(res.find(1) != res.end());
	assert_equal(0, res[1].first);
	assert_equal(1, res[1].second);
}

void test_2() {
	int n = 2;
	vvii adj_list(n);
	adj_list[0].push_back(ii(42, 1));

	res = dijkstra_path(0, adj_list);
	assert_true(res.find(1) != res.end());
	assert_true(res.find(0) != res.end());
	assert_equal(42, res[1].first);
	assert_equal(0, res[1].second);
	assert_equal(0, res[0].first);
	assert_equal(0, res[0].second);

	res = dijkstra_path(1, adj_list);
	assert_true(res.find(0) == res.end());
	assert_true(res.find(1) != res.end());
	assert_equal(0, res[1].first);
	assert_equal(1, res[1].second);
}

void test_3() {
	int n = 2;
	vvii adj_list(n);
	adj_list[0].push_back(ii(42, 1));
	adj_list[1].push_back(ii(42, 0));

	res = dijkstra_path(0, adj_list);
	assert_true(res.find(1) != res.end());
	assert_true(res.find(0) != res.end());
	assert_equal(42, res[1].first);
	assert_equal(0, res[1].second);
	assert_equal(0, res[0].first);
	assert_equal(0, res[0].second);

	res = dijkstra_path(1, adj_list);
	assert_true(res.find(1) != res.end());
	assert_true(res.find(0) != res.end());
	assert_equal(0, res[1].first);
	assert_equal(1, res[1].second);
	assert_equal(42, res[0].first);
	assert_equal(1, res[0].second);
}

void test_4() {
	int n = 4;
	vvii adj_list(n);
	adj_list[0].push_back(ii(5, 1));
	adj_list[1].push_back(ii(8, 2));
	adj_list[1].push_back(ii(30, 3));
	adj_list[2].push_back(ii(7, 3));

	res = dijkstra_path(0, adj_list);
	assert_true(res.find(1) != res.end());
	assert_equal(5, res[1].first);
	assert_equal(0, res[1].second);
	assert_true(res.find(2) != res.end());
	assert_equal(13, res[2].first);
	assert_equal(1, res[2].second);
	assert_true(res.find(3) != res.end());
	assert_equal(20, res[3].first);
	assert_equal(2, res[3].second);

	res = dijkstra_path(3, adj_list);
	assert_true(res.find(0) == res.end());
	assert_true(res.find(1) == res.end());
	assert_true(res.find(2) == res.end());

	res = dijkstra_path(1, adj_list);
	assert_true(res.find(3) != res.end());
	assert_equal(15, res[3].first);
}

void test() {
	test_1();
	test_2();
	test_3();
	test_4();
}