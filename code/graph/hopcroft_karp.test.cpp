#include "../code/graph/bipartite_matching.cpp"

void test_rand(int N, int M, int sparseness = 2) {
  adj = new vi[N];

  done = new bool[N];
  memset(done, 0, sizeof(bool) * N);

  owner = new int[M];
  memset(owner, -1, sizeof(int) * M);

  bipartite_graph g(N, M);

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(rand() % sparseness == 0) {
        g.add_edge(i, j);
        adj[i].push_back(j);
      }
    }
  }

  int sum = 0;
  for(int i = 0; i < N; ++i) {
    memset(done, 0, sizeof(bool) * N);
    sum += alternating_path(i);
  }

  assert_equal(sum, g.maximum_matching());

  delete[] adj;
  delete[] done;
  delete[] owner;
}

void test() {
  int TESTS = 1000, MAX_N = 400, MAX_M = 300;
  for(int i = 0; i < TESTS; ++i) {
    test_rand(rand() % MAX_N, rand() % MAX_M, rand() % 100 + 1);
  }
}

// void test_rand(int N, int M, int sparse) {
//     bipartite_graph g(N, M);
//
//     int cnt = 0;
//
//     for(int i = 0; i < N; i++) {
//         for(int j = 0; j < M; j++) {
//             if(rand() % sparse == 0) {
//                 cnt++;
//                 g.add_edge(i, j);
//             }
//         }
//     }
//
//     cout << g.maximum_matching() << endl;
// }
//
// void test() {
//     int TESTS = 20, MAX_N = 5000, MAX_M = 5000;
//     for(int i = 0; i < TESTS; ++i) {
//         // test_rand(rand() % MAX_N, rand() % MAX_M);
//         test_rand(MAX_N, MAX_M, rand() % 100000);
//     }
// }
// vim: cc=60 ts=2 sts=2 sw=2:
