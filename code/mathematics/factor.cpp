#include "miller_rabin.cpp"
#include "pollard_rho.cpp"
template <class T>
map<T, T> factor(T n) {
  if (n == 1) return {};
  if (is_probable_prime(n, 20)) return { { n, 1 } };
  map<T, T> res;
  while (n % 2 == 0) ++res[2], n /= 2;
  for (T i = 3; i*i*i <= n; i+=2) {
    while (n % i == 0) ++res[i], n /= i;
  }
  if (is_probable_prime(n, 20)) {
    res[n] += 1;
    return res;
  }
  for (T seed_value : {2,3,5,7,11,13,1031}) {
    T a_factor = rho(n, seed_value);
    if (a_factor != 1) {
      ++res[a_factor];
      ++res[n / a_factor];
      return res;
    }
  }
  if (n != 1) ++res[n];
  return res;
}
// vim: cc=60 ts=2 sts=2 sw=2:
