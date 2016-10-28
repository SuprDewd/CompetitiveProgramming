struct fenwick_tree {
  int n; vi data;
  fenwick_tree(int _n) : n(_n), data(vi(n)) { }
  void update(int at, int by) {
    while (at < n) data[at] += by, at |= at + 1; }
  int query(int at) {
    int res = 0;
    while (at >= 0) res += data[at], at = (at & (at + 1)) - 1;
    return res; }
  int rsq(int a, int b) { return query(b) - query(a - 1); }
};
struct fenwick_tree_sq {
  int n; fenwick_tree x1, x0;
  fenwick_tree_sq(int _n) : n(_n), x1(fenwick_tree(n)),
    x0(fenwick_tree(n)) { }
  // insert f(y) = my + c if x <= y
  void update(int x, int m, int c) {
    x1.update(x, m); x0.update(x, c); }
  int query(int x) { return x*x1.query(x) + x0.query(x); }
};
void range_update(fenwick_tree_sq &s, int a, int b, int k) {
  s.update(a, k, k * (1 - a)); s.update(b+1, -k, k * b); }
int range_query(fenwick_tree_sq &s, int a, int b) {
  return s.query(b) - s.query(a-1); }
// vim: cc=60 ts=2 sts=2 sw=2:
