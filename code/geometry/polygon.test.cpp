void assert_nearly_equal(double a, double b) {
  assert_true(abs(a - b) < EPS);
}

void assert_equal(point a, point b) {
  assert_nearly_equal(real(a), real(b));
  assert_nearly_equal(imag(a), imag(b));
}

void test() {
  /* Field testing: Kattis pointinpolygon, UVa 11030, UVa 634  */

  polygon pts;
  pts.push_back(point(1, 1));
  pts.push_back(point(1, 4));
  pts.push_back(point(4, 4));
  pts.push_back(point(4, 1));

  assert_nearly_equal(-9.0, polygon_area_signed(pts));
  assert_nearly_equal(9.0, polygon_area(pts));

  reverse(pts.begin(), pts.end());

  assert_nearly_equal(9.0, polygon_area_signed(pts));
  assert_nearly_equal(9.0, polygon_area(pts));

  pts.clear();
  pts.push_back(point(1, 1));
  pts.push_back(point(1, 4));
  pts.push_back(point(2, 2));
  pts.push_back(point(4, 1));

  assert_nearly_equal(-3.0, polygon_area_signed(pts));
  assert_nearly_equal(3.0, polygon_area(pts));

}
// vim: cc=60 ts=2 sts=2 sw=2:
