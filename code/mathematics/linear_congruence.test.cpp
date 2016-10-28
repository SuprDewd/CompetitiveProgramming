
pair<ll,ll> check(ll a, ll b, ll c) {
  pair<ll,ll> res = linear_congruence(a,b,c);
  vector<ll> x,y;
  if (res.second != 0) {
    rep(k,0,c / res.second) {
      y.push_back(smod(res.first + k * res.second, c));
    }
  }
  sort(y.begin(), y.end());
  rep(i,0,c) {
    if (smod(a*i,c) == smod(b,c)) {
      x.push_back(i);
    }
  }
  assert_true(x == y);
  return res;
}

void test() {
  check(3, 2, 6);
  check(5, 2, 6);
  check(4, 2, 6);
  check(12, 20, 28);
  check(12 - 28, 20 - 28, 28);

  rep(it,0,10000) {
    int a = randint(-1000,1000),
      b = randint(-1000,1000),
      c = randint(1,1000);
    check(a,b,c);
  }
}

// vim: cc=60 ts=2 sts=2 sw=2:
