struct mf_edge {
    int u, v, w;
    mf_edge* rev;
    mf_edge(int _u, int _v, int _w, mf_edge* _rev = NULL) {
        u = _u; v = _v; w = _w; rev = _rev;
    }
};

int max_flow(int n, int s, int t, vii* adj) {
    vector<mf_edge*>* g = new vector<mf_edge*>[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0, len = size(adj[i]); j < len; j++) {
            mf_edge *cur = new mf_edge(i, adj[i][j].first, adj[i][j].second),
                    *rev = new mf_edge(adj[i][j].first, i, 0, cur);
            cur->rev = rev;
            g[i].push_back(cur);
            g[adj[i][j].first].push_back(rev);
        }
    }
    int flow = 0;
    mf_edge** back = new mf_edge*[n];
    while (true) {
        for (int i = 0; i < n; i++) back[i] = NULL;
        queue<int> Q; Q.push(s);
        while (!Q.empty()) {
            int cur = Q.front(); Q.pop();
            if (cur == t) break;
            for (int i = 0, len = size(g[cur]); i < len; i++) {
                mf_edge* nxt = g[cur][i];
                if (nxt->v != s && nxt->w > 0 && back[nxt->v] == NULL) {
                    back[nxt->v] = nxt;
                    Q.push(nxt->v);
                }
            }
        }
        mf_edge* cure = back[t];
        if (cure == NULL) break;
        int cap = INF;
        while (true) {
            cap = min(cap, cure->w);
            if (cure->u == s) break;
            cure = back[cure->u];
        }
        assert(cap > 0 && cap < INF);
        cure = back[t];
        while (true) {
            cure->w -= cap;
            cure->rev->w += cap;
            if (cure->u == s) break;
            cure = back[cure->u];
        }
        flow += cap;
    }
    // instead of deleting g, we could also
    // use it to get info about the actual flow
    for (int i = 0; i < n; i++)
        for (int j = 0, len = size(g[i]); j < len; j++)
            delete g[i][j];
    delete[] g;
    delete[] back;
    return flow;
}
