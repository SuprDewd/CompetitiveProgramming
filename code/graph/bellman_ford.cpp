int* bellman_ford(int n, int s, vii* adj, bool& has_negative_cycle) {
    has_negative_cycle = false;
    int* dist = new int[n];
    rep(i,0,n) dist[i] = i == s ? 0 : INF;
    rep(i,0,n-1) rep(j,0,n) if (dist[j] != INF)
        rep(k,0,size(adj[j]))
            dist[adj[j][k].first] = min(dist[adj[j][k].first],
                    dist[j] + adj[j][k].second);
    rep(j,0,n) rep(k,0,size(adj[j]))
        if (dist[j] + adj[j][k].second < dist[adj[j][k].first])
            has_negative_cycle = true;
    return dist;
}
