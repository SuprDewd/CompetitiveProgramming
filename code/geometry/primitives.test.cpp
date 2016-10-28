void assert_nearly_equal(double a, double b) {
  assert_true(abs(a - b) < EPS);
}

void assert_equal(point a, point b) {
  assert_nearly_equal(real(a), real(b));
  assert_nearly_equal(imag(a), imag(b));
}

void test() {
  /* Field testing: UVa10263, Kattis segmentdistance */

  assert_equal(point(-3, 3), rotate(point(3, 3), pi / 2, point(0,0)));
  assert_equal(point(-3, 3), rotate(point(3, 3)));
  assert_equal(point(-3, -3), rotate(point(3, 3), pi, point(0,0)));
  assert_equal(point(3, -3), rotate(point(3, 3), pi + pi / 2, point(0,0)));
  assert_equal(point(3, 3), rotate(point(3, 3), 2 * pi, point(0,0)));

  // assert_equal(point(0.7071067811,0.7071067811), normalize(point(2,2)));
  assert_equal(point(cos(pi/4), sin(pi/4)), normalize(point(2,2)));
  assert_equal(point(0,0), normalize(point(0,0)));
  assert_equal(point(0,1), normalize(point(0,100)));
  assert_equal(point(1,0), normalize(point(100,0)));
  assert_equal(point(-1,0), normalize(point(-2,0)));
  assert_equal(point(0,-1), normalize(point(0,-2)));
  assert_equal(point(cos(pi/3), sin(pi/3)), normalize(point(cos(pi/3) * 2, sin(pi/3) * 2)));

  assert_equal(point(6.0/25, -8.0/25), proj(point(-3, 4), point(2, 1)));
}
// vim: cc=60 ts=2 sts=2 sw=2:
