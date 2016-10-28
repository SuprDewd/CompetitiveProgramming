#include "../data-structures/union_find.cpp"
struct tarjan_olca {
  int *ancestor;
  vi *adj, answers;
  vii *queries;
  bool *colored;
  union_find uf;
  tarjan_olca(int n, vi *_adj) : adj(_adj), uf(n) {
    colored = new bool[n];
    ancestor = new int[n];
    queries = new vii[n];
    memset(colored, 0, n); }
  void query(int x, int y) {
    queries[x].push_back(ii(y, size(answers)));
    queries[y].push_back(ii(x, size(answers)));
    answers.push_back(-1); }
  void process(int u) {
    ancestor[u] = u;
    rep(i,0,size(adj[u])) {
      int v = adj[u][i];
      process(v);
      uf.unite(u,v);
      ancestor[uf.find(u)] = u; }
    colored[u] = true;
    rep(i,0,size(queries[u])) {
      int v = queries[u][i].first;
      if (colored[v]) {
        answers[queries[u][i].second] = ancestor[uf.find(v)];
      } } } };
// vim: cc=60 ts=2 sts=2 sw=2:
