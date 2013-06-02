#include "../data-structures/heap.cpp"

int *dist, *pre;
struct dist_cmp {
    dist_cmp() { }
    bool operator ()(const int &a, const int &b) {
        return dist[a] < dist[b];
    }
};

pair<int*, int*> dijkstra_fast(int n, int s, vector<ii> *adj) {
    dist = new int[n];
    pre = new int[n];
    heap<dist_cmp> H(n);
    for (int i = 0; i < n; i++) dist[i] = INF, pre[i] = -1, H.push(i, false);
    dist[s] = 0, H.heapify();
    while (!H.empty()) {
        int cur = H.top(); H.pop();
        if (dist[cur] == INF) break;
        for (int i = 0, cnt = size(adj[cur]); i < cnt; i++) {
            int nxt = adj[cur][i].first, ndist = dist[cur] + adj[cur][i].second;
            if (ndist < dist[nxt]) dist[nxt] = ndist, pre[nxt] = cur, H.update_key(nxt);
        }
    }

    return pair<int*, int*>(dist, pre);
}
