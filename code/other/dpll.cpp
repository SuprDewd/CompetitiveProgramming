#define IDX(x) ((abs(x)-1)*2+((x)>0))
struct SAT {
  int n;
  vi cl, head, tail, val;
  vii log; vvi w, loc;
  SAT() : n(0) { }
  int var() { return ++n; }
  void clause(vi vars) {
    set<int> seen; iter(it,vars) {
      if (seen.find(IDX(*it)^1) != seen.end()) return;
      seen.insert(IDX(*it)); }
    head.push_back(cl.size());
    iter(it,seen) cl.push_back(*it);
    tail.push_back((int)cl.size() - 2); }
  bool assume(int x) {
    if (val[x^1]) return false;
    if (val[x]) return true;
    val[x] = true; log.push_back(ii(-1, x));
    rep(i,0,w[x^1].size()) {
      int at = w[x^1][i], h = head[at], t = tail[at];
      log.push_back(ii(at, h));
      if (cl[t+1] != (x^1)) swap(cl[t], cl[t+1]);
      while (h < t && val[cl[h]^1]) h++;
      if ((head[at] = h) < t) {
        w[cl[h]].push_back(w[x^1][i]);
        swap(w[x^1][i--], w[x^1].back());
        w[x^1].pop_back();
        swap(cl[head[at]++], cl[t+1]);
      } else if (!assume(cl[t])) return false; }
    return true; }
  bool bt() {
    int v = log.size(), x; ll b = -1;
    rep(i,0,n) if (val[2*i] == val[2*i+1]) {
      ll s = 0, t = 0;
      rep(j,0,2) { iter(it,loc[2*i])
        s+=1LL<<max(0,40-tail[*it]+head[*it]); swap(s,t); }
      if (max(s,t) >= b) b = max(s,t), x = 2*i + (t>=s); }
    if (b == -1 || (assume(x) && bt())) return true;
    while (log.size() != v) {
      int a = log.back().first, b = log.back().second;
      if (a == -1) val[b] = false; else head[a] = b;
      log.pop_back(); }
    return assume(x^1) && bt(); }
  bool solve() {
    val.assign(2*n+1, false);
    w.assign(2*n+1, vi()); loc.assign(2*n+1, vi());
    rep(i,0,head.size()) {
      if (head[i] == tail[i]+2) return false;
      rep(at,head[i],tail[i]+2) loc[cl[at]].push_back(i); }
    rep(i,0,head.size()) if (head[i] < tail[i]+1) rep(t,0,2)
      w[cl[tail[i]+t]].push_back(i);
    rep(i,0,head.size()) if (head[i] == tail[i]+1)
      if (!assume(cl[head[i]])) return false;
    return bt(); }
  bool get_value(int x) { return val[IDX(x)]; } };
// vim: cc=60 ts=2 sts=2 sw=2:
