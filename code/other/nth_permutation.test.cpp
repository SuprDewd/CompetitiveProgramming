string toString(vector<int> p) {
  stringstream ss;
  for (int i = 0; i < size(p); i++) {
    if (i != 0) ss << ",";
    ss << p[i];
  }

  return ss.str();
}

void test() {
  assert_equal(string("0,1,2"), toString(nth_permutation(3, 0)));
  assert_equal(string("0,2,1"), toString(nth_permutation(3, 1)));
  assert_equal(string("1,0,2"), toString(nth_permutation(3, 2)));
  assert_equal(string("1,2,0"), toString(nth_permutation(3, 3)));
  assert_equal(string("2,0,1"), toString(nth_permutation(3, 4)));
  assert_equal(string("2,1,0"), toString(nth_permutation(3, 5)));

  vector<int> perm(9);
  for (int i = 0; i < 9; i++) perm[i] = i;
  for (int i = 0; i < 10000; i++) {
    assert_equal(toString(perm), toString(nth_permutation(9, i)));
    next_permutation(perm.begin(), perm.end());
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
