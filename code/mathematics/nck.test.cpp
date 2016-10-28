void test() {
  assert_equal(1, nck(0, 0));
  assert_equal(1, nck(1, 0));
  assert_equal(1, nck(1, 1));
  assert_equal(2, nck(2, 1));
  assert_equal(45, nck(10, 8));
  assert_equal(462, nck(11, 5));
  rep(i,2,500) {
    bool ok = true;
    rep(j,2,i) if (i%j==0) ok = false;
    if (!ok) continue;
    assert_equal(1%i, nck(0, 0, i));
    assert_equal(1%i, nck(1, 0, i));
    assert_equal(1%i, nck(1, 1, i));
    assert_equal(2%i, nck(2, 1, i));
    assert_equal(45%i, nck(10, 8, i));
    assert_equal(462%i, nck(11, 5, i));
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
