namespace dinic {
#include "../code/graph/dinic.cpp"
}

void test1() {
  int N = 20;
  int MAX = 100000;

  flow_network mf(N);
  dinic::flow_network mf2(N);

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      int cap = rand() % MAX + 1;
      mf.add_edge(i, j, cap);
      mf2.add_edge(i, j, cap);
    }
  }

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      if (i == j) continue;
      assert_equal(mf2.max_flow(i, j), mf.max_flow(i, j));
    }
  }
}

void test2() {
  int N = 20;
  int MAX = 100000;

  flow_network mf(N);
  dinic::flow_network mf2(N);

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      int cap = rand() % MAX + 1;
      mf.add_edge(i, j, cap, cap);
      mf2.add_edge(i, j, cap, cap);
    }
  }

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      if (i == j) continue;
      assert_equal(mf2.max_flow(i, j), mf.max_flow(i, j));
    }
  }
}

void test3() {
  int N = 20;
  int MAX = 100000;

  flow_network mf(N);
  dinic::flow_network mf2(N);

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      int cap = rand() % MAX + 1;
      mf.add_edge(i, j, cap, cap);
      mf.add_edge(i, j, cap, cap);
      mf2.add_edge(i, j, cap, cap);
      mf2.add_edge(i, j, cap, cap);
    }
  }

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      if (i == j) continue;
      assert_equal(mf2.max_flow(i, j), mf.max_flow(i, j));
    }
  }
}

void test() {
  /* Field testing: UVa259, UVa670, UVa10080, UVa10330, ICPC Live Archive 5905, ICPC Live Archive 3792 */
  /* Field testing (v2): Kattis maxflow */

  flow_network mf(4);
  mf.add_edge(0, 1, 133700);
  mf.add_edge(0, 2, 133700);
  mf.add_edge(1, 2, 1);
  mf.add_edge(1, 3, 133700);
  mf.add_edge(2, 3, 133700);
  assert_equal(2 * 133700, mf.max_flow(0, 3));

  mf = flow_network(5);
  mf.add_edge(1, 2, 100);
  mf.add_edge(1, 3, 50);
  mf.add_edge(2, 3, 50);
  mf.add_edge(2, 4, 50);
  mf.add_edge(2, 0, 50);
  mf.add_edge(3, 4, 100);
  mf.add_edge(4, 0, 125);
  assert_equal(150, mf.max_flow(1, 0));

  mf = flow_network(5);
  mf.add_edge(1, 2, 100);
  mf.add_edge(1, 3, 50);
  mf.add_edge(2, 3, 50);
  mf.add_edge(2, 4, 50);
  mf.add_edge(2, 0, 50);
  mf.add_edge(3, 4, 100);
  mf.add_edge(4, 0, 75);
  assert_equal(125, mf.max_flow(1, 0));

  mf = flow_network(5);
  mf.add_edge(1, 2, 100);
  mf.add_edge(1, 3, 50);
  mf.add_edge(2, 4, 5);
  mf.add_edge(2, 0, 5);
  mf.add_edge(3, 4, 100);
  mf.add_edge(4, 0, 125);
  assert_equal(60, mf.max_flow(1, 0));

  test1();
  test2();
  test3();
}
// vim: cc=60 ts=2 sts=2 sw=2:
