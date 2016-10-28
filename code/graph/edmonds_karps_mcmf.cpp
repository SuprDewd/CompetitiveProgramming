#define MAXV 2000
int d[MAXV], p[MAXV], pot[MAXV];
struct cmp { bool operator ()(int i, int j) {
    return d[i] == d[j] ? i < j : d[i] < d[j]; } };
struct flow_network {
  struct edge { int v, nxt, cap, cost;
    edge(int _v, int _cap, int _cost, int _nxt)
      : v(_v), nxt(_nxt), cap(_cap), cost(_cost) { } };
  int n; vi head; vector<edge> e, e_store;
  flow_network(int _n) : n(_n), head(n,-1) { }
  void reset() { e = e_store; }
  void add_edge(int u, int v, int cost, int uv, int vu=0) {
    e.push_back(edge(v, uv, cost, head[u]));
    head[u] = size(e)-1;
    e.push_back(edge(u, vu, -cost, head[v]));
    head[v] = size(e)-1; }
  ii min_cost_max_flow(int s, int t, bool res=true) {
    e_store = e;
    memset(pot, 0, n*sizeof(int));
    rep(it,0,n-1) rep(i,0,size(e)) if (e[i].cap > 0)
      pot[e[i].v] =
        min(pot[e[i].v], pot[e[i^1].v] + e[i].cost);
    int v, f = 0, c = 0;
    while (true) {
      memset(d, -1, n*sizeof(int));
      memset(p, -1, n*sizeof(int));
      set<int, cmp> q;
      d[s] = 0; q.insert(s);
      while (!q.empty()) {
        int u = *q.begin();
        q.erase(q.begin());
        for (int i = head[u]; i != -1; i = e[i].nxt) {
          if (e[i].cap == 0) continue;
          int cd = d[u] + e[i].cost + pot[u] - pot[v = e[i].v];
          if (d[v] == -1 || cd < d[v]) {
            q.erase(v);
            d[v] = cd; p[v] = i;
            q.insert(v); } } }
      if (p[t] == -1) break;
      int at = p[t], x = INF;
      while (at != -1)
        x = min(x, e[at].cap), at = p[e[at^1].v];
      at = p[t], f += x;
      while (at != -1)
        e[at].cap -= x, e[at^1].cap += x, at = p[e[at^1].v];
      c += x * (d[t] + pot[t] - pot[s]);
      rep(i,0,n) if (p[i] != -1) pot[i] += d[i]; }
    if (res) reset();
    return ii(f, c); } };
// vim: cc=60 ts=2 sts=2 sw=2:
