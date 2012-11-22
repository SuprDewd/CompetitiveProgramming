double target;

double f1(double x) {
	return x * x - target;
}

double f2(double x) {
	return x * x - 5 - target;
}

void test() {
	target = 5;
	assert_true(abs(binary_search_continuous(0, 100, 1e-9, f1) - sqrt(5)) < 1e-9);
	target = 0;
	assert_true(abs(binary_search_continuous(0, 100, 1e-9, f2) - sqrt(5)) < 1e-9);
}