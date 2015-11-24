void assert_nearly_equal(double a, double b) {
    assert_true(abs(a - b) < EPS);
}

void assert_equal(point a, point b) {
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
    assert_equal(2, intersect(point(-5,0), point(5,0), point(0,0), 3, res1, res2));
    assert_equal(2, intersect(point(0,-5), point(0,5), point(0,0), 3, res1, res2));

    assert_equal(0, intersect(point(-5,0), point(5,0), point(0,5), 3, res1, res2));
    assert_equal(0, intersect(point(0,-5), point(0,5), point(5,0), 3, res1, res2));

    assert_equal(1, intersect(point(-5,0), point(5,0), point(0,3), 3, res1, res2));
    assert_equal(1, intersect(point(0,-5), point(0,5), point(3, -3234.234), 3, res1, res2));

    // Point circle tangent
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
