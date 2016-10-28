#define N 10000000
ll sp[N];
unordered_map<ll,ll> mem;
ll sumphi(ll n) {
  if (n < N) return sp[n];
  if (mem.find(n) != mem.end()) return mem[n];
  ll ans = 0, done = 1;
  for (ll i = 2; i*i <= n; i++) ans += sumphi(n/i), done = i;
  for (ll i = 1; i*i <= n; i++)
    ans += sp[i] * (n/i - max(done, n/(i+1)));
  return mem[n] = n*(n+1)/2 - ans; }
void sieve() {
  for (int i = 1; i < N; i++) sp[i] = i;
  for (int i = 2; i < N; i++) {
    if (sp[i] == i) {
      sp[i] = i-1;
      for (int j = i+i; j < N; j += i) sp[j] -= sp[j] / i; }
    sp[i] += sp[i-1]; } }
// vim: cc=60 ts=2 sts=2 sw=2:
