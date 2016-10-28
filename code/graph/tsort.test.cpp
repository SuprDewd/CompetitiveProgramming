void test() {
  vvi graph(2);
  graph[0].push_back(1);
  bool has_error;
  vi res = tsort(2, graph, has_error);
  assert_false(has_error);
  assert_equal(0, res[0]);
  assert_equal(1, res[1]);

  vvi graph2(2);
  graph2[0].push_back(1);
  graph2[1].push_back(0);
  res = tsort(2, graph2, has_error);
  assert_true(has_error);

  vvi graph3(3);
  graph3[0].push_back(2);
  graph3[1].push_back(0);
  graph3[1].push_back(2);
  res = tsort(3, graph3, has_error);
  assert_false(has_error);
  assert_equal(1, res[0]);
  assert_equal(0, res[1]);
  assert_equal(2, res[2]);
}
// vim: cc=60 ts=2 sts=2 sw=2:
