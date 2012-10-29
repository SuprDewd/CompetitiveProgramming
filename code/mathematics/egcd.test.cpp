void test() {
	int x, y;

	assert_equal(3 * 5, egcd(2 * 3 * 5 * 5 * 11, 3 * 5 * 13, x, y));
	assert_equal(-2, x);
	assert_equal(17, y);

	assert_equal(3 * 5, egcd(2 * 3 * 5 * 5 * 11, 3 * 5 * 13 * 17, x, y));
	assert_equal(-2, x);
	assert_equal(1, y);

	assert_equal(3 * 5, egcd(2 * 3 * 5 * 11, 3 * 5 * 13 * 17, x, y));
	assert_equal(-10, x);
	assert_equal(1, y);

	assert_equal(3 * 5, egcd(3 * 5 * 11, 3 * 5 * 13 * 17, x, y));
	assert_equal(-20, x);
	assert_equal(1, y);

	assert_equal(3 * 5, egcd(3 * 5 * 11, 3 * 3 * 5 * 13 * 17, x, y));
	assert_equal(-241, x);
	assert_equal(4, y);

	assert_equal(3 * 3 * 5, egcd(3 * 3 * 5 * 11, 3 * 3 * 5 * 13 * 17, x, y));
	assert_equal(-20, x);
	assert_equal(1, y);

	assert_equal(3 * 3 * 5, egcd(-1 * 3 * 3 * 5 * 11, 3 * 3 * 5 * 13 * 17, x, y));
	assert_equal(20, x);
	assert_equal(1, y);

	assert_equal(3 * 3 * 5, egcd(3 * 3 * 5 * 11, -1 * 3 * 3 * 5 * 13 * 17, x, y));
	assert_equal(-20, x);
	assert_equal(-1, y);

	assert_equal(-1 * 3 * 3 * 5, egcd(-1 * 3 * 3 * 5 * 11, -1 * 3 * 3 * 5 * 13 * 17, x, y));
	assert_equal(20, x);
	assert_equal(-1, y);

	assert_equal(1, egcd(3424, 23423, x, y));
	assert_equal(1977, x);
	assert_equal(-289, y);

	for (int a = 0; a < 20; a++)
		for (int b = 0; b < 20; b++) {
			assert_equal(egcd(a, b, x, y), egcd(b, a, x, y));
			assert_equal(egcd(a, b, x, y), a * x + b * y);
		}

	for (int a = 0; a < 100; a++) {
		assert_equal(a, egcd(a, a, x, y));
		assert_equal(1, egcd(1, a, x, y));
		assert_equal(1, egcd(a, 1, x, y));
	}
}