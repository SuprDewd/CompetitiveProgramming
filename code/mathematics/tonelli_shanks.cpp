#include "mod_pow.cpp"
ll legendre(ll a, ll p) {
  if (a % p == 0) return 0;
  if (p == 2) return 1;
  return mod_pow(a, (p-1)/2, p) == 1 ? 1 : -1; }
ll tonelli_shanks(ll n, ll p) {
  assert(legendre(n,p) == 1);
  if (p == 2) return 1;
  ll s = 0, q = p-1, z = 2;
  while (~q & 1) s++, q >>= 1;
  if (s == 1) return mod_pow(n, (p+1)/4, p);
  while (legendre(z,p) != -1) z++;
  ll c = mod_pow(z, q, p),
    r = mod_pow(n, (q+1)/2, p),
    t = mod_pow(n, q, p),
    m = s;
  while (t != 1) {
    ll i = 1, ts = (ll)t*t % p;
    while (ts != 1) i++, ts = ((ll)ts * ts) % p;
    ll b = mod_pow(c, 1LL<<(m-i-1), p);
    r = (ll)r * b % p;
    t = (ll)t * b % p * b % p;
    c = (ll)b * b % p;
    m = i; }
  return r; }
// vim: cc=60 ts=2 sts=2 sw=2:
