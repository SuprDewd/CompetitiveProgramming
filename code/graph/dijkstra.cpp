int *dist, *dad;
struct cmp {
    bool operator()(int a, int b) { return dist[a] != dist[b] ? dist[a] < dist[b] : a < b; }
};

pair<int*, int*> dijkstra(int n, int s, vector<ii> *adj) {
    dist = new int[n];
    dad = new int[n];
    for (int i = 0; i < n; i++) dist[i] = INF, dad[i] = -1;
    set<int, cmp> pq;
    dist[s] = 0, pq.insert(s);
    while (!pq.empty()) {
        int cur = *pq.begin(); pq.erase(pq.begin());
        for (int i = 0, cnt = size(adj[cur]); i < cnt; i++) {
            int nxt = adj[cur][i].first, ndist = dist[cur] + adj[cur][i].second;
            if (ndist < dist[nxt]) dist[nxt] = ndist, dad[nxt] = cur, pq.insert(nxt);
        }
    }

    return pair<int*, int*>(dist, dad);
}
