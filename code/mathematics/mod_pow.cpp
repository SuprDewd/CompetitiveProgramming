int mod_pow(int b, int e, int m) {
	assert(e >= 0);
	assert(m > 0);
	int res = 1;
	while (e) {
		if (e & 1) res = mod(res * b, m);
		b = mod(b * b, m);
		e >>= 1;
	}

	return res;
}