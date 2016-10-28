void test() {
  /* Field testing: UVa 978, UVa 1513, UVa 12049, Kattis turbo */

  int cnt = 10000,
    range = 1000;

  avl_tree<int> t1;
  set<int> t2;

  assert_equal(0, t1.size());

  for (int i = 0; i < cnt; i++) {
    int n = rand() % range;
    avl_tree<int>::node *p = t1.insert(n);
    assert_equal(n, p->item);
    t2.insert(n);
    assert_equal(size(t2), size(t1));

    int n1 = rand() % range;
    avl_tree<int>::node *b = t1.find(n1);
    if (b) assert_equal(n1, b->item);
    assert_equal(b == NULL, t2.find(n1) == t2.end());

    int n2 = rand() % range;
    t1.erase(n2);
    t2.erase(n2);
    assert_equal(size(t2), size(t1));
  }

  t1.clear();
  t2.clear();

  assert_equal(0, t1.size());

  for (int i = 0; i < cnt; i++) {
    int n = rand() % range;
    avl_tree<int>::node *p = t1.insert(n);
    assert_equal(n, p->item);
    t2.insert(n);
    assert_equal(size(t2), size(t1));

    int n1 = rand() % range;
    avl_tree<int>::node *b = t1.find(n1);
    if (b) assert_equal(n1, b->item);
    assert_equal(b == NULL, t2.find(n1) == t2.end());

    int n2 = rand() % range;
    t1.erase(n2);
    t2.erase(n2);
    assert_equal(size(t2), size(t1));
  }

  for (int i = 0; i < range; i++) {
    t1.erase(i);
    t2.erase(i);
    assert_equal(size(t2), size(t1));
  }

  assert_equal(0, t1.size());
}
// vim: cc=60 ts=2 sts=2 sw=2:
