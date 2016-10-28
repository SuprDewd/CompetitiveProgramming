#include "../code/data-structures/segment_tree_mnnode.cpp"
#include "../code/data-structures/segment_tree.cpp"

int lca_slow(int n, int *ps, int a, int b) {
  vi as, bs;
  while (a != -1) {
    as.push_back(a);
    a = ps[a];
  }

  while (b != -1) {
    bs.push_back(b);
    b = ps[b];
  }

  reverse(as.begin(), as.end());
  reverse(bs.begin(), bs.end());

  int at = 0;
  while (at+1 < size(as) && at+1 < size(bs) && as[at+1] == bs[at+1]) {
    at++;
  }

  return as[at];
}

int* pars(int n, vi *adj) {
  int *res = new int[n];
  memset(res, -1, n << 2);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < size(adj[i]); j++) {
      res[adj[i][j]] = i;
    }
  }
  return res;
}

pair<vi*, int> random_tree(int n) {
  vi *adj = new vi[n];
  vi *children = new vi[n];
  union_find uf(n);

  for (int i = 0; uf.size(0) < n; i++) {
    int a = rand() % n,
      b = rand() % n;

    if (uf.find(a) != uf.find(b)) {
      uf.unite(a, b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  }

  int root = rand() % n;
  stack<int> S;
  S.push(root);
  bool *visited = new bool[n];
  memset(visited, 0, n);
  visited[root] = true;

  while (!S.empty()) {
    int cur = S.top();
    S.pop();
    for (int i = 0; i < size(adj[cur]); i++){
      int nxt = adj[cur][i];
      if (visited[nxt])
        continue;
      children[cur].push_back(nxt);
      S.push(nxt);
      visited[nxt] = true;
    }
  }

  delete[] adj;
  delete[] visited;

  return make_pair(children, root);
}

struct lca_tree {
  int *label;
  int *orig;
  int *start;
  vector<ll> s;
  segment_tree st;

  lca_tree(int n, int root, vi *children) {
    label = new int[n];
    orig = new int[n];
    start = new int[n];
    memset(label, -1, n << 2);
    int at = 0;
    queue<int> Q;
    Q.push(root);
    label[root] = at++;
    while (!Q.empty()) {
      int cur = Q.front();
      orig[label[cur]] = cur;
      Q.pop();
      for (int i = 0; i < size(children[cur]); i++) {
        int nxt = children[cur][i];
        if (label[nxt] == -1) {
          label[nxt] = at++;
          Q.push(nxt);
        }
      }
    }

    seq(children, root);
    st = segment_tree(s);
  }

  void seq(vi *c, int r) {
    start[label[r]] = size(s);
    s.push_back(label[r]);
    for (int i = 0; i < size(c[r]); i++) {
      seq(c, c[r][i]);
      s.push_back(label[r]);
    }
  }

  int lca(int a, int b) {
    a = label[a];
    b = label[b];
    int x = start[a],
      y = start[b];
    if (x > y) swap(x, y);
    return orig[st.query(x, y).x];
  }
};

void test() {
  int tests = 100;

  for (int t = 0; t < tests; t++) {
    int n = rand() % 10000 + 1;
    int q = rand() % 10000 + 1;

    pair<vi*, int> xadj = random_tree(n);
    vi *adj = xadj.first;
    int root = xadj.second;

    int *ps = pars(n, adj);

    lca_tree tr(n, root, adj);
    tarjan_olca lca(n, adj);

    vii qs;
    for (int i = 0; i < q; i++) {
      int a = rand() % n,
        b = rand() % n;

      qs.push_back(ii(a, b));
      lca.query(a, b);
    }

    lca.process(root);

    for (int i = 0; i < q; i++) {
      int correct = lca_slow(n, ps, qs[i].first, qs[i].second);
      int maybe = lca.answers[i];
      int maybe2 = tr.lca(qs[i].first, qs[i].second);
      assert_equal(correct, maybe);
      assert_equal(correct, maybe2);
    }
  }

}
// vim: cc=60 ts=2 sts=2 sw=2:
