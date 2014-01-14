bool assert_nearly_equal(double a, double b) {
    assert_true(abs(a - b) < EPS);
}

bool assert_equal(point a, point b) {
    assert_nearly_equal(real(a), real(b));
    assert_nearly_equal(imag(a), imag(b));
}

void test() {
    /* Field testing: UVa10263, Kattis segmentdistance */

    point a, b, c;

    a = point(-2, -2); b = point(3, 3); c = point(5, 5);
    assert_true(collinear(a, b, c));
    assert_true(collinear(a, c, b));
    assert_true(collinear(b, a, c));
    assert_true(collinear(b, c, a));
    assert_true(collinear(c, a, b));
    assert_true(collinear(c, b, a));

    a = point(-2, 2); b = point(3, 3); c = point(5, 5);
    assert_false(collinear(a, b, c));
    assert_false(collinear(a, c, b));
    assert_false(collinear(b, a, c));
    assert_false(collinear(b, c, a));
    assert_false(collinear(c, a, b));
    assert_false(collinear(c, b, a));

    assert_equal(point(-3, 3), rotate(point(3, 3), point(0,0), pi / 2));
    assert_equal(point(-3, -3), rotate(point(3, 3), point(0,0), pi));
    assert_equal(point(3, -3), rotate(point(3, 3), point(0,0), pi + pi / 2));
    assert_equal(point(3, 3), rotate(point(3, 3), point(0,0), 2 * pi));

    assert_equal(point(1, 1), closest_point(point(2, 2), point(3, 3), point(2, 0)));
    assert_equal(point(0.5, 0.5), closest_point(point(2, 2), point(3, 3), point(1, 0)));
    assert_equal(point(1, 1), closest_point(point(2, 2), point(3, 3), point(0, 2)));
    assert_equal(point(0.5, 0.5), closest_point(point(2, 2), point(3, 3), point(0, 1)));
    assert_equal(point(0, 0), closest_point(point(2, 2), point(3, 3), point(0, 0)));
    assert_equal(point(2, 2), closest_point(point(2, 2), point(3, 3), point(2, 2)));
    assert_equal(point(1, 1), closest_point(point(2, 2), point(3, 3), point(1, 1)));
    assert_equal(point(3, 3), closest_point(point(2, 2), point(3, 3), point(3, 3)));
    assert_equal(point(2.5, 2.5), closest_point(point(2, 2), point(3, 3), point(2.5, 2.5)));

    assert_equal(point(2.5, 2.5), closest_point(point(2, 2), point(3, 3), point(2.5, 2.5), true));
    assert_equal(point(2, 2), closest_point(point(2, 2), point(3, 3), point(2, 2), true));
    assert_equal(point(3, 3), closest_point(point(2, 2), point(3, 3), point(3, 3), true));
    assert_equal(point(2, 2), closest_point(point(2, 2), point(3, 3), point(1, 1), true));
    assert_equal(point(3, 3), closest_point(point(2, 2), point(3, 3), point(4, 4), true));
    assert_equal(point(3, 3), closest_point(point(2, 2), point(3, 3), point(50, 100), true));
    assert_equal(point(3, 3), closest_point(point(2, 2), point(3, 3), point(100, 50), true));
    assert_equal(point(2, 2), closest_point(point(2, 2), point(3, 3), point(-50, -100), true));
    assert_equal(point(2, 2), closest_point(point(2, 2), point(3, 3), point(-100, -50), true));

    assert_equal(point(6.0/25, -8.0/25), proj(point(-3, 4), point(2, 1)));

}
