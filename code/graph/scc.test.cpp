void test_1() {
  vvi adj(4);

  adj[0].push_back(1);
  adj[1].push_back(0);
  adj[1].push_back(2);
  adj[2].push_back(3);
  adj[3].push_back(2);

  pair<union_find, vi> res = scc(adj);
  union_find scc = res.first;
  vi dag = res.second;

  assert_equal(scc.find(0), scc.find(1));
  assert_equal(scc.find(2), scc.find(3));
  assert_not_equal(scc.find(0), scc.find(2));

  assert_equal(scc.find(2), scc.find(dag[0]));
  assert_equal(scc.find(0), scc.find(dag[1]));
}

void test_2() {
  vvi adj(2);

  adj[0].push_back(1);

  pair<union_find, vi> res = scc(adj);
  union_find scc = res.first;

  assert_not_equal(scc.find(0), scc.find(1));
}

void test_3() {
  vvi adj(5);

  adj[0].push_back(1);
  adj[1].push_back(2);
  adj[2].push_back(3);
  adj[3].push_back(4);
  adj[4].push_back(0);

  pair<union_find, vi> res = scc(adj);
  union_find scc = res.first;

  assert_equal(scc.find(0), scc.find(1));
  assert_equal(scc.find(2), scc.find(1));
  assert_equal(scc.find(2), scc.find(3));
  assert_equal(scc.find(4), scc.find(3));
}

void test_4() {
  vvi adj(5);

  adj[0].push_back(1);
  adj[1].push_back(2);
  adj[2].push_back(3);
  adj[3].push_back(4);

  pair<union_find, vi> res = scc(adj);
  union_find scc = res.first;

  assert_not_equal(scc.find(0), scc.find(1));
  assert_not_equal(scc.find(0), scc.find(2));
  assert_not_equal(scc.find(0), scc.find(3));
  assert_not_equal(scc.find(0), scc.find(4));
  assert_not_equal(scc.find(1), scc.find(2));
  assert_not_equal(scc.find(1), scc.find(3));
  assert_not_equal(scc.find(1), scc.find(4));
  assert_not_equal(scc.find(2), scc.find(3));
  assert_not_equal(scc.find(2), scc.find(4));
  assert_not_equal(scc.find(3), scc.find(4));
}

void test_5() {
  vvi adj(5);

  pair<union_find, vi> res = scc(adj);
  union_find scc = res.first;

  assert_not_equal(scc.find(0), scc.find(1));
  assert_not_equal(scc.find(0), scc.find(2));
  assert_not_equal(scc.find(0), scc.find(3));
  assert_not_equal(scc.find(0), scc.find(4));
  assert_not_equal(scc.find(1), scc.find(2));
  assert_not_equal(scc.find(1), scc.find(3));
  assert_not_equal(scc.find(1), scc.find(4));
  assert_not_equal(scc.find(2), scc.find(3));
  assert_not_equal(scc.find(2), scc.find(4));
  assert_not_equal(scc.find(3), scc.find(4));
}

void test_6() {
  vvi adj(2);

  for (int i = 0; i < 100; i++)
  {
    adj[0].push_back(0);
    adj[1].push_back(1);
  }

  pair<union_find, vi> res = scc(adj);
  union_find scc = res.first;

  assert_not_equal(scc.find(0), scc.find(1));
}

void test_7() {
  vvi adj(2);

  for (int i = 0; i < 100; i++)
  {
    adj[0].push_back(0);
    adj[1].push_back(1);
  }

  adj[0].push_back(1);

  pair<union_find, vi> res = scc(adj);
  union_find scc = res.first;

  assert_not_equal(scc.find(0), scc.find(1));
}

void test_8() {
  vvi adj(2);

  for (int i = 0; i < 100; i++)
  {
    adj[0].push_back(0);
    adj[1].push_back(1);
  }

  adj[1].push_back(0);

  pair<union_find, vi> res = scc(adj);
  union_find scc = res.first;

  assert_not_equal(scc.find(0), scc.find(1));
}

void test_9() {
  vvi adj(2);

  for (int i = 0; i < 100; i++)
  {
    adj[0].push_back(0);
    adj[1].push_back(1);
  }

  adj[0].push_back(1);
  adj[1].push_back(0);

  pair<union_find, vi> res = scc(adj);
  union_find scc = res.first;

  assert_equal(scc.find(0), scc.find(1));
}

void test_10() {
  vvi adj(4);

  adj[0].push_back(1);
  adj[1].push_back(0);
  adj[2].push_back(1);
  adj[2].push_back(3);
  adj[3].push_back(2);

  pair<union_find, vi> res = scc(adj);
  union_find scc = res.first;
  vi dag = res.second;

  assert_equal(scc.find(0), scc.find(1));
  assert_equal(scc.find(2), scc.find(3));
  assert_not_equal(scc.find(0), scc.find(2));

  assert_equal(scc.find(0), scc.find(dag[0]));
  assert_equal(scc.find(2), scc.find(dag[1]));
}

void test_11() {
  vvi adj(10);

  adj[0].push_back(8);
  adj[0].push_back(4);
  adj[1].push_back(9);
  adj[2].push_back(6);
  adj[3].push_back(6);
  adj[3].push_back(0);
  adj[3].push_back(5);
  adj[4].push_back(8);
  adj[5].push_back(4);
  adj[6].push_back(0);
  adj[6].push_back(7);
  adj[7].push_back(2);
  adj[8].push_back(5);

  pair<union_find, vi> res = scc(adj);
  union_find scc = res.first;
  vi dag = res.second;

  vi num(10);
  num[0] = 1;
  num[1] = 3;
  num[2] = 5;
  num[3] = 2;
  num[4] = 0;
  num[5] = 0;
  num[6] = 5;
  num[7] = 5;
  num[8] = 0;
  num[9] = 4;

  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      assert_equal(num[i] == num[j], scc.find(i) == scc.find(j));
    }
  }

  vi idx(10);
  for (int i = 0; i < size(dag); i++) {
    idx[scc.find(dag[i])] = i;
  }

  assert_true(idx[scc.find(4)] < idx[scc.find(0)]);
  assert_true(idx[scc.find(4)] < idx[scc.find(6)]);
  assert_true(idx[scc.find(4)] < idx[scc.find(3)]);
  assert_true(idx[scc.find(0)] < idx[scc.find(3)]);
  assert_true(idx[scc.find(0)] < idx[scc.find(6)]);
  assert_true(idx[scc.find(6)] < idx[scc.find(3)]);
  assert_true(idx[scc.find(9)] < idx[scc.find(1)]);
}

void test_12() {
  vvi adj(4);

  adj[0].push_back(2);
  adj[1].push_back(3);
  adj[2].push_back(0);
  adj[2].push_back(1);
  adj[3].push_back(0);
  adj[3].push_back(1);

  // adj[0].push_back(1);
  // adj[0].push_back(2);
  // adj[1].push_back(2);
  // adj[2].push_back(1);
  // adj[2].push_back(3);
  // adj[3].push_back(0);

  pair<union_find, vi> res = scc(adj);
  union_find scc = res.first;
  vi dag = res.second;

  assert_equal(scc.find(0), scc.find(1));
  assert_equal(scc.find(0), scc.find(2));
  assert_equal(scc.find(0), scc.find(3));
}

void test() {
  test_1();
  test_2();
  test_3();
  test_4();
  test_5();
  test_6();
  test_7();
  test_8();
  test_9();
  test_10();
  test_11();
  test_12();
}
// vim: cc=60 ts=2 sts=2 sw=2:
