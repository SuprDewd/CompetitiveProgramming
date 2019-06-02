ll tmp[10000];
void mul(vector<ll> &a, vector<ll> &b,
         const vector<ll> &c, ll mod) {
  memset(tmp,0,sizeof(tmp));
  rep(i,0,a.size()) rep(j,0,b.size())
    tmp[i+j] = (tmp[i+j] + a[i] * b[j]) % mod;
  for (int i=(int)(a.size()+b.size())-2; i>=c.size(); i--)
    rep(j,0,c.size())
      tmp[i-j-1] = (tmp[i-j-1] + tmp[i]*c[j]) % mod;
  rep(i,0,a.size()) a[i] = i < c.size() ? tmp[i] : 0; }
ll nth_term(const vector<ll> &init, const vector<ll> &c,
            ll n, ll mod) {
  if (n < init.size()) return init[n];
  int l = max(2, (int)c.size());
  vector<ll> x(l), t(l); x[1]=t[0]=1;
  while (n) { if (n & 1) mul(t, x, c, mod);
    mul(x, x, c, mod); n >>= 1; }
  ll res = 0;
  rep(i,0,c.size()) res = (res + init[i] * t[i]) % mod;
  return res; }
// vim: cc=60 ts=2 sts=2 sw=2:
