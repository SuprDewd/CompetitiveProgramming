#include "primitives.cpp"
bool collinear(L(a, b), L(p, q)) {
  return abs(ccw(a, b, p)) < EPS && abs(ccw(a, b, q)) < EPS; }
bool parallel(L(a, b), L(p, q)) {
  return abs(cross(b - a, q - p)) < EPS; }
point closest_point(L(a, b), P(c), bool segment = false) {
  if (segment) {
    if (dot(b - a, c - b) > 0) return b;
    if (dot(a - b, c - a) > 0) return a;
  }
  double t = dot(c - a, b - a) / norm(b - a);
  return a + t * (b - a); }
double line_segment_distance(L(a,b), L(c,d)) {
  double x = INFINITY;
  if (abs(a - b) < EPS && abs(c - d) < EPS) x = abs(a - c);
  else if (abs(a - b) < EPS)
    x = abs(a - closest_point(c, d, a, true));
  else if (abs(c - d) < EPS)
    x = abs(c - closest_point(a, b, c, true));
  else if ((ccw(a, b, c) < 0) != (ccw(a, b, d) < 0) &&
       (ccw(c, d, a) < 0) != (ccw(c, d, b) < 0)) x = 0;
  else {
    x = min(x, abs(a - closest_point(c,d, a, true)));
    x = min(x, abs(b - closest_point(c,d, b, true)));
    x = min(x, abs(c - closest_point(a,b, c, true)));
    x = min(x, abs(d - closest_point(a,b, d, true)));
  }
  return x; }
bool intersect(L(a,b), L(p,q), point &res, bool seg=false) {
  // NOTE: check parallel/collinear before
  point r = b - a, s = q - p;
  double c = cross(r, s),
         t = cross(p - a, s) / c, u = cross(p - a, r) / c;
  if (seg &&
      (t < 0-EPS || t > 1+EPS || u < 0-EPS || u > 1+EPS))
    return false;
  res = a + t * r;
  return true; }
// vim: cc=60 ts=2 sts=2 sw=2:
