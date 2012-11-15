double f1(double x) {
	return x * x;
}

double f2(double x) {
	return x * x - 5;
}

void test() {
	assert_true(abs(binary_search(0, 100, 5, 1e-9, f1) - sqrt(5)) < 1e-9);
	assert_true(abs(binary_search(0, 100, 0, 1e-9, f2) - sqrt(5)) < 1e-9);
}