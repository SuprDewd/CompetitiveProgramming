#include "../code/mathematics/is_prime.cpp"
void test() {
  // Field testing: Project Euler 437
  rep(it,0,10000) {
    int n;
    while (true) {
      n = randint(2, 100000);
      if (is_prime(n)) {
        break;
      }
    }
    int a;
    while (true) {
      a = randint(1,n-1);
      if (legendre(a, n) == 1) {
        break;
      }
    }
    ll res = tonelli_shanks(a, n);
    assert_false(res == -1);
    assert_equal<ll>(a, (res*res)%n);
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
