#define L 9000000
int mob[L], mer[L];
unordered_map<ll,ll> mem;
ll M(ll n) {
  if (n < L) return mer[n];
  if (mem.find(n) != mem.end()) return mem[n];
  ll ans = 0, done = 1;
  for (ll i = 2; i*i <= n; i++) ans += M(n/i), done = i;
  for (ll i = 1; i*i <= n; i++)
    ans += mer[i] * (n/i - max(done, n/(i+1)));
  return mem[n] = 1 - ans; }
void sieve() {
  for (int i = 1; i < L; i++) mer[i] = mob[i] = 1;
  for (int i = 2; i < L; i++) {
    if (mer[i]) {
      mob[i] = -1;
      for (int j = i+i; j < L; j += i)
        mer[j] = 0, mob[j] = (j/i)%i == 0 ? 0 : -mob[j/i]; }
    mer[i] = mob[i] + mer[i-1]; } }
// vim: cc=60 ts=2 sts=2 sw=2:
