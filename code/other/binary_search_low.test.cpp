int f1(int x) {
	return x / 3;
}

void test() {
	for (int i = -10; i <= 10; i++) {
		int res = binary_search_low(-40, 40, i, f1);
		assert_true(f1(res) == i);
		assert_true(f1(res - 1) != i);
	}
}