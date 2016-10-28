void test() {
  init_is_square();

  rep(i,0,100000) {
    int n = rand() % 100000000;
    int st = sqrt(n);
    while (st*st > n) st--;
    while (st*st < n) st++;
    assert_equal(st*st == n, is_square(n));
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
