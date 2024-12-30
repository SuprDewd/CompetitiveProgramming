string rand_string(int l, int h) {
  int len = uniform_int_distribution(l, h)(rng);
  stringstream ss;
  rep(i,0,len) {
    if (rng() % 2 == 0) {
      ss << static_cast<char>(rng() % 26 + 'a');
    } else {
      ss << static_cast<char>(rng() % 26 + 'A');
    }
  }
  return ss.str();
}

void test() {
  rep(it,0,8000) {
    string a = rand_string(1, 50),
        b = rand_string(1, 10000);
    size_t x = b.find(a);
    int ans = string_match(b, a);
    if (x == string::npos) {
      assert_equal(-1, ans);
    } else {
      assert_equal((int)x, ans);
    }
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
