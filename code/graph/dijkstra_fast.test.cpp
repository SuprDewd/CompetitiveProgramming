pair<int*, int*> res;
vector<ii> *adj;

void test_1() {
    int n = 3;
    adj = new vector<ii>[n];
    adj[0].push_back(ii(1, 10));
    adj[0].push_back(ii(2, 56));
    adj[0].push_back(ii(0, 2));
    adj[1].push_back(ii(2, 23));
    adj[1].push_back(ii(0, 3));
    adj[2].push_back(ii(0, 4));
    adj[2].push_back(ii(1, 5));
    adj[2].push_back(ii(2, 1));
    res = dijkstra_fast(n, 0, adj);
    assert_equal(0, res.first[0]);
    assert_equal(-1, res.second[0]);
    assert_equal(10, res.first[1]);
    assert_equal(0, res.second[1]);
    assert_equal(33, res.first[2]);
    assert_equal(1, res.second[2]);
    delete[] res.first;
    delete[] res.second;

    res = dijkstra_fast(n, 1, adj);
    assert_equal(0, res.first[1]);
    assert_equal(-1, res.second[1]);
    assert_equal(3, res.first[0]);
    assert_equal(1, res.second[0]);
    delete[] res.first;
    delete[] res.second;
    delete[] adj;
}

void test_2() {
    int n = 2;
    adj = new vector<ii>[n];
    adj[0].push_back(ii(1, 42));

    res = dijkstra_fast(n, 0, adj);
    assert_equal(42, res.first[1]);
    assert_equal(0, res.second[1]);
    assert_equal(0, res.first[0]);
    assert_equal(-1, res.second[0]);
    delete[] res.first;
    delete[] res.second;

    res = dijkstra_fast(n, 1, adj);
    assert_equal(-1, res.second[0]);
    assert_equal(INF, res.first[0]);
    assert_equal(0, res.first[1]);
    assert_equal(-1, res.second[1]);
    delete[] res.first;
    delete[] res.second;
    delete[] adj;
}

void test_3() {
    int n = 2;
    adj = new vector<ii>[n];
    adj[0].push_back(ii(1, 42));
    adj[1].push_back(ii(0, 42));

    res = dijkstra_fast(n, 0, adj);
    assert_equal(42, res.first[1]);
    assert_equal(0, res.second[1]);
    assert_equal(0, res.first[0]);
    assert_equal(-1, res.second[0]);
    delete[] res.first;
    delete[] res.second;

    res = dijkstra_fast(n, 1, adj);
    assert_equal(0, res.first[1]);
    assert_equal(-1, res.second[1]);
    assert_equal(42, res.first[0]);
    assert_equal(1, res.second[0]);
    delete[] res.first;
    delete[] res.second;
    delete[] adj;
}

void test_4() {
    int n = 4;
    adj = new vector<ii>[n];
    adj[0].push_back(ii(1, 5));
    adj[1].push_back(ii(2, 8));
    adj[1].push_back(ii(3, 30));
    adj[2].push_back(ii(3, 7));

    res = dijkstra_fast(n, 0, adj);
    assert_equal(5, res.first[1]);
    assert_equal(0, res.second[1]);
    assert_equal(13, res.first[2]);
    assert_equal(1, res.second[2]);
    assert_equal(20, res.first[3]);
    assert_equal(2, res.second[3]);
    delete[] res.first;
    delete[] res.second;

    res = dijkstra_fast(n, 3, adj);
    assert_equal(INF, res.first[0]);
    assert_equal(-1, res.second[0]);
    assert_equal(INF, res.first[1]);
    assert_equal(-1, res.second[1]);
    assert_equal(INF, res.first[2]);
    assert_equal(-1, res.second[2]);
    delete[] res.first;
    delete[] res.second;

    res = dijkstra_fast(n, 1, adj);
    assert_equal(15, res.first[3]);
    delete[] res.first;
    delete[] res.second;
    delete[] adj;
}

void test_5() {
    int n = 4;
    adj = new vector<ii>[n];
    adj[0].push_back(ii(1, 4));
    adj[0].push_back(ii(2, 5));
    adj[1].push_back(ii(3, 2));
    adj[2].push_back(ii(1, -5));

    res = dijkstra_fast(n, 0, adj);
    assert_equal(0, res.first[0]);
    assert_equal(5, res.first[2]);
    assert_equal(0, res.second[2]);
    assert_equal(0, res.first[1]);
    assert_equal(2, res.second[1]);
    assert_equal(2, res.first[3]);
    assert_equal(1, res.second[3]);
    delete[] res.first;
    delete[] res.second;
    delete[] adj;
}

void test_6() {
    int n = 2;
    adj = new vector<ii>[n];

    res = dijkstra_fast(n, 0, adj);
    assert_equal(-1, res.second[1]);
    assert_equal(0, res.first[0]);
    assert_equal(-1, res.second[0]);
    delete[] res.first;
    delete[] res.second;

    res = dijkstra_fast(n, 1, adj);
    assert_equal(-1, res.second[0]);
    assert_equal(0, res.first[1]);
    assert_equal(-1, res.second[1]);
    delete[] res.first;
    delete[] res.second;
    delete[] adj;
}

void test() {
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
}
