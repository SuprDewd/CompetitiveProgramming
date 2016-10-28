#define BITS 15
struct misof_tree {
  int cnt[BITS][1<<BITS];
  misof_tree() { memset(cnt, 0, sizeof(cnt)); }
  void insert(int x) {
    for (int i = 0; i < BITS; cnt[i++][x]++, x >>= 1); }
  void erase(int x) {
    for (int i = 0; i < BITS; cnt[i++][x]--, x >>= 1); }
  int nth(int n) {
    int res = 0;
    for (int i = BITS-1; i >= 0; i--)
      if (cnt[i][res <<= 1] <= n) n -= cnt[i][res], res |= 1;
    return res; } };
// vim: cc=60 ts=2 sts=2 sw=2:
