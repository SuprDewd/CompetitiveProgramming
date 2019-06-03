struct MatroidIntersection {
  virtual void add(int element) = 0;
  virtual void remove(int element) = 0;
  virtual bool valid1(int element) = 0;
  virtual bool valid2(int element) = 0;
  int n, found; vi arr; vector<ll> ws; ll weight;
  MatroidIntersection(vector<ll> weights)
    : n(weights.size()), found(0), ws(weights), weight(0) {
      rep(i,0,n) arr.push_back(i); }
  bool increase() {
    vector<tuple<int,int,ll>> es;
    vector<pair<ll,int>> d(n+1, {1000000000000000000LL,0});
    vi p(n+1,-1), a, r; bool ch;
    rep(at,found,n) {
      if (valid1(arr[at])) d[p[at] = at] = {-ws[arr[at]],0};
      if (valid2(arr[at])) es.emplace_back(at, n, 0); }
    rep(cur,0,found) {
      remove(arr[cur]);
      rep(nxt,found,n) {
        if (valid1(arr[nxt]))
          es.emplace_back(cur, nxt, -ws[arr[nxt]]);
        if (valid2(arr[nxt]))
          es.emplace_back(nxt, cur, ws[arr[cur]]); }
      add(arr[cur]); }
    do { ch = false;
      for (auto [u,v,c] : es) {
        pair<ll,int> nd(d[u].first + c, d[u].second + 1);
        if (p[u] != -1 && nd < d[v])
          d[v] = nd, p[v] = u, ch = true; } } while (ch);
    if (p[n] == -1) return false;
    int cur = p[n];
    while(p[cur]!=cur)a.push_back(cur),a.swap(r),cur=p[cur];
    a.push_back(cur);
    sort(a.begin(), a.end()); sort(r.rbegin(), r.rend());
    iter(it,r)remove(arr[*it]),swap(arr[--found],arr[*it]);
    iter(it,a)add(arr[*it]),swap(arr[found++],arr[*it]);
    weight -= d[n].first; return true; } };
// vim: cc=60 ts=2 sts=2 sw=2:
