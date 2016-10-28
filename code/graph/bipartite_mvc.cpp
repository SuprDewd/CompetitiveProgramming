#include "hopcroft_karp.cpp"
vector<bool> alt;
void dfs(bipartite_graph &g, int at) {
  alt[at] = true;
  iter(it,g.adj[at]) {
    alt[*it + g.N] = true;
    if (g.R[*it] != -1 && !alt[g.R[*it]]) dfs(g, g.R[*it]); } }
vi mvc_bipartite(bipartite_graph &g) {
  vi res; g.maximum_matching();
  alt.assign(g.N + g.M,false);
  rep(i,0,g.N) if (g.L[i] == -1) dfs(g, i);
  rep(i,0,g.N) if (!alt[i]) res.push_back(i);
  rep(i,0,g.M) if (alt[g.N + i]) res.push_back(g.N + i);
  return res; }
// vim: cc=60 ts=2 sts=2 sw=2:
