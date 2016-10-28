long long M;
void init_is_square() {
  rep(i,0,64) M |= 1ULL << (63-(i*i)%64); }
inline bool is_square(ll x) {
  if ((M << x) >= 0) return false;
  int c = __builtin_ctz(x);
  if (c & 1) return false;
  x >>= c;
  if ((x&7) - 1) return false;
  ll r = sqrt(x);
  return r*r == x; }
// vim: cc=60 ts=2 sts=2 sw=2:
