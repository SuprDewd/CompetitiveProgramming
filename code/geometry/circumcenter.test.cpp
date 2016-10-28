// Field testing: UVa 12395

void test() {
  for (int i = 0; i < 10000; i++) {
    point a(randint(-100, 100), randint(-100, 100)),
       b(randint(-100, 100), randint(-100, 100)),
       c(randint(-100, 100), randint(-100, 100));

    if (abs(cross(b - a, c - a) / 2.0) < EPS) {
      // illegal triangle
      continue;
    }

    point mid = circumcenter(a, b, c);

    double x = abs(mid - a);
    assert_almost_equal(x, abs(mid - b), 1e-9);
    assert_almost_equal(x, abs(mid - c), 1e-9);
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
