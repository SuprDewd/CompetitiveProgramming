/* Field testing: Kattis increasingsubsequence, longincsubseq, poklon */

map<int,int> mem;
int lis_dp(const vi &arr, int last) {
  if (mem.find(last) != mem.end())
    return mem[last];
  int res = 1;
  rep(i,0,last) {
    if (arr[i] < arr[last]) {
      res = max(res, 1 + lis_dp(arr, i));
    }
  }
  return mem[last] = res;
}

void check(int n) {
  vi arr(n);
  rep(i,0,n) arr[i] = rand() % 100;

  mem.clear();
  int mx = 0;
  rep(i,0,n) {
    mx = max(mx, lis_dp(arr, i));
  }

  vi res = lis(arr);
  assert_equal(mx, (int)res.size());
  rep(i,1,res.size()) {
    assert_true(arr[res[i-1]] < arr[res[i]]);
  }
}

void test() {
  check(0);
  check(1);
  rep(i,0,50) {
    check(20*i+4);
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
