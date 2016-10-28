void test() {
  ll x, y;

  assert_equal(3LL * 5, egcd(2 * 3 * 5 * 5 * 11, 3 * 5 * 13, x, y));
  assert_equal(-2LL, x);
  assert_equal(17LL, y);

  assert_equal(3LL * 5, egcd(2 * 3 * 5 * 5 * 11, 3 * 5 * 13 * 17, x, y));
  assert_equal(-2LL, x);
  assert_equal(1LL, y);

  assert_equal(3LL * 5, egcd(2 * 3 * 5 * 11, 3 * 5 * 13 * 17, x, y));
  assert_equal(-10LL, x);
  assert_equal(1LL, y);

  assert_equal(3LL * 5, egcd(3 * 5 * 11, 3 * 5 * 13 * 17, x, y));
  assert_equal(-20LL, x);
  assert_equal(1LL, y);

  assert_equal(3LL * 5, egcd(3 * 5 * 11, 3 * 3 * 5 * 13 * 17, x, y));
  assert_equal(-241LL, x);
  assert_equal(4LL, y);

  assert_equal(3LL * 3 * 5, egcd(3 * 3 * 5 * 11, 3 * 3 * 5 * 13 * 17, x, y));
  assert_equal(-20LL, x);
  assert_equal(1LL, y);

  // assert_equal(3 * 3 * 5, egcd(-1 * 3 * 3 * 5 * 11, 3 * 3 * 5 * 13 * 17, x, y));
  // assert_equal(20, x);
  // assert_equal(1, y);

  // assert_equal(3 * 3 * 5, egcd(3 * 3 * 5 * 11, -1 * 3 * 3 * 5 * 13 * 17, x, y));
  // assert_equal(-20, x);
  // assert_equal(-1, y);

  // assert_equal(-1 * 3 * 3 * 5, egcd(-1 * 3 * 3 * 5 * 11, -1 * 3 * 3 * 5 * 13 * 17, x, y));
  // assert_equal(20, x);
  // assert_equal(-1, y);

  assert_equal(1LL, egcd(3424, 23423, x, y));
  assert_equal(1977LL, x);
  assert_equal(-289LL, y);

  for (ll a = 0; a < 20; a++)
    for (ll b = 0; b < 20; b++) {
      assert_equal(egcd(a, b, x, y), egcd(b, a, x, y));
      assert_equal(egcd(a, b, x, y), a * x + b * y);
    }

  for (ll a = 0; a < 100; a++) {
    assert_equal(a, egcd(a, a, x, y));
    assert_equal(1LL, egcd(1, a, x, y));
    assert_equal(1LL, egcd(a, 1, x, y));
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
