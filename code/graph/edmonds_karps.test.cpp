void test() {
	/* Field testing: UVa259 */

	vii* adj = new vii[4];
	adj[0].push_back(ii(1, 133700));
	adj[0].push_back(ii(2, 133700));
	adj[1].push_back(ii(2, 1));
	adj[1].push_back(ii(3, 133700));
	adj[2].push_back(ii(3, 133700));

	assert_equal(2 * 133700, max_flow(4, 0, 3, adj));
	delete[] adj;

	adj = new vii[5];
	adj[1].push_back(ii(2, 100));
	adj[1].push_back(ii(3, 50));
	adj[2].push_back(ii(3, 50));
	adj[2].push_back(ii(4, 50));
	adj[2].push_back(ii(0, 50));
	adj[3].push_back(ii(4, 100));
	adj[4].push_back(ii(0, 125));

	assert_equal(150, max_flow(5, 1, 0, adj));
	delete[] adj;

	adj = new vii[5];
	adj[1].push_back(ii(2, 100));
	adj[1].push_back(ii(3, 50));
	adj[2].push_back(ii(3, 50));
	adj[2].push_back(ii(4, 50));
	adj[2].push_back(ii(0, 50));
	adj[3].push_back(ii(4, 100));
	adj[4].push_back(ii(0, 75));

	assert_equal(125, max_flow(5, 1, 0, adj));
	delete[] adj;

	adj = new vii[5];
	adj[1].push_back(ii(2, 100));
	adj[1].push_back(ii(3, 50));
	adj[2].push_back(ii(4, 5));
	adj[2].push_back(ii(0, 5));
	adj[3].push_back(ii(4, 100));
	adj[4].push_back(ii(0, 125));

	assert_equal(60, max_flow(5, 1, 0, adj));
	delete[] adj;
}