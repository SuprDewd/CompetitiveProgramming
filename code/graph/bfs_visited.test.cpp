void test() {
    vvi adj(8);
    adj[0].push_back(4);
    adj[1].push_back(4);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(0);
    adj[4].push_back(0);
    adj[5].push_back(7);
    adj[6].push_back(5);
    adj[7].push_back(6);

    for (int i = 0; i < size(adj); i++)
        assert_equal(0, bfs(i, i, adj));

    assert_equal(1, bfs(0, 4, adj));
    assert_equal(1, bfs(4, 0, adj));
    assert_equal(2, bfs(5, 6, adj));
    assert_equal(1, bfs(6, 5, adj));
    assert_equal(1, bfs(1, 2, adj));
    assert_equal(2, bfs(1, 3, adj));
    assert_equal(2, bfs(1, 0, adj));
    assert_equal(-1, bfs(6, 4, adj));
    assert_equal(-1, bfs(0, 1, adj));
    assert_equal(-1, bfs(5, 0, adj));
}
