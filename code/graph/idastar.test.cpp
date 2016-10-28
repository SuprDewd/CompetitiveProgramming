void test() {
  // Field testing: UVa 10181, UVa 11163

  n = 15;
  int tc[15] = {
    1, 3, 6, 9, 2, 14, 4, 13, 7, 11, 0, 12, 8, 5, 10
  };
  rep(i,0,n) cur[i] = tc[i];
  assert(idastar() == 52);
}
// vim: cc=60 ts=2 sts=2 sw=2:
