#define RESIZE
#define SWP(x,y) tmp = x, x = y, y = tmp
struct default_int_cmp {
  default_int_cmp() { }
  bool operator ()(const int &a, const int &b) {
    return a < b; } };
template <class Compare = default_int_cmp> struct heap {
  int len, count, *q, *loc, tmp;
  Compare _cmp;
  inline bool cmp(int i, int j) { return _cmp(q[i], q[j]); }
  inline void swp(int i, int j) {
    SWP(q[i], q[j]), SWP(loc[q[i]], loc[q[j]]); }
  void swim(int i) {
    while (i > 0) {
      int p = (i - 1) / 2;
      if (!cmp(i, p)) break;
      swp(i, p), i = p; } }
  void sink(int i) {
    while (true) {
      int l = 2*i + 1, r = l + 1;
      if (l >= count) break;
      int m = r >= count || cmp(l, r) ? l : r;
      if (!cmp(m, i)) break;
      swp(m, i), i = m; } }
  heap(int init_len = 128)
    : count(0), len(init_len), _cmp(Compare()) {
    q = new int[len], loc = new int[len];
    memset(loc, 255, len << 2); }
  ~heap() { delete[] q; delete[] loc; }
  void push(int n, bool fix = true) {
    if (len == count || n >= len) {
#ifdef RESIZE
      int newlen = 2 * len;
      while (n >= newlen) newlen *= 2;
      int *newq = new int[newlen], *newloc = new int[newlen];
      rep(i,0,len) newq[i] = q[i], newloc[i] = loc[i];
      memset(newloc + len, 255, (newlen - len) << 2);
      delete[] q, delete[] loc;
      loc = newloc, q = newq, len = newlen;
#else
      assert(false);
#endif
    }
    assert(loc[n] == -1);
    loc[n] = count, q[count++] = n;
    if (fix) swim(count-1); }
  void pop(bool fix = true) {
    assert(count > 0);
    loc[q[0]] = -1, q[0] = q[--count], loc[q[0]] = 0;
    if (fix) sink(0);
  }
  int top() { assert(count > 0); return q[0]; }
  void heapify() { for (int i = count - 1; i > 0; i--)
    if (cmp(i, (i - 1) / 2)) swp(i, (i - 1) / 2); }
  void update_key(int n) {
    assert(loc[n] != -1), swim(loc[n]), sink(loc[n]); }
  bool empty() { return count == 0; }
  int size() { return count; }
  void clear() { count = 0, memset(loc, 255, len << 2); }};
// vim: cc=60 ts=2 sts=2 sw=2:
