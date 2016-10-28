#include "polygon.cpp"
#define MAXN 1000
point hull[MAXN];
bool cmp(const point &a, const point &b) {
  return abs(real(a) - real(b)) > EPS ?
    real(a) < real(b) : imag(a) < imag(b); }
int convex_hull(polygon p) {
  int n = size(p), l = 0;
  sort(p.begin(), p.end(), cmp);
  rep(i,0,n) {
    if (i > 0 && p[i] == p[i - 1]) continue;
    while (l >= 2 &&
        ccw(hull[l - 2], hull[l - 1], p[i]) >= 0) l--;
    hull[l++] = p[i]; }
  int r = l;
  for (int i = n - 2; i >= 0; i--) {
    if (p[i] == p[i + 1]) continue;
    while (r - l >= 1 &&
        ccw(hull[r - 2], hull[r - 1], p[i]) >= 0) r--;
    hull[r++] = p[i]; }
  return l == 1 ? 1 : r - 1; }
// vim: cc=60 ts=2 sts=2 sw=2:
