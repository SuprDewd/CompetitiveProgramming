void test() {
  vector<pair<int, ii> > edges;

  edges.push_back(pair<int, ii>(4, ii(0, 1)));
  edges.push_back(pair<int, ii>(9, ii(0, 2)));
  edges.push_back(pair<int, ii>(21, ii(0, 3)));
  edges.push_back(pair<int, ii>(4, ii(1, 0)));
  edges.push_back(pair<int, ii>(8, ii(1, 2)));
  edges.push_back(pair<int, ii>(17, ii(1, 3)));
  edges.push_back(pair<int, ii>(9, ii(2, 0)));
  edges.push_back(pair<int, ii>(8, ii(2, 1)));
  edges.push_back(pair<int, ii>(16, ii(2, 3)));
  edges.push_back(pair<int, ii>(21, ii(3, 0)));
  edges.push_back(pair<int, ii>(17, ii(3, 1)));
  edges.push_back(pair<int, ii>(16, ii(3, 2)));

  vector<pair<int, ii> > res = mst(4, edges);
  int sum = 0;
  for (int i = 0; i < size(res); i++) sum += res[i].first;
  assert_equal(28, sum);
}
// vim: cc=60 ts=2 sts=2 sw=2:
