#include "egcd.cpp"
template <class T>
T mod_inv(T a, T m) {
  T x, y, d = egcd(a, m, x, y);
  return d == 1 ? smod(x,m) : -1; }
// vim: cc=60 ts=2 sts=2 sw=2:
