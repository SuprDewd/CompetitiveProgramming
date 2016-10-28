#include "../code/graph/dinic.cpp"

void test_rand(int N, int M) {
  adj = new vi[N];

  done = new bool[N];
  memset(done, 0, sizeof(bool) * N);

  owner = new int[M];
  memset(owner, -1, sizeof(int) * M);

  flow_network g(N + M + 2);

  int SOURCE = N + M;
  int SINK = N + M + 1;

  for(int i = 0; i < N; i++) {
    g.add_edge(SOURCE, i, 1, 0);
    for(int j = 0; j < M; j++) {
      if(rand() % 2) {
        // cout << i << " -> " << j << endl;
        g.add_edge(i, N + j, 1, 0);
        adj[i].push_back(j);
      }
    }
  }

  for(int j = 0; j < M; j++) {
    g.add_edge(j + N, SINK, 1, 0);
  }

  int sum = 0;
  for(int i = 0; i < N; ++i) {
    memset(done, 0, sizeof(bool) * N);
    sum += alternating_path(i);
  }

  assert_equal(g.max_flow(SOURCE, SINK), sum);

  delete[] adj;
  delete[] done;
  delete[] owner;
}

void test_1() {
  int N = 3, M = 3;

  adj = new vi[N];

  done = new bool[N];

  owner = new int[M];
  memset(owner, -1, sizeof(int) * M);

  flow_network g(N + M + 2);

  int SOURCE = N + M;
  int SINK = N + M + 1;

  for(int i = 0; i < N; i++) {
    g.add_edge(SOURCE, i, 1, 0);
  }

  int graph[][2] = { { 0, 0 }, { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 2 } };

  for(int i = 0; i < 4; ++i) {
    g.add_edge(graph[i][0], graph[i][1] + N, 1, 0);
    adj[graph[i][0]].push_back(graph[i][1]);
  }

  for(int j = 0; j < M; j++) {
    g.add_edge(j + N, SINK, 1, 0);
  }

  int sum = 0;
  for(int i = 0; i < N; ++i) {
    memset(done, 0, sizeof(bool) * N);
    sum += alternating_path(i);
  }

  assert_equal(g.max_flow(SOURCE, SINK), sum);

  delete[] adj;
  delete[] done;
  delete[] owner;
}

void test() {
  test_1();
  int TESTS = 1000, MAX_N = 50, MAX_M = 50;
  for(int i = 0; i < TESTS; ++i) {
    test_rand(rand() % MAX_N, rand() % MAX_M);
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
