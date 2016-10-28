void tsort_dfs(int cur, char* color, const vvi& adj,
    stack<int>& res, bool& cyc) {
  color[cur] = 1;
  rep(i,0,size(adj[cur])) {
    int nxt = adj[cur][i];
    if (color[nxt] == 0)
      tsort_dfs(nxt, color, adj, res, cyc);
    else if (color[nxt] == 1)
      cyc = true;
    if (cyc) return; }
  color[cur] = 2;
  res.push(cur); }
vi tsort(int n, vvi adj, bool& cyc) {
  cyc = false;
  stack<int> S;
  vi res;
  char* color = new char[n];
  memset(color, 0, n);
  rep(i,0,n) {
    if (!color[i]) {
      tsort_dfs(i, color, adj, S, cyc);
      if (cyc) return res; } }
  while (!S.empty()) res.push_back(S.top()), S.pop();
  return res; }
// vim: cc=60 ts=2 sts=2 sw=2:
