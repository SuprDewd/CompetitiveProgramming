// Field testing: Kattis triangles

void assert_nearly_equal(double a, double b) {
  //printf("Expected: %.10f, but got %.10f\n", a, b);
  assert_true(abs(a - b) < EPS);
}

void assert_equal(point3d a, point3d b) {
  assert_nearly_equal(a.x, b.x);
  assert_nearly_equal(a.y, b.y);
  assert_nearly_equal(a.z, b.z);
}

void test() {
  point3d p;
  assert_equal(p, point3d(0,0,0));

  assert_equal(point3d(7,8,0) - point3d(2,4,-10), point3d(5, 4, 10));
  assert_equal(point3d(-2.0, -3.789, 17.0*pi/200.0) + point3d(344889.9, 0, exp(1.0)), point3d(344887.9, -3.789, 17.0*pi/200.0 + exp(1.0)));
  assert_equal(-point3d(-1.0, -2.0, 3.0), point3d(1.0, 2.0, -3.0));
  assert_equal(point3d(1.0, 2.0, 3.0)*2.0, point3d(2.0, 4.0, 6.0));
  assert_equal(point3d(1.0, pi, exp(1.0))*(log(100000)), point3d((log(100000)), pi*(log(100000)), exp(1.0)*(log(100000))));
  assert_equal(point3d(-1.0, -2.0, 3.0)/exp(2.0), point3d(-1.0/exp(2.0), -2.0/exp(2.0), 3.0/exp(2.0)));

  assert_equal(point3d(1, 2, 3)%point3d(2,3,4), 20.0);
  assert_equal(point3d(2, 7, -9) * point3d(4, -2, 8), point3d(38, -52, -32));
  assert_equal(point3d(0, 7.8023, -9) * point3d(4, -2.089, 8.098), point3d(44.3820254, -36.0, -31.2092));

  assert_equal(point3d(0,0,0).distTo(point3d(4, -7, 9)), point3d(4, -7, 9).length());
  assert_nearly_equal(point3d(0.09,3,2).distTo(point3d(4, -7, 9)), 12.817491954);

  assert_nearly_equal(point3d(exp(2.7), pi*2, -log(1000000.0)).normalize().length(), 1.0);
  assert_nearly_equal(point3d(exp(2.7), pi*2, -log(1000000.0)).normalize(7.93).length(), 7.93);
}
// vim: cc=60 ts=2 sts=2 sw=2:
