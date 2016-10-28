void test() {
  assert_equal(3LL * 5, gcd(2 * 3 * 5 * 5 * 11, 3 * 5 * 13));
  assert_equal(3LL * 5, gcd(2 * 3 * 5 * 5 * 11, 3 * 5 * 13 * 17));
  assert_equal(3LL * 5, gcd(2 * 3 * 5 * 11, 3 * 5 * 13 * 17));
  assert_equal(3LL * 5, gcd(3 * 5 * 11, 3 * 5 * 13 * 17));
  assert_equal(3LL * 5, gcd(3 * 5 * 11, 3 * 3 * 5 * 13 * 17));
  assert_equal(3LL * 3 * 5, gcd(3 * 3 * 5 * 11, 3 * 3 * 5 * 13 * 17));
  // assert_equal(3 * 3 * 5, gcd(-1 * 3 * 3 * 5 * 11, 3 * 3 * 5 * 13 * 17));
  // assert_equal(3 * 3 * 5, gcd(3 * 3 * 5 * 11, -1 * 3 * 3 * 5 * 13 * 17));
  // assert_equal(-1 * 3 * 3 * 5, gcd(-1 * 3 * 3 * 5 * 11, -1 * 3 * 3 * 5 * 13 * 17));

  for (ll a = 0; a < 20; a++)
    for (ll b = 0; b < 20; b++)
      assert_equal(gcd(a, b), gcd(b, a));

  for (ll a = 0; a < 100; a++) {
    assert_equal(a, gcd(a, a));
    assert_equal(1LL, gcd(1, a));
    assert_equal(1LL, gcd(a, 1));
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
