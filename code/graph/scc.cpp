#include "../data-structures/union_find.cpp"
vector<bool> visited;
vi order;
void scc_dfs(const vvi &adj, int u) {
  int v; visited[u] = true;
  rep(i,0,size(adj[u]))
    if (!visited[v = adj[u][i]]) scc_dfs(adj, v);
  order.push_back(u); }
pair<union_find, vi> scc(const vvi &adj) {
  int n = size(adj), u, v;
  order.clear();
  union_find uf(n); vi dag; vvi rev(n);
  rep(i,0,n) rep(j,0,size(adj[i])) rev[adj[i][j]].push_back(i);
  visited.resize(n);
  fill(visited.begin(), visited.end(), false);
  rep(i,0,n) if (!visited[i]) scc_dfs(rev, i);
  fill(visited.begin(), visited.end(), false);
  stack<int> S;
  for (int i = n-1; i >= 0; i--) {
    if (visited[order[i]]) continue;
    S.push(order[i]), dag.push_back(order[i]);
    while (!S.empty()) {
      visited[u = S.top()] = true, S.pop();
      uf.unite(u, order[i]);
      rep(j,0,size(adj[u]))
        if (!visited[v = adj[u][j]]) S.push(v); } }
  return pair<union_find, vi>(uf, dag); }
// vim: cc=60 ts=2 sts=2 sw=2:
