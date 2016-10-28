#include "prime_sieve.cpp"
unordered_map<ll,ll> primepi(ll n) {
#define f(n) (1)
#define F(n) (n)
  ll st = 1, *dp[3], k = 0;
  while (st*st < n) st++;
  vi ps = prime_sieve(st);
  ps.push_back(st+1);
  rep(i,0,3) dp[i] = new ll[2*st];
  ll *pre = new ll[size(ps)-1];
  rep(i,0,size(ps)-1)
    pre[i] = f(ps[i]) + (i == 0 ? f(1) : pre[i-1]);
#define L(i) ((i)<st?(i)+1:n/(2*st-(i)))
#define I(l) ((l)<st?(l)-1:2*st-n/(l))
  rep(i,0,2*st) {
    ll cur = L(i);
    while ((ll)ps[k]*ps[k] <= cur) k++;
    dp[2][i] = k, dp[1][i] = F(L(i)), dp[0][i] = 0; }
  for (int j = 0, start = 0; start < 2*st; j++) {
    rep(i,start,2*st) {
      if (j >= dp[2][i]) { start++; continue; }
      ll s = j == 0 ? f(1) : pre[j-1];
      int l = I(L(i)/ps[j]);
      dp[j&1][i] = dp[~j&1][i]
        - f(ps[j]) * (dp[~min(j,(int)dp[2][l])&1][l] - s);
    } }
  unordered_map<ll,ll> res;
  rep(i,0,2*st) res[L(i)] = dp[~dp[2][i]&1][i]-f(1);
  delete[] pre; rep(i,0,3) delete[] dp[i];
  return res; }
// vim: cc=60 ts=2 sts=2 sw=2:
