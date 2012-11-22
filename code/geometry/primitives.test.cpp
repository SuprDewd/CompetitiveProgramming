bool assert_nearly_equal(double a, double b) {
	assert_true(abs(a - b) < EPS);
}

bool assert_equal(vector2d a, vector2d b) {
	assert_nearly_equal(a.x, b.x);
	assert_nearly_equal(a.y, b.y);
}

bool assert_equal(point a, point b) {
	assert_nearly_equal(a.x, b.x);
	assert_nearly_equal(a.y, b.y);
}

void test() {
	/* Field testing: UVa10263 */

	point a, b, c;

	a = point(-2, -2); b = point(3, 3); c = point(5, 5);
	assert_true(collinearPoints(a, b, c));
	assert_true(collinearPoints(a, c, b));
	assert_true(collinearPoints(b, a, c));
	assert_true(collinearPoints(b, c, a));
	assert_true(collinearPoints(c, a, b));
	assert_true(collinearPoints(c, b, a));

	a = point(-2, 2); b = point(3, 3); c = point(5, 5);
	assert_false(collinearPoints(a, b, c));
	assert_false(collinearPoints(a, c, b));
	assert_false(collinearPoints(b, a, c));
	assert_false(collinearPoints(b, c, a));
	assert_false(collinearPoints(c, a, b));
	assert_false(collinearPoints(c, b, a));

	assert_equal(vector2d(-3, 3), vector2d(3, 3).rotate(pi / 2));
	assert_equal(vector2d(-3, -3), vector2d(3, 3).rotate(pi));
	assert_equal(vector2d(3, -3), vector2d(3, 3).rotate(pi + pi / 2));
	assert_equal(vector2d(3, 3), vector2d(3, 3).rotate(2 * pi));

	assert_equal(point(1, 1), closestPointOnLine(point(2, 2), point(3, 3), point(2, 0)));
	assert_equal(point(0.5, 0.5), closestPointOnLine(point(2, 2), point(3, 3), point(1, 0)));
	assert_equal(point(1, 1), closestPointOnLine(point(2, 2), point(3, 3), point(0, 2)));
	assert_equal(point(0.5, 0.5), closestPointOnLine(point(2, 2), point(3, 3), point(0, 1)));
	assert_equal(point(0, 0), closestPointOnLine(point(2, 2), point(3, 3), point(0, 0)));
	assert_equal(point(2, 2), closestPointOnLine(point(2, 2), point(3, 3), point(2, 2)));
	assert_equal(point(1, 1), closestPointOnLine(point(2, 2), point(3, 3), point(1, 1)));
	assert_equal(point(3, 3), closestPointOnLine(point(2, 2), point(3, 3), point(3, 3)));
	assert_equal(point(2.5, 2.5), closestPointOnLine(point(2, 2), point(3, 3), point(2.5, 2.5)));

	assert_equal(point(2.5, 2.5), closestPointOnLine(point(2, 2), point(3, 3), point(2.5, 2.5), true));
	assert_equal(point(2, 2), closestPointOnLine(point(2, 2), point(3, 3), point(2, 2), true));
	assert_equal(point(3, 3), closestPointOnLine(point(2, 2), point(3, 3), point(3, 3), true));
	assert_equal(point(2, 2), closestPointOnLine(point(2, 2), point(3, 3), point(1, 1), true));
	assert_equal(point(3, 3), closestPointOnLine(point(2, 2), point(3, 3), point(4, 4), true));
	assert_equal(point(3, 3), closestPointOnLine(point(2, 2), point(3, 3), point(50, 100), true));
	assert_equal(point(3, 3), closestPointOnLine(point(2, 2), point(3, 3), point(100, 50), true));
	assert_equal(point(2, 2), closestPointOnLine(point(2, 2), point(3, 3), point(-50, -100), true));
	assert_equal(point(2, 2), closestPointOnLine(point(2, 2), point(3, 3), point(-100, -50), true));

	vector<point> pts;
	pts.push_back(point(1, 1));
	pts.push_back(point(1, 4));
	pts.push_back(point(4, 4));
	pts.push_back(point(4, 1));

	assert_nearly_equal(-9.0, polygon_area_signed(pts));
	assert_nearly_equal(9.0, polygon_area(pts));

	reverse(all(pts));

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