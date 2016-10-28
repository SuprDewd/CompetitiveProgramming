#include "lines.cpp"
bool line_segment_intersect(L(a, b), L(c, d), point &A,
                                              point &B) {
  if (abs(a - b) < EPS && abs(c - d) < EPS) {
    A = B = a; return abs(a - d) < EPS; }
  else if (abs(a - b) < EPS) {
    A = B = a; double p = progress(a, c,d);
    return 0.0 <= p && p <= 1.0
      && (abs(a - c) + abs(d - a) - abs(d - c)) < EPS; }
  else if (abs(c - d) < EPS) {
    A = B = c; double p = progress(c, a,b);
    return 0.0 <= p && p <= 1.0
      && (abs(c - a) + abs(b - c) - abs(b - a)) < EPS; }
  else if (collinear(a,b, c,d)) {
    double ap = progress(a, c,d), bp = progress(b, c,d);
    if (ap > bp) swap(ap, bp);
    if (bp < 0.0 || ap > 1.0) return false;
    A = c + max(ap, 0.0) * (d - c);
    B = c + min(bp, 1.0) * (d - c);
    return true; }
  else if (parallel(a,b, c,d)) return false;
  else if (intersect(a,b, c,d, A, true)) {
    B = A; return true; }
  return false; }
// vim: cc=60 ts=2 sts=2 sw=2:
