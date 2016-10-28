struct { vi adj; int val, num, lo; bool done; } V[2*1000+100];
struct TwoSat {
  int n, at = 0; vi S;
  TwoSat(int _n) : n(_n) {
    rep(i,0,2*n+1)
      V[i].adj.clear(),
      V[i].val = V[i].num = -1, V[i].done = false; }
  bool put(int x, int v) {
    return (V[n+x].val &= v) != (V[n-x].val &= 1-v); }
  void add_or(int x, int y) {
    V[n-x].adj.push_back(n+y), V[n-y].adj.push_back(n+x); }
  int dfs(int u) {
    int br = 2, res;
    S.push_back(u), V[u].num = V[u].lo = at++;
    iter(v,V[u].adj) {
      if (V[*v].num == -1) {
        if (!(res = dfs(*v))) return 0;
        br |= res, V[u].lo = min(V[u].lo, V[*v].lo);
      } else if (!V[*v].done)
        V[u].lo = min(V[u].lo, V[*v].num);
      br |= !V[*v].val; }
    res = br - 3;
    if (V[u].num == V[u].lo) rep(i,res+1,2) {
      for (int j = size(S)-1; ; j--) {
        int v = S[j];
        if (i) {
          if (!put(v-n, res)) return 0;
          V[v].done = true, S.pop_back();
        } else res &= V[v].val;
        if (v == u) break; }
      res &= 1; }
    return br | !res; }
  bool sat() {
    rep(i,0,2*n+1)
      if (i != n && V[i].num == -1 && !dfs(i)) return false;
    return true; } };
// vim: cc=60 ts=2 sts=2 sw=2:
