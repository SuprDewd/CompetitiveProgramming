#define MAXV 2000
int q[MAXV], p[MAXV], d[MAXV];
struct flow_network {
  struct edge { int v, nxt, cap;
    edge(int _v, int _cap, int _nxt)
      : v(_v), nxt(_nxt), cap(_cap) { } };
  int n, *head; vector<edge> e, e_store;
  flow_network(int _n) : n(_n) {
    memset(head = new int[n], -1, n*sizeof(int)); }
  void reset() { e = e_store; }
  void add_edge(int u, int v, int uv, int vu=0) {
    e.push_back(edge(v, uv, head[u])); head[u] = size(e)-1;
    e.push_back(edge(u, vu, head[v])); head[v] = size(e)-1; }
  int max_flow(int s, int t, bool res=true) {
    e_store = e;
    int l, r, v, f = 0;
    while (true) {
      memset(d, -1, n*sizeof(int));
      memset(p, -1, n*sizeof(int));
      l = r = 0, d[q[r++] = s] = 0;
      while (l < r)
        for (int u = q[l++], i = head[u]; i != -1; i=e[i].nxt)
          if (e[i].cap > 0 &&
              (d[v = e[i].v] == -1 || d[u] + 1 < d[v]))
            d[v] = d[u] + 1, p[q[r++] = v] = i;
      if (p[t] == -1) break;
      int at = p[t], x = INF;
      while (at != -1)
        x = min(x, e[at].cap), at = p[e[at^1].v];
      at = p[t], f += x;
      while (at != -1)
        e[at].cap -= x, e[at^1].cap += x, at = p[e[at^1].v]; }
    if (res) reset();
    return f; } };
// vim: cc=60 ts=2 sts=2 sw=2:
