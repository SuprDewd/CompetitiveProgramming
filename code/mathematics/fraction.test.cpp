void test() {
  fraction<int> a(3, 4), b(2, 10);
  assert_equal(3, a.n);
  assert_equal(4, a.d);
  assert_equal(1, b.n);
  assert_equal(5, b.d);

  fraction<int> c = a + b;
  assert_equal(19, c.n);
  assert_equal(20, c.d);

  c = a - b;
  assert_equal(11, c.n);
  assert_equal(20, c.d);

  c = b - a;
  assert_equal(-11, c.n);
  assert_equal(20, c.d);

  c = a * b;
  assert_equal(3, c.n);
  assert_equal(20, c.d);

  c = a / b;
  assert_equal(15, c.n);
  assert_equal(4, c.d);

  c = b / a;
  assert_equal(4, c.n);
  assert_equal(15, c.d);

  assert_true(a == a);
  assert_true(b == b);
  assert_false(a != a);
  assert_false(b != b);
  assert_true(a != b);
  assert_false(a == b);
  assert_true(b != a);
  assert_false(b == a);
  assert_false(a <= b);
  assert_false(a < b);
  assert_true(a > b);
  assert_true(a >= b);
  assert_true(b <= a);
  assert_true(b < a);
  assert_false(b > a);
  assert_false(b >= a);
}
// vim: cc=60 ts=2 sts=2 sw=2:
