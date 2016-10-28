void assert_nearly_equal(double a, double b) {
  assert_true(abs(a - b) < EPS);
}

void assert_equal(point a, point b) {
  assert_nearly_equal(real(a), real(b));
  assert_nearly_equal(imag(a), imag(b));
}

void test() {

  point res1, res2;
  // Circle circle intersection
  assert_equal(intersect(point(0,0), 2, point(3,0), 2, res1, res2), 2);
  assert_equal(intersect(point(0,0), 2, point(3,2), 2, res1, res2), 2);
  assert_equal(intersect(point(0,0), 2, point(2,3), 2, res1, res2), 2);
  assert_equal(intersect(point(0,0), 2, point(0,3), 2, res1, res2), 2);
  assert_equal(intersect(point(0,0), 2, point(-2,3), 2, res1, res2), 2);
  assert_equal(intersect(point(0,0), 2, point(-3,2), 2, res1, res2), 2);
  assert_equal(intersect(point(0,0), 2, point(-3,0), 2, res1, res2), 2);
  assert_equal(intersect(point(0,0), 2, point(-3,-2), 2, res1, res2), 2);
  assert_equal(intersect(point(0,0), 2, point(-2,-3), 2, res1, res2), 2);
  assert_equal(intersect(point(0,0), 2, point(0,3), 2, res1, res2), 2);

  assert_equal(intersect(point(0,0), 2, point(-3,2), 2, res1, res2), 2);
  assert_equal(intersect(point(0,0), 2, point(-2,3), 2, res1, res2), 2);
  assert_equal(intersect(point(0,0), 2, point(3,0), 2, res1, res2), 2);

  assert_equal(intersect(point(1000,0), 2, point(1003,0), 2, res1, res2), 2);
  assert_equal(intersect(point(0,1000), 2, point(3,1002), 2, res1, res2), 2);
  assert_equal(intersect(point(0,100000), 2, point(2,100003), 2, res1, res2), 2);
  assert_equal(intersect(point(-1000,0), 2, point(-1000,3), 2, res1, res2), 2);
  assert_equal(intersect(point(0,-1000), 2, point(-2,-1003), 2, res1, res2), 2);
  assert_equal(intersect(point(0,0), 2, point(-3,2), 2, res1, res2), 2);

  assert_equal(intersect(point(0,0), 1, point(2,0), 1, res1, res2), 1);
  assert_equal(intersect(point(0,0), 1, point(-2,0), 1, res1, res2), 1);

  assert_equal(intersect(point(0,0), 1, point(4,0), 1, res1, res2), 0);
  assert_equal(intersect(point(0,0), 1, point(-2.3048,10034), 1, res1, res2), 0);
  assert_equal(intersect(point(0,0), 1, point(-823.847,2.7872), 1, res1, res2), 0);
  assert_equal(intersect(point(0,0), 1, point(-972.66283,0), 1, res1, res2), 0);
  assert_equal(intersect(point(0,0), 1, point(-20973249,2938490.02983942), 1, res1, res2), 0);

  // Circle line intersection
  // Field testing: Kattis redgem, Kattis garden
  assert_equal(2, intersect(point(-5,0), point(5,0), point(0,0), 3, res1, res2));
  assert_equal(2, intersect(point(0,-5), point(0,5), point(0,0), 3, res1, res2));

  assert_equal(0, intersect(point(-5,0), point(5,0), point(0,5), 3, res1, res2));
  assert_equal(0, intersect(point(0,-5), point(0,5), point(5,0), 3, res1, res2));

  assert_equal(1, intersect(point(-5,0), point(5,0), point(0,3), 3, res1, res2));
  assert_equal(1, intersect(point(0,-5), point(0,5), point(3, -3234.234), 3, res1, res2));

  intersect(point(1.67, 0), point(3.8, -1.6), point(0,0), 10.0, res1, res2);
  assert(abs(point(8.56, -5.17) - res1) < 0.1);
  assert(abs(point(-7.36, 6.77) - res2) < 0.1);

  intersect(point(3.8, -1.6), point(1.67, 0), point(0,0), 10.0, res1, res2);
  assert(abs(point(8.56, -5.17) - res2) < 0.1);
  assert(abs(point(-7.36, 6.77) - res1) < 0.1);

  // Point circle tangent
  // Field testing: Kattis redgem, Kattis tomosynthesis
  point M, N;
  assert_equal(2, tangent(point(0,2), point(2,0), 2.0, M, N));
  assert_equal(N, point(0,0));
  assert_equal(M, point(2,2));
  assert_equal(1, tangent(point(0,0), point(2,0), 2.0, M, N));
  assert_equal(0, tangent(point(3.4142135,1.4142135), point(2,0), 2.0, M, N));

  // Circle circle tangent
  pair<point, point> res3, res4;
  tangent_outer(point(0,1), 1.0, point(8,1), 1.0, res3, res4);
  assert_equal(res3.first, point(0.0,2.0));
  assert_equal(res3.second, point(8.0,2.0));
  assert_equal(res4.first, point(0.0,0.0));
  assert_equal(res4.second, point(8.0,0.0));

  tangent_outer(point(0,1), 1.0, point(8,4), 4.0, res3, res4);
  assert_equal(res4.first, point(0.0,0.0));
  assert_equal(res4.second, point(8.0,0.0));
}
// vim: cc=60 ts=2 sts=2 sw=2:
