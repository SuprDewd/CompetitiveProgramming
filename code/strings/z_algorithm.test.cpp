void test() {
  int* arr;

  arr = z_values("blablubli");
  assert_equal(9, arr[0]);
  assert_equal(0, arr[1]);
  assert_equal(0, arr[2]);
  assert_equal(2, arr[3]);
  assert_equal(0, arr[4]);
  assert_equal(0, arr[5]);
  assert_equal(2, arr[6]);
  assert_equal(0, arr[7]);
  assert_equal(0, arr[8]);

  delete[] arr;

  arr = z_values("aaa");

  assert_equal(3, arr[0]);
  assert_equal(2, arr[1]);
  assert_equal(1, arr[2]);

  delete[] arr;

  arr = z_values("bobobo");

  assert_equal(6, arr[0]);
  assert_equal(0, arr[1]);
  assert_equal(4, arr[2]);
  assert_equal(0, arr[3]);
  assert_equal(2, arr[4]);
  assert_equal(0, arr[5]);
}
// vim: cc=60 ts=2 sts=2 sw=2:
