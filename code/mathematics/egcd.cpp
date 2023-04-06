template <class T>
T egcd(T a, T b, T& x, T& y) {
  if (b == 0) { x = 1; y = 0; return a; }
  T d = egcd(b, a % b, x, y);
  x -= a / b * y; swap(x, y); return d; }
// vim: cc=60 ts=2 sts=2 sw=2:
