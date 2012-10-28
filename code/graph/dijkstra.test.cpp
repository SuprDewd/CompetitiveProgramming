void test_1() {
	int n = 2;
	vvii adj_list(n);
	assert_equal(-1, dijkstra(0, 1, adj_list));
	assert_equal(-1, dijkstra(1, 0, adj_list));
}

void test_2() {
	int n = 2;
	vvii adj_list(n);
	adj_list[0].push_back(ii(42, 1));
	assert_equal(42, dijkstra(0, 1, adj_list));
	assert_equal(-1, dijkstra(1, 0, adj_list));
}

void test_3() {
	int n = 2;
	vvii adj_list(n);
	adj_list[0].push_back(ii(42, 1));
	adj_list[1].push_back(ii(42, 0));
	assert_equal(42, dijkstra(0, 1, adj_list));
	assert_equal(42, dijkstra(1, 0, adj_list));
}

void test_4() {
	int n = 4;
	vvii adj_list(n);
	adj_list[0].push_back(ii(5, 1));
	adj_list[1].push_back(ii(8, 2));
	adj_list[1].push_back(ii(30, 3));
	adj_list[2].push_back(ii(7, 3));
	assert_equal(5, dijkstra(0, 1, adj_list));
	assert_equal(13, dijkstra(0, 2, adj_list));
	assert_equal(20, dijkstra(0, 3, adj_list));
	assert_equal(-1, dijkstra(3, 0, adj_list));
	assert_equal(15, dijkstra(1, 3, adj_list));
}

void test() {
	test_1();
	test_2();
	test_3();
	test_4();
}