void test() {
  /*
   * Field testing:
   * - UVa 11356
   * - UVa 12019
   * - UVa 893 (had to use long long)
   * - Kattis booking
   **/

  int y, m, d;
  assert_equal(2451545, dateToInt(2000, 1, 1));
  intToDate(2451545, y, m, d);
  assert_equal(2000, y);
  assert_equal(1, m);
  assert_equal(1, d);

  for (int i = 1; i <= 31; i++) assert_equal((6 + i - 1) % 7, dateToInt(2012, 1, i) % 7);
  for (int i = 1; i <= 29; i++) assert_equal((2 + i - 1) % 7, dateToInt(2012, 2, i) % 7);

  for (int i = 1; i <= 31; i++) assert_equal((6 + i - 1) % 7, dateToInt(2908, 1, i) % 7);
  for (int i = 1; i <= 29; i++) assert_equal((2 + i - 1) % 7, dateToInt(2908, 2, i) % 7);

  for (int i = 1; i <= 30; i++) assert_equal((1 + i - 1) % 7, dateToInt(2320, 6, i) % 7);
  for (int i = 1; i <= 31; i++) assert_equal((2 + i - 1) % 7, dateToInt(2320, 12, i) % 7);

  intToDate(dateToInt(2320, 1, 1) + 4*7 + 9, y, m, d);
  assert_equal(2320, y);
  assert_equal(2, m);
  assert_equal(7, d);

  intToDate(dateToInt(2320, 1, 1) + 4*7 + 9 + 3*7 + 2, y, m, d);
  assert_equal(2320, y);
  assert_equal(3, m);
  assert_equal(1, d);
}
// vim: cc=60 ts=2 sts=2 sw=2:
