#include "mod_pow.cpp"
template <class T>
bool is_probable_prime(T n, int k) {
  if (~n & 1) return n == 2;
  if (n <= 3) return n == 3;
  int s = 0; T d = n - 1;
  while (~d & 1) d >>= 1, s++;
  while (k--) {
    T a = (n - 3) * rand() / RAND_MAX + 2;
    T x = mod_pow(a, d, n);
    if (x == 1 || x == n - 1) continue;
    bool ok = false;
    rep(i,0,s-1) {
      x = (x * x) % n;
      if (x == 1) return false;
      if (x == n - 1) { ok = true; break; }
    }
    if (!ok) return false;
  } return true; }
// vim: cc=60 ts=2 sts=2 sw=2:
