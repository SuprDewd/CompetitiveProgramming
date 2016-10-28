struct segment_tree_slow {
  vector<ll> arr;
  segment_tree_slow(vector<ll> _arr) : arr(_arr) { }
  ll query(int a, int b) {
    ll s = 0;
    for (int i = a; i <= b; i++) s += arr[i];
    return s;
  }
  void update(int i, ll v) {
    arr[i] = v;
  }

  void range_update(int a, int b, ll v) {
    for (int i = a; i <= b; i++) {
      arr[i] += v;
    }
  }
};

void test() {
  /* Field testing: SPOJ HORRIBLE */

  int n = 100000;
  vector<ll> arr(n);
  for (int i = 0; i < n; i++) {
    arr[i] = randint(-1000, 1000);
  }

  segment_tree x(arr);
  segment_tree_slow xslow(arr);

  for (int i = 0; i < 100000; i++) {
    int op = randint(0, 2);
    if (op == 0) {
      int a = randint(0, n-1),
        b = randint(0, n-1);
      if (a > b) swap(a,b);
      assert_equal(xslow.query(a, b), x.query(a, b).x);
    } else if (op == 1) {
      int idx = randint(0, n-1),
        val = randint(-1000, 1000);
      x.update(idx, val);
      xslow.update(idx, val);
    } else if (op == 2) {
      int a = randint(0, n-1),
        b = randint(0, n-1),
        v = randint(-1000, 1000);

      if (a > b) swap(a,b);

      x.range_update(a, b, v);
      xslow.range_update(a, b, v);
    }
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
