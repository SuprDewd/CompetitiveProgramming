struct hasher { int b = 311, m; vi h, p;
  hasher(string s, int _m)
    : m(_m), h(size(s)+1), p(size(s)+1) {
    p[0] = 1; h[0] = 0;
    rep(i,0,size(s)) p[i+1] = (ll)p[i] * b % m;
    rep(i,0,size(s)) h[i+1] = ((ll)h[i] * b + s[i]) % m; }
  int hash(int l, int r) {
    return (h[r+1] + m - (ll)h[l] * p[r-l+1] % m) % m; } };
// vim: cc=60 ts=2 sts=2 sw=2:
