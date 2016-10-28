void test() {
  vii* adj = new vii[5];
  adj[0].push_back(ii(1, 1));
  adj[0].push_back(ii(2, 10));
  adj[1].push_back(ii(3, 2));
  adj[2].push_back(ii(3, -10));
  adj[3].push_back(ii(4, 3));

  bool neg_cycle;
  int* dist = bellman_ford(5, 0, adj, neg_cycle);

  assert_false(neg_cycle);
  assert_equal(0, dist[0]);
  assert_equal(1, dist[1]);
  assert_equal(10, dist[2]);
  assert_equal(0, dist[3]);
  assert_equal(3, dist[4]);

  delete[] adj;

  adj = new vii[5];
  adj[0].push_back(ii(1, 1));
  adj[0].push_back(ii(2, 0));
  adj[1].push_back(ii(3, 2));
  adj[2].push_back(ii(3, -10));
  adj[3].push_back(ii(4, 3));
  adj[3].push_back(ii(0, 0));

  dist = bellman_ford(5, 0, adj, neg_cycle);

  assert_true(neg_cycle);

  delete[] adj;

  adj = new vii[2];
  adj[0].push_back(ii(1, -1));
  adj[1].push_back(ii(0, -1));

  dist = bellman_ford(2, 0, adj, neg_cycle);

  assert_true(neg_cycle);

  delete[] adj;

  adj = new vii[2];
  adj[0].push_back(ii(1, -1));
  adj[1].push_back(ii(0, -1));

  dist = bellman_ford(2, 1, adj, neg_cycle);

  assert_true(neg_cycle);
}
// vim: cc=60 ts=2 sts=2 sw=2:
