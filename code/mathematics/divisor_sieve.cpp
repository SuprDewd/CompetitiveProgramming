vi divisor_sieve(int n) {
  vi mnd(n+1, 2), ps;
  if (n >= 2) ps.push_back(2);
  mnd[0] = 0;
  for (int k = 1; k <= n; k += 2) mnd[k] = k;
  for (int k = 3; k <= n; k += 2) {
    if (mnd[k] == k) ps.push_back(k);
    rep(i,1,size(ps))
      if (ps[i] > mnd[k] || ps[i]*k > n) break;
      else mnd[ps[i]*k] = ps[i]; }
  return ps; }
// vim: cc=60 ts=2 sts=2 sw=2:
