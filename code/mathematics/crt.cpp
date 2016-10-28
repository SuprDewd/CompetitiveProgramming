#include "egcd.cpp"
ll crt(vector<ll> &as, vector<ll> &ns) {
  ll cnt = size(as), N = 1, x = 0, r, s, l;
  rep(i,0,cnt) N *= ns[i];
  rep(i,0,cnt) egcd(ns[i], l = N/ns[i], r, s), x += as[i]*s*l;
  return smod(x, N); }
pair<ll,ll> gcrt(vector<ll> &as, vector<ll> &ns) {
  map<ll,pair<ll,ll> > ms;
  rep(at,0,size(as)) {
    ll n = ns[at];
    for (ll i = 2; i*i <= n; i = i == 2 ? 3 : i + 2) {
      ll cur = 1;
      while (n % i == 0) n /= i, cur *= i;
      if (cur > 1 && cur > ms[i].first)
        ms[i] = make_pair(cur, as[at] % cur); }
    if (n > 1 && n > ms[n].first)
      ms[n] = make_pair(n, as[at] % n); }
  vector<ll> as2, ns2; ll n = 1;
  iter(it,ms) {
    as2.push_back(it->second.second);
    ns2.push_back(it->second.first);
    n *= it->second.first; }
  ll x = crt(as2,ns2);
  rep(i,0,size(as)) if (smod(x,ns[i]) != smod(as[i],ns[i]))
      return ii(0,0);
  return make_pair(x,n); }
// vim: cc=60 ts=2 sts=2 sw=2:
