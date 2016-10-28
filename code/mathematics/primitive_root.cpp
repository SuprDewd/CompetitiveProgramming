#include "mod_pow.cpp"
ll primitive_root(ll m) {
  vector<ll> div;
  for (ll i = 1; i*i <= m-1; i++) {
    if ((m-1) % i == 0) {
      if (i < m) div.push_back(i);
      if (m/i < m) div.push_back(m/i); } }
  rep(x,2,m) {
    bool ok = true;
    iter(it,div) if (mod_pow<ll>(x, *it, m) == 1) {
      ok = false; break; }
    if (ok) return x; }
  return -1; }
// vim: cc=60 ts=2 sts=2 sw=2:
