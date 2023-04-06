template <class T>
T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
// vim: cc=60 ts=2 sts=2 sw=2:
