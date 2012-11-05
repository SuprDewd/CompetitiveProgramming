vector<int> prime_sieve(int n) {
	int mx = (n - 3) >> 1;
	vector<int> primes;
	bool* prime = new bool[mx + 1];
	memset(prime, 1, mx + 1);

	if (n >= 2)
		primes.push_back(2);

	int i = 0;
	for ( ; i <= mx; i++)
		if (prime[i]) {
			int v = (i << 1) + 3;
			primes.push_back(v);
			int sq = i * ((i << 1) + 6) + 3;
			if (sq > mx) break;
			for (int j = sq; j <= mx; j += v)
				prime[j] = false;
		}

	for (i++; i <= mx; i++)
		if (prime[i])
			primes.push_back((i << 1) + 3);

	delete[] prime; // can be used for O(1) lookup
	return primes;
}