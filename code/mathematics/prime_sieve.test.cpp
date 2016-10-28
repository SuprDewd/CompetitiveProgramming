void assert_deep_equal(vector<int> expected, vector<int> actual) {
  assert_equal(size(expected), size(actual));
  for (int i = 0; i < size(expected); i++) {
    assert_equal(expected[i], actual[i]);
  }
}

void test() {
  vector<int> res, empty;
  res = prime_sieve(1);
  assert_deep_equal(empty, res);
  res = prime_sieve(2);
  empty.push_back(2);
  assert_deep_equal(empty, res);
  res = prime_sieve(3);
  empty.push_back(3);
  assert_deep_equal(empty, res);
  res = prime_sieve(4);
  assert_deep_equal(empty, res);
  res = prime_sieve(5);
  empty.push_back(5);
  assert_deep_equal(empty, res);
  res = prime_sieve(32);
  empty.push_back(7);
  empty.push_back(11);
  empty.push_back(13);
  empty.push_back(17);
  empty.push_back(19);
  empty.push_back(23);
  empty.push_back(29);
  empty.push_back(31);
  assert_deep_equal(empty, res);
}
// vim: cc=60 ts=2 sts=2 sw=2:
