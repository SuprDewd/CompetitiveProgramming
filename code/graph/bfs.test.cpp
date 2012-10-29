void test() {
	vvi adj(8);
	adj[0].pb(4);
	adj[1].pb(4);
	adj[1].pb(2);
	adj[2].pb(3);
	adj[3].pb(0);
	adj[4].pb(0);
	adj[5].pb(7);
	adj[6].pb(5);
	adj[7].pb(6);

	for (int i = 0; i < size(adj); i++)
		assert_equal(0, bfs(i, i, adj));

	assert_equal(1, bfs(0, 4, adj));
	assert_equal(1, bfs(4, 0, adj));
	assert_equal(2, bfs(5, 6, adj));
	assert_equal(1, bfs(6, 5, adj));
	assert_equal(1, bfs(1, 2, adj));
	assert_equal(2, bfs(1, 3, adj));
	assert_equal(2, bfs(1, 0, adj));
}