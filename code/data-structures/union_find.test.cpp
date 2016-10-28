void test() {
  const int n = 20;
  union_find uf(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        assert_equal(uf.find(i), uf.find(j));
      } else {
        assert_not_equal(uf.find(i), uf.find(j));
      }
    }
  }

  assert_true(uf.unite(3, 5));
  assert_equal(uf.find(3), uf.find(5));
  assert_not_equal(uf.find(3), uf.find(4));
  assert_not_equal(uf.find(3), uf.find(6));
  assert_not_equal(uf.find(3), uf.find(2));
  assert_not_equal(uf.find(5), uf.find(4));
  assert_not_equal(uf.find(5), uf.find(6));
  assert_not_equal(uf.find(5), uf.find(2));

  assert_true(uf.unite(11, 5));
  assert_equal(uf.find(3), uf.find(11));
  assert_equal(uf.find(5), uf.find(11));
  assert_equal(uf.find(3), uf.find(5));
  assert_not_equal(uf.find(3), uf.find(4));
  assert_not_equal(uf.find(3), uf.find(6));
  assert_not_equal(uf.find(3), uf.find(2));
  assert_not_equal(uf.find(5), uf.find(4));
  assert_not_equal(uf.find(5), uf.find(6));
  assert_not_equal(uf.find(5), uf.find(2));
  assert_not_equal(uf.find(11), uf.find(4));
  assert_not_equal(uf.find(11), uf.find(6));
  assert_not_equal(uf.find(11), uf.find(2));

  assert_false(uf.unite(11, 5));
  assert_equal(uf.find(3), uf.find(11));
  assert_equal(uf.find(5), uf.find(11));
  assert_equal(uf.find(3), uf.find(5));
  assert_not_equal(uf.find(3), uf.find(4));
  assert_not_equal(uf.find(3), uf.find(6));
  assert_not_equal(uf.find(3), uf.find(2));
  assert_not_equal(uf.find(5), uf.find(4));
  assert_not_equal(uf.find(5), uf.find(6));
  assert_not_equal(uf.find(5), uf.find(2));
  assert_not_equal(uf.find(11), uf.find(4));
  assert_not_equal(uf.find(11), uf.find(6));
  assert_not_equal(uf.find(11), uf.find(2));

  assert_false(uf.unite(5, 3));
  assert_false(uf.unite(3, 5));
  assert_false(uf.unite(5, 11));
  assert_false(uf.unite(3, 11));
}
// vim: cc=60 ts=2 sts=2 sw=2:
