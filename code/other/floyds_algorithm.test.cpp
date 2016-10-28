int m;

int f1(int x) {
  if (x < 0) return x + 1;
  return (x + 1) % m;
}

void test() {
  for (int i = 0; i < 20; i++) {
    for (m = 1; m < 20; m++) {
      ii res = find_cycle(-i, f1);
      assert_equal(res.first, i);
      assert_equal(res.second, m);
    }
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
