#include "gcd.cpp"
template <class T>
T rho(T n, T seed) {
  T i = 0, k = 2;
  T x = seed, y = seed;
  while (i < 1000000) {
    i++;
    x = (x*x + n - 1) % n;
    T d = gcd(abs(y - x), n);
    if (d != 1 && d != n) return d;
    if (i == k) {
      y = x;
      k = k*2;
    }
  }
  return 1;
}
// vim: cc=60 ts=2 sts=2 sw=2:
