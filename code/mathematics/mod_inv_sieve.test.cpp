#include "../code/mathematics/is_prime.cpp"
void test() {
  rep(it,0,300) {
    int p = rand() % 2000000000;
    while (!is_prime(p)) p++;
    int n = min(100000, p);
    vi inv = inv_sieve(n, p);
    rep(i,1,n) {
      // cout << n << " " << p << " " << i << " " << inv[i] << endl;
      assert((ll)i * inv[i] % p == 1);
    }
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
