int J(int n, int k) {
  if (n == 1) return 0;
  if (k == 1) return n-1;
  if (n < k) return (J(n-1,k)+k)%n;
  int np = n - n/k;
  return k*((J(np,k)+np-n%k%np)%np) / (k-1); }
// vim: cc=60 ts=2 sts=2 sw=2:
