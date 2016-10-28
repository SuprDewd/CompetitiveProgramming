template <class T>
T mod_pow(T b, T e, T m) {
  T res = T(1);
  while (e) {
    if (e & T(1)) res = smod(res * b, m);
    b = smod(b * b, m), e >>= T(1); }
  return res; }
// vim: cc=60 ts=2 sts=2 sw=2:
