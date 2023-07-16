#ifndef STNODE
#define STNODE
struct node {
  int l, r;
  ll x, lazy;
  node() {}
  node(int _l, int _r) : l(_l), r(_r), x(INF), lazy(0) { }
  node(int _l, int _r, ll _x) : node(_l,_r) { x = _x; }
  node(node a, node b) : node(a.l,b.r) { x = min(a.x, b.x); }
  void update(ll v) { x = v; }
  void range_update(ll v) { lazy = v; }
  void apply() { x += lazy; lazy = 0; }
  void push(node &u) { u.lazy += lazy; } };
#endif
// vim: cc=60 ts=2 sts=2 sw=2:
