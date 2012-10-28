int nck(int n, int k) {
	if (n - k < k)
		k = n - k;

	int res = 1;
	for (int i = 1; i <= k; i++)
		res = res * (n - (k - i)) / i;

	return res;
}