/* Field testing: POJ 3468 */

void test1() {
  fenwick_tree ft(20);

  for (int i = 0; i < 20; i++) {
    assert_equal(0, ft.rsq(i, i));
    ft.update(i, i);
    assert_equal(i, ft.rsq(i, i));
    ft.update(i, -i);
    assert_equal(0, ft.rsq(i, i));
  }

  ft.update(3, 1);
  for (int i = 0; i < 20; i++)
  {
    for (int j = i; j < 20; j++)
    {
      if (i <= 3 && 3 <= j)
      {
        assert_equal(1, ft.rsq(i, j));
      }
      else
      {
        assert_equal(0, ft.rsq(i, j));
      }
    }
  }

  ft.update(5, -2);
  assert_equal(-1, ft.rsq(1, 8));
  ft.update(4, 5);
  assert_equal(4, ft.rsq(1, 8));
  ft.update(0, 100);
  assert_equal(4, ft.rsq(1, 8));
  assert_equal(104, ft.rsq(0, 19));
  ft.update(19, -200);
  assert_equal(-96, ft.rsq(0, 19));
}

struct fake_fenwick_tree {
  vi arr;

  fake_fenwick_tree(int n) {
    arr.resize(n);
    fill(arr.begin(), arr.end(), 0);
  }

  void update(int i, int v) {
    arr[i] += v;
  }

  void update(int i, int j, int v) {
    for ( ; i <= j; i++) {
      arr[i] += v;
    }
  }

  int rsq(int i) {
    int sum = 0;
    for (int j = 0; j <= i; j++) {
      sum += arr[j];
    }

    return sum;
  }

  int rsq(int i, int j) {
    int sum = 0;
    for (int k = i; k <= j; k++) {
      sum += arr[k];
    }

    return sum;
  }
};

void test1_fake() {
  fake_fenwick_tree ft(20);

  for (int i = 0; i < 20; i++) {
    assert_equal(0, ft.rsq(i, i));
    ft.update(i, i);
    assert_equal(i, ft.rsq(i, i));
    ft.update(i, -i);
    assert_equal(0, ft.rsq(i, i));
  }

  ft.update(3, 1);
  for (int i = 0; i < 20; i++)
  {
    for (int j = i; j < 20; j++)
    {
      if (i <= 3 && 3 <= j)
      {
        assert_equal(1, ft.rsq(i, j));
      }
      else
      {
        assert_equal(0, ft.rsq(i, j));
      }
    }
  }

  ft.update(5, -2);
  assert_equal(-1, ft.rsq(1, 8));
  ft.update(4, 5);
  assert_equal(4, ft.rsq(1, 8));
  ft.update(0, 100);
  assert_equal(4, ft.rsq(1, 8));
  assert_equal(104, ft.rsq(0, 19));
  ft.update(19, -200);
  assert_equal(-96, ft.rsq(0, 19));
}

void test2() {
  int n = 5000;
  fenwick_tree_sq ft(n);
  fake_fenwick_tree fft(n);
  for (int i = 0; i < 100000; i++) {
    int op = randint(0, 4);
    if (op == 0) {
      int at = randint(0, n-1);
      assert_equal(range_query(ft, at, at), fft.rsq(at, at));
    } else if (op == 1) {
      int j = randint(0, n-1),
        k = randint(j, n-1);
      // assert_equal(ft.rsq(j, k), fft.rsq(j, k));
      assert_equal(range_query(ft, j, k), fft.rsq(j, k));
    } else if (op == 2) {
      int at = randint(0, n-1);
      assert_equal(range_query(ft, 0, at), fft.rsq(at));
    } else if (op == 3) {
      int j = randint(0, n-1),
        k = randint(j, n-1),
        v = randint(-1337, 1337);
      // ft.update(j, k, v);
      range_update(ft, j, k, v);
      fft.update(j, k, v);
    } else {
      int at = randint(0, n-1),
        upd = randint(-1337, 1337);
      range_update(ft, at, at, upd);
      // ft.update(at, upd);
      fft.update(at, upd);
    }
  }
}

void test() {
  test1();
  test2();
}
// vim: cc=60 ts=2 sts=2 sw=2:
