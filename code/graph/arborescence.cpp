#include "../data-structures/union_find.cpp"
struct arborescence {
  int n; union_find uf;
  vector<vector<pair<ii,int> > > adj;
  arborescence(int _n) : n(_n), uf(n), adj(n) { }
  void add_edge(int a, int b, int c) {
    adj[b].push_back(make_pair(ii(a,b),c)); }
  vii find_min(int r) {
    vi vis(n,-1), mn(n,INF); vii par(n);
    rep(i,0,n) {
      if (uf.find(i) != i) continue;
      int at = i;
      while (at != r && vis[at] == -1) {
        vis[at] = i;
        iter(it,adj[at]) if (it->second < mn[at] &&
            uf.find(it->first.first) != at)
          mn[at] = it->second, par[at] = it->first;
        if (par[at] == ii(0,0)) return vii();
        at = uf.find(par[at].first); }
      if (at == r || vis[at] != i) continue;
      union_find tmp = uf; vi seq;
      do { seq.push_back(at); at = uf.find(par[at].first);
      } while (at != seq.front());
      iter(it,seq) uf.unite(*it,seq[0]);
      int c = uf.find(seq[0]);
      vector<pair<ii,int> > nw;
      iter(it,seq) iter(jt,adj[*it])
        nw.push_back(make_pair(jt->first,
              jt->second - mn[*it]));
      adj[c] = nw;
      vii rest = find_min(r);
      if (size(rest) == 0) return rest;
      ii use = rest[c];
      rest[at = tmp.find(use.second)] = use;
      iter(it,seq) if (*it != at)
        rest[*it] = par[*it];
      return rest; }
    return par; } };
// vim: cc=60 ts=2 sts=2 sw=2:
