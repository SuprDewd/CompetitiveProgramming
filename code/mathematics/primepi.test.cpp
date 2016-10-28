void test() {
  unordered_map<ll,ll> res;

  ll n = 10000000000LL;
  res = primepi(n);
  assert_equal(455052511LL, res[n]);
  assert_equal(50847534LL, res[n/10]);
  assert_equal(5761455LL, res[n/100]);
  assert_equal(1229LL, res[10000]);
  assert_equal(4LL, res[10]);
  assert_equal(0LL, res[1]);

  n = 12397441;
  res = primepi(n);
  assert_equal(812443LL, res[n]);
  assert_equal(425565LL, res[n/2]);
  assert_equal(291869LL, res[n/3]);
  assert_equal(1147LL, res[n/1337]);

  // ll n = 1000000000;
  // res = primepi(n);
  // assert_equal(24739512092254535LL, res[n]);
  // assert_equal(279209790387276LL, res[n/10]);
  // assert_equal(3203324994356LL, res[n/100]);
  // assert_equal(5736396LL, res[10000]);
  // assert_equal(17LL, res[10]);
  // assert_equal(0LL, res[1]);
}
// vim: cc=60 ts=2 sts=2 sw=2:
