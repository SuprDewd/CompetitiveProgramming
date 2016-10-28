#include "../data-structures/segment_tree.cpp"
const int ID = 0;
int f(int a, int b) { return a + b; }
struct HLD {
  int n, curhead, curloc;
  vi sz, head, parent, loc;
  vvi adj; segment_tree values;
  HLD(int _n) : n(_n), sz(n, 1), head(n),
                parent(n, -1), loc(n), adj(n) {
    vector<ll> tmp(n, ID); values = segment_tree(tmp); }
  void add_edge(int u, int v) {
    adj[u].push_back(v); adj[v].push_back(u); }
  void update_cost(int u, int v, int c) {
    if (parent[v] == u) swap(u, v); assert(parent[u] == v);
    values.update(loc[u], c); }
  int csz(int u) {
    rep(i,0,size(adj[u])) if (adj[u][i] != parent[u])
      sz[u] += csz(adj[parent[adj[u][i]] = u][i]);
    return sz[u]; }
  void part(int u) {
    head[u] = curhead; loc[u] = curloc++;
    int best = -1;
    rep(i,0,size(adj[u]))
      if (adj[u][i] != parent[u] &&
          (best == -1 || sz[adj[u][i]] > sz[best]))
        best = adj[u][i];
    if (best != -1) part(best);
    rep(i,0,size(adj[u]))
      if (adj[u][i] != parent[u] && adj[u][i] != best)
        part(curhead = adj[u][i]); }
  void build(int r = 0) {
    curloc = 0, csz(curhead = r), part(r); }
  int lca(int u, int v) {
    vi uat, vat; int res = -1;
    while (u != -1) uat.push_back(u), u = parent[head[u]];
    while (v != -1) vat.push_back(v), v = parent[head[v]];
    u = size(uat) - 1, v = size(vat) - 1;
    while (u >= 0 && v >= 0 && head[uat[u]] == head[vat[v]])
      res = (loc[uat[u]] < loc[vat[v]] ? uat[u] : vat[v]),
      u--, v--;
    return res; }
  int query_upto(int u, int v) { int res = ID;
    while (head[u] != head[v])
      res = f(res, values.query(loc[head[u]], loc[u]).x),
      u = parent[head[u]];
    return f(res, values.query(loc[v] + 1, loc[u]).x); }
  int query(int u, int v) { int l = lca(u, v);
    return f(query_upto(u, l), query_upto(v, l)); } };
// vim: cc=60 ts=2 sts=2 sw=2:
