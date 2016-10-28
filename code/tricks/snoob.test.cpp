void test() {
  /* Field testing: UVa 729 */

  assert_equal(66, snoob(65));
  assert_equal(68, snoob(66));
  assert_equal(72, snoob(68));
  assert_equal(80, snoob(72));
  assert_equal(96, snoob(80));
  assert_equal(129, snoob(96));
  assert_equal(13, snoob(11));
  assert_equal(14, snoob(13));
  assert_equal(19, snoob(14));
  assert_equal(1535, snoob(1023));
}
// vim: cc=60 ts=2 sts=2 sw=2:
