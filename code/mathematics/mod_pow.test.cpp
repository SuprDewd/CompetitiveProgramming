void test() {
  assert_equal(16, mod_pow(234, 2334, 23));
  assert_equal(400, mod_pow(42, 34, 2344));
  assert_equal(1, mod_pow(1, 34, 2344));
  assert_equal(0, mod_pow(1, 34, 1));
  assert_equal(1, mod_pow(-1, 34, 2344));
  assert_equal(2343, mod_pow(-1, 35, 2344));
  assert_equal(1425, mod_pow(-23, 34, 2344));
  assert_equal(41, mod_pow(-23, 35, 2344));
}
// vim: cc=60 ts=2 sts=2 sw=2:
