#include "../code/data-structures/union_find.cpp"

struct HLD_naive {
  int n;
  vector<vii> adj;
  vii parent;

  HLD_naive(int _n) : n(_n), adj(n), parent(n, ii(-1, ID)) { }

  void add_edge(int u, int v) {
    adj[u].push_back(ii(v, ID));
    adj[v].push_back(ii(u, ID));
    parent[v] = ii(u, ID);
  }

  void update_cost(int u, int v, int c) {
    if (parent[v].first == u)
      swap(u, v);

    assert(parent[u].first == v);
    parent[u] = ii(v, c);

    for (int i = 0; i < size(adj[u]); i++)
      if (adj[u][i].first == v)
        adj[u][i] = ii(v, c);

    for (int i = 0; i < size(adj[v]); i++)
      if (adj[v][i].first == u)
        adj[v][i] = ii(u, c);
  }

  int lca(int u, int v) {
    vi uat, vat; int res = -1;
    while (u != -1) uat.push_back(u), u = parent[u].first;
    while (v != -1) vat.push_back(v), v = parent[v].first;
    u = size(uat) - 1, v = size(vat) - 1;
    while (u >= 0 && v >= 0 && uat[u] == vat[v])
      res = uat[u], u--, v--;
    return res;
  }

  // int query_upto(int u, int v) {

  // }

  int query(int u, int v) {
    // int l = lca(u, v);
    // return f(query_upto(u, l), query_upto(v, l));

    vector<bool> visited(n, false);
    stack<ii> S;
    S.push(ii(u, ID));
    visited[u] = true;

    while (!S.empty())
    {
      ii cur = S.top(); S.pop();
      // printf("%d\n", cur.first);

      if (cur.first == v)
        return cur.second;

      for (int i = 0; i < size(adj[cur.first]); i++)
      {
        int nxt = adj[cur.first][i].first;
        if (!visited[nxt])
        {
          visited[nxt] = true;
          S.push(ii(nxt, f(cur.second, adj[cur.first][i].second)));
        }
      }
    }

    assert(false);
  }
};

// int randint(int a, int b)
// {
//     return rand() % (b - a + 1) + a;
// }

void test() {
  /* Field testing: SPOJ LCA, SPOJ QTREE, TOJ 2241, Live Archive 2045, Live Archive 6140, UVa 10938, IPSC 2009 L */

  // srand(100);

  int ts = 100,
    maxn = 1000,
    maxq = 1000,
    minc = -1000,
    maxc = 1000;

  // ts = 100000;
  // maxn = 4;
  // minc = 1;
  // maxc = 4;
  // maxq = 5;

  for (int t = 0; t < ts; t++)
  {
    // printf("%d\n", t);

    int n = randint(1, maxn),
      qs = maxq;

    HLD hld1(n);
    HLD_naive hld2(n);

    union_find uf(n);
    vii edges;
    vvi adj(n);
    for (int i = 0; i < n - 1; i++)
    {
      while (true)
      {
        int a = randint(0, n - 1),
          b = randint(0, n - 1);

        if (uf.find(a) == uf.find(b))
          continue;

        uf.unite(a, b);
        // hld1.add_edge(a, b);
        // hld2.add_edge(a, b);
        edges.push_back(ii(a, b));
        edges.push_back(ii(b, a));
        adj[a].push_back(b);
        adj[b].push_back(a);
        hld1.add_edge(a,b);
        break;
      }
    }

    vector<int> parent(n, -1);

    stack<int> S;
    vector<bool> visited(n, false);
    int root = randint(0, n - 1);
    visited[root] = true;
    S.push(root);

    while (!S.empty())
    {
      int cur = S.top(); S.pop();
      for (int i = 0; i < size(adj[cur]); i++)
      {
        int nxt = adj[cur][i];
        if (!visited[nxt])
        {
          visited[nxt] = true;
          S.push(nxt);
          // hld1.add_edge(cur, nxt);
          hld2.add_edge(cur, nxt);
          parent[nxt] = cur;
        }
      }
    }

    hld1.build(root);

    // printf("\n\n");
    // for (int i = 0; i < n; i++)
    // {
    //     if (i != 0) printf(" ");
    //     printf("%d", parent[i]);
    // }

    // printf("\n");

    for (int q = 0; q < qs; q++)
    {
      // printf("\t%d\n", q);

      int type = randint(1, 3);
      // printf("\t\t%d\n", type);

      if (type == 1) // LCA
      {
        int u = randint(0, n - 1),
          v = randint(0, n - 1);

        int l1 = hld1.lca(u, v);
        int l2 = hld2.lca(u, v);

        // printf("lca %d %d = %d %d\n", u, v, l1, l2);

        assert_equal(l1, l2, true);
      }
      else if (type == 2) // QUERY
      {
        int u = randint(0, n - 1),
          v = randint(0, n - 1);

        int l1 = hld1.query(u, v);
        // printf("\t\t%d\n", l1);
        int l2 = hld2.query(u, v);
        // printf("\t\t%d\n", l2);

        // printf("query %d %d = %d %d\n", u, v, l1, l2);

        assert_equal(l1, l2, true);
      }
      else if (type == 3) // UPDATE
      {
        if (n > 1)
        {
          int i = randint(0, size(edges) - 1);
          int u = edges[i].first,
            v = edges[i].second;

          int c = randint(minc, maxc);

          // printf("update %d %d %d\n", u, v, c);

          hld1.update_cost(u, v, c);
          hld2.update_cost(u, v, c);
        }
      }
    }
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
