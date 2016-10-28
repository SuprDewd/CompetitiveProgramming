#include "../data-structures/union_find.cpp"
vector<pair<int, ii> > mst(int n,
    vector<pair<int, ii> > edges) {
  union_find uf(n);
  sort(edges.begin(), edges.end());
  vector<pair<int, ii> > res;
  rep(i,0,size(edges))
    if (uf.find(edges[i].second.first) !=
        uf.find(edges[i].second.second)) {
      res.push_back(edges[i]);
      uf.unite(edges[i].second.first,
               edges[i].second.second); }
  return res; }
// vim: cc=60 ts=2 sts=2 sw=2:
