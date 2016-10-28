int snoob(int x) {
  int y = x & -x, z = x + y;
  return z | ((x ^ z) >> 2) / y; }
// vim: cc=60 ts=2 sts=2 sw=2:
