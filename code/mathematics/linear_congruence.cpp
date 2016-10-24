#include "egcd.cpp"
pair<ll,ll> linear_congruence(ll a, ll b, ll n) {
    ll x, y, d = egcd(smod(a,n), n, x, y);
    if ((b = smod(b,n)) % d != 0) return ii(0,0);
    return make_pair(smod(b / d * x, n),n/d); }
