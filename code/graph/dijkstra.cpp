int *dist, *dad;
struct cmp {
  bool operator()(int a, int b) {
    return dist[a] != dist[b] ? dist[a] < dist[b] : a < b; }
};
pair<int*, int*> dijkstra(int n, int s, vii *adj) {
  dist = new int[n];
  dad = new int[n];
  rep(i,0,n) dist[i] = INF, dad[i] = -1;
  set<int, cmp> pq;
  dist[s] = 0, pq.insert(s);
  while (!pq.empty()) {
    int cur = *pq.begin(); pq.erase(pq.begin());
    rep(i,0,size(adj[cur])) {
      int nxt = adj[cur][i].first,
        ndist = dist[cur] + adj[cur][i].second;
      if (ndist < dist[nxt]) pq.erase(nxt),
        dist[nxt] = ndist, dad[nxt] = cur, pq.insert(nxt);
    } }
  return pair<int*, int*>(dist, dad); }
// vim: cc=60 ts=2 sts=2 sw=2:
