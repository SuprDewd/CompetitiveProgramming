#include "fstream"

/* Field testing: USACO butter, UVa 721 */
void test() {
  ifstream ifs("dijkstra.test.in");
  int ts;
  ifs >> ts;
  for (int t = 0; t < ts; t++) {
    int n, m;
    ifs >> n >> m;
    vector<ii> *adj = new vector<ii>[n];
    for (int i = 0; i < m; i++) {
      int a, b, c;
      ifs >> a >> b >> c;
      adj[a].push_back(ii(b, c));
    }

    for (int i = 0; i < n; i++) {
      pair<int*, int*> res = dijkstra(n, i, adj);
      for (int j = 0; j < n; j++) {
        int correct;
        ifs >> correct;

        if (correct == -1) {
          assert_equal(INF, res.first[j]);
        } else {
          assert_equal(correct, res.first[j]);
        }
      }
    }
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
