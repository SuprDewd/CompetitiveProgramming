int factorial(int n) {
	int res = 1;
	while (n) {
		res *= n--;
	}

	return res;
}

int nck(int n, int k) {
	return factorial(n) / factorial(k) / factorial(n - k);
}