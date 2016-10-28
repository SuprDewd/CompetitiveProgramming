#include "primitives.cpp"
point circumcenter(point a, point b, point c) {
  b -= a, c -= a;
  return a +
    perp(b * norm(c) - c * norm(b)) / 2.0 / cross(b, c); }
// vim: cc=60 ts=2 sts=2 sw=2:
