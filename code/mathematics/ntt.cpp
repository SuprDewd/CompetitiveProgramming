#include "../mathematics/primitive_root.cpp"
int mod = 998244353, g = primitive_root(mod),
  ginv = mod_pow<ll>(g, mod-2, mod),
  inv2 = mod_pow<ll>(2, mod-2, mod);
#define MAXN (1<<22)
struct Num {
  int x;
  Num(ll _x=0) { x = (_x%mod+mod)%mod; }
  Num operator +(const Num &b) { return x + b.x; }
  Num operator -(const Num &b) const { return x - b.x; }
  Num operator *(const Num &b) const { return (ll)x * b.x; }
  Num operator /(const Num &b) const {
    return (ll)x * b.inv().x; }
  Num inv() const { return mod_pow<ll>((ll)x, mod-2, mod); }
  Num pow(int p) const { return mod_pow<ll>((ll)x, p, mod); }
} T1[MAXN], T2[MAXN];
void ntt(Num x[], int n, bool inv = false) {
  Num z = inv ? ginv : g;
  z = z.pow((mod - 1) / n);
  for (ll i = 0, j = 0; i < n; i++) {
    if (i < j) swap(x[i], x[j]);
    ll k = n>>1;
    while (1 <= k && k <= j) j -= k, k >>= 1;
    j += k; }
  for (int mx = 1, p = n/2; mx < n; mx <<= 1, p >>= 1) {
    Num wp = z.pow(p), w = 1;
    for (int k = 0; k < mx; k++, w = w*wp) {
      for (int i = k; i < n; i += mx << 1) {
        Num t = x[i + mx] * w;
        x[i + mx] = x[i] - t;
        x[i] = x[i] + t; } } }
  if (inv) {
    Num ni = Num(n).inv();
    rep(i,0,n) { x[i] = x[i] * ni; } } }
void inv(Num x[], Num y[], int l) {
  if (l == 1) { y[0] = x[0].inv(); return; }
  inv(x, y, l>>1);
  // NOTE: maybe l<<2 instead of l<<1
  rep(i,l>>1,l<<1) T1[i] = y[i] = 0;
  rep(i,0,l) T1[i] = x[i];
  ntt(T1, l<<1); ntt(y, l<<1);
  rep(i,0,l<<1) y[i] = y[i]*2 - T1[i] * y[i] * y[i];
  ntt(y, l<<1, true); }
void sqrt(Num x[], Num y[], int l) {
  if (l == 1) { assert(x[0].x == 1); y[0] = 1; return; }
  sqrt(x, y, l>>1);
  inv(y, T2, l>>1);
  rep(i,l>>1,l<<1) T1[i] = T2[i] = 0;
  rep(i,0,l) T1[i] = x[i];
  ntt(T2, l<<1); ntt(T1, l<<1);
  rep(i,0,l<<1) T2[i] = T1[i] * T2[i];
  ntt(T2, l<<1, true);
  rep(i,0,l) y[i] = (y[i] + T2[i]) * inv2; }
// vim: cc=60 ts=2 sts=2 sw=2:
