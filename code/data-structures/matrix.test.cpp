void test() {
	matrix<int> A(2, 2);
	assert_equal(0, A(0, 0));
	assert_equal(0, A(1, 0));
	assert_equal(0, A(0, 1));
	assert_equal(0, A(1, 1));

	A(0, 0) = A(0, 1) = A(1, 0) = 1;
	assert_equal(1, A(0, 0));
	assert_equal(1, A(1, 0));
	assert_equal(1, A(0, 1));
	assert_equal(0, A(1, 1));

	A = A.pow(20);
	assert_equal(10946, A(0, 0));
	assert_equal(6765, A(1, 0));
	assert_equal(6765, A(0, 1));
	assert_equal(4181, A(1, 1));

	A = A * 5;
	assert_equal(10946 * 5, A(0, 0));
	assert_equal(6765 * 5, A(1, 0));
	assert_equal(6765 * 5, A(0, 1));
	assert_equal(4181 * 5, A(1, 1));

	A = A + A;
	assert_equal(10946 * 5 * 2, A(0, 0));
	assert_equal(6765 * 5 * 2, A(1, 0));
	assert_equal(6765 * 5 * 2, A(0, 1));
	assert_equal(4181 * 5 * 2, A(1, 1));

	A = A - A;
	assert_equal(0, A(0, 0));
	assert_equal(0, A(1, 0));
	assert_equal(0, A(0, 1));
	assert_equal(0, A(1, 1));

	matrix<int> B(1, 2);
	B(0, 0) = 1;
	B(0, 1) = 5;
	assert_equal(1, B.transpose()(0, 0));
	assert_equal(5, B.transpose()(1, 0));
}