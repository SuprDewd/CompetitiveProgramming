void test() {
  init_is_square();

  assert_true(is_square(0));
  assert_true(is_square(1));
  assert_false(is_square(2));
  assert_false(is_square(3));
  assert_true(is_square(4));

  rep(i,0,100000) {
    int n = rng() % 100000000;
    int st = sqrt(n);
    while (st*st > n) st--;
    while (st*st < n) st++;
    assert_equal(st*st == n, is_square(n), true);
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
