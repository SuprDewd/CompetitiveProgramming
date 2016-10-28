int nck(int n, int k) {
  if (n < k) return 0;
  k = min(k, n - k);
  int res = 1;
  rep(i,1,k+1) res = res * (n - (k - i)) / i;
  return res; }
int nck(int n, int k, int p) {
  int res = 1;
  while (n || k) {
    res = nck(n % p, k % p) % p * res % p;
    n /= p, k /= p; }
  return res; }
// vim: cc=60 ts=2 sts=2 sw=2:
