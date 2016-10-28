template <class T> struct fraction {
  T gcd(T a, T b) { return b == T(0) ? a : gcd(b, a % b); }
  T n, d;
  fraction(T n_=T(0), T d_=T(1)) {
    assert(d_ != 0);
    n = n_, d = d_;
    if (d < T(0)) n = -n, d = -d;
    T g = gcd(abs(n), abs(d));
    n /= g, d /= g; }
  fraction(const fraction<T>& other)
    : n(other.n), d(other.d) { }
  fraction<T> operator +(const fraction<T>& other) const {
    return fraction<T>(n * other.d + other.n * d,
                       d * other.d);}
  fraction<T> operator -(const fraction<T>& other) const {
    return fraction<T>(n * other.d - other.n * d,
                       d * other.d); }
  fraction<T> operator *(const fraction<T>& other) const {
    return fraction<T>(n * other.n, d * other.d); }
  fraction<T> operator /(const fraction<T>& other) const {
    return fraction<T>(n * other.d, d * other.n); }
  bool operator <(const fraction<T>& other) const {
    return n * other.d < other.n * d; }
  bool operator <=(const fraction<T>& other) const {
    return !(other < *this); }
  bool operator >(const fraction<T>& other) const {
    return other < *this; }
  bool operator >=(const fraction<T>& other) const {
    return !(*this < other); }
  bool operator ==(const fraction<T>& other) const {
    return n == other.n && d == other.d; }
  bool operator !=(const fraction<T>& other) const {
    return !(*this == other); } };
// vim: cc=60 ts=2 sts=2 sw=2:
