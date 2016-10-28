#include "../code/mathematics/gcd.cpp"

void test() {
  for (ll a = -20; a < 20; a++) {
    for (ll b = 2; b < 40; b++) {
      if (gcd(a, b) == 1) {
        assert_equal(1LL, smod((a * mod_inv(a, b)), b));
      } else {
        assert_equal(-1LL, mod_inv(a, b));
      }
    }
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
