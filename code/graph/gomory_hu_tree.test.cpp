
void test() {
  int N = 20;
  int MAX = 10000;

  flow_network g(N);
  pair<vii, vvi> gh;

  for(int i = 0; i < N; i++) {
    for(int j = i+1; j < N; j++) {
      gh = construct_gh_tree(g);
      for(int x = 0; x < N; ++x) {
        for(int y = 0; y < N; ++y) {
          if (x == y) continue;
          assert_equal(g.max_flow(x, y), compute_max_flow(x, y, gh));
        }
      }

      int cap = rand() % MAX;
      g.add_edge(i, j, cap, cap);
    }
  }

  gh = construct_gh_tree(g);
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      if (i == j) continue;
      assert_equal(g.max_flow(i, j), compute_max_flow(i, j, gh));
    }
  }


  // TODO: fix GH, and then uncomment these tests (they fail with low probability)
  // N = 500;
  // g = flow_network(N);
  // int cnt = 0;
  // rep(i,0,N) {
  //     rep(j,0,N) {
  //         if (rand() % 1000 == 0) {
  //             g.add_edge(i,j,rand() % MAX);
  //             cnt++;
  //         }
  //     }
  // }
  //
  // gh = construct_gh_tree(g);
  // rep(i,0,N) {
  //     int a = rand() % N,
  //         b = rand() % N;
  //     assert_equal(g.max_flow(a,b), compute_max_flow(a,b,gh));
  // }
}

// vim: cc=60 ts=2 sts=2 sw=2:
