int n, cur[100], pos;
int calch() {
  int h = 0;
  rep(i,0,n) if (cur[i] != 0) h += abs(i - cur[i]);
  return h; }
int dfs(int d, int g, int prev) {
  int h = calch();
  if (g + h > d) return g + h;
  if (h == 0) return 0;
  int mn = INF;
  rep(di,-2,3) {
    if (di == 0) continue;
    int nxt = pos + di;
    if (nxt == prev) continue;
    if (0 <= nxt && nxt < n) {
      swap(cur[pos], cur[nxt]);
      swap(pos,nxt);
      mn = min(mn, dfs(d, g+1, nxt));
      swap(pos,nxt);
      swap(cur[pos], cur[nxt]); }
    if (mn == 0) break; }
  return mn; }
int idastar() {
  rep(i,0,n) if (cur[i] == 0) pos = i;
  int d = calch();
  while (true) {
    int nd = dfs(d, 0, -1);
    if (nd == 0 || nd == INF) return d;
    d = nd; } }
// vim: cc=60 ts=2 sts=2 sw=2:
