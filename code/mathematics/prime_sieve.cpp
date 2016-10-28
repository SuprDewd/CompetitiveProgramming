vi prime_sieve(int n) {
  int mx = (n - 3) >> 1, sq, v, i = -1;
  vi primes;
  bool* prime = new bool[mx + 1];
  memset(prime, 1, mx + 1);
  if (n >= 2) primes.push_back(2);
  while (++i <= mx) if (prime[i]) {
    primes.push_back(v = (i << 1) + 3);
    if ((sq = i * ((i << 1) + 6) + 3) > mx) break;
    for (int j = sq; j <= mx; j += v) prime[j] = false; }
  while (++i <= mx)
    if (prime[i]) primes.push_back((i << 1) + 3);
  delete[] prime; // can be used for O(1) lookup
  return primes; }
// vim: cc=60 ts=2 sts=2 sw=2:
