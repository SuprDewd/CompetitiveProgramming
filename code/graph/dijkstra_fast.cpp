#define TSWP(x, y) tmp = x, x = y, y = tmp
#define SWP(a, b) TSWP(loc[heap[a]], loc[heap[b]]), TSWP(heap[a], heap[b])

pair<int*, int*> dijkstra_fast(int n, int s, vector<ii> *adj) {
    int *heap = new int[n],
        *loc = new int[n],
        *dist = new int[n],
        *parent = new int[n],
        tmp;

    for (int i = 0; i < n; i++) {
        heap[i] = i;
        loc[i] = i;
        dist[i] = INF;
        parent[i] = -1;
    }

    SWP(0, s), dist[s] = 0;
    for (int left = n; left > 0; ) {
        int cur = heap[0];
        if (dist[cur] == INF) break;
        SWP(0, left-1), left--;
        int at = 0;
        while (at < left) {
            int l = 2*at + 1, r = l + 1, nxt = -1, ad = dist[heap[at]];
            if (r >= left) {
                if (l < left && ad > dist[heap[l]]) nxt = l;
            } else {
                int ld = dist[heap[l]], rd = dist[heap[r]];
                if (ad > ld && ad > rd) nxt = ld <= rd ? l : r;
                else if (ad > ld) nxt = l;
                else if (ad > rd) nxt = r;
            }
            if (nxt != -1) SWP(at, nxt), at = nxt;
            else break;
        }

        for (int i = 0, cnt = size(adj[cur]); i < cnt; i++) {
            int nxt = adj[cur][i].first,
                ndist = dist[cur] + adj[cur][i].second;
            if (ndist < dist[nxt]) {
                dist[nxt] = ndist;
                parent[nxt] = cur;
                int at = loc[nxt];
                while (at > 0) {
                    int p = (at-1)/2;
                    if (dist[nxt] < dist[heap[p]]) SWP(at, p), at = p;
                    else break;
                }
            }
        }
    }

    delete[] heap;
    delete[] loc;
    return pair<int*, int*>(dist, parent);
}
