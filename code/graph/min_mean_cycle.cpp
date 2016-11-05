double min_mean_cycle(vector<vector<pair<int,double>>> adj){
  int n = size(adj); double mn = INFINITY;
  vector<vector<double> > arr(n+1, vector<double>(n, mn));
  arr[0][0] = 0;
  rep(k,1,n+1) rep(j,0,n) iter(it,adj[j])
    arr[k][it->first] = min(arr[k][it->first],
                            it->second + arr[k-1][j]);
  rep(k,0,n) {
    double mx = -INFINITY;
    rep(i,0,n) mx = max(mx, (arr[n][i]-arr[k][i])/(n-k));
    mn = min(mn, mx); }
  return mn; }
// vim: cc=60 ts=2 sts=2 sw=2:
