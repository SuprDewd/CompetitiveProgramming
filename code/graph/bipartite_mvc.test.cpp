/* Field testing: Kattis sensor */
void test() {
  rep(ite,0,10000) {
    int n = rand() % 400 + 1,
      m = rand() % 400 + 1;
    int k = rand() % n + 1;
    vii es;
    rep(i,0,n) {
      rep(j,0,m) {
        if (rand() % k == 0) {
          es.push_back(ii(i,j));
        }
      }
    }
    bipartite_graph g(n,m);
    iter(it,es) {
      g.add_edge(it->first, it->second);
    }
    int sz = g.maximum_matching();
    vector<int> res = mvc_bipartite(g);
    set<int> cover;
    iter(it,res) cover.insert(*it);
    assert(size(res) == sz);
    int LEFT = 0,
      RIGHT = n;
    rep(i,0,size(es)) {
      int a = LEFT + es[i].first,
        b = RIGHT + es[i].second;
      assert(cover.find(a) != cover.end() ||
          cover.find(b) != cover.end());
    }
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
