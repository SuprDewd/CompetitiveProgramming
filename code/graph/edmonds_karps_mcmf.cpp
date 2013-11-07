struct mcmf_edge {
    int u, v, w, c;
    mcmf_edge* rev;
    mcmf_edge(int _u, int _v, int _w, int _c, mcmf_edge* _rev = NULL) {
        u = _u; v = _v; w = _w; c = _c; rev = _rev;
    }
};

ii min_cost_max_flow(int n, int s, int t, vector<pair<int, ii> >* adj) {
    vector<mcmf_edge*>* g = new vector<mcmf_edge*>[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < size(adj[i]); j++) {
            mcmf_edge *cur = new mcmf_edge(i, adj[i][j].first, adj[i][j].second.first, adj[i][j].second.second),
                      *rev = new mcmf_edge(adj[i][j].first, i, 0, -adj[i][j].second.second, cur);
            cur->rev = rev;
            g[i].push_back(cur);
            g[adj[i][j].first].push_back(rev);
        }
    }
    int flow = 0, cost = 0;
    mcmf_edge** back = new mcmf_edge*[n];
    int* dist = new int[n];
    while (true) {
        for (int i = 0; i < n; i++) back[i] = NULL, dist[i] = INF;
        dist[s] = 0;
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n; j++)
                if (dist[j] != INF)
                    for (int k = 0; k < size(g[j]); k++)
                        if (g[j][k]->w > 0 && dist[j] + g[j][k]->c < dist[g[j][k]->v]) {
                            dist[g[j][k]->v] = dist[j] + g[j][k]->c;
                            back[g[j][k]->v] = g[j][k];
                        }
        mcmf_edge* cure = back[t];
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
            cost += cap * cure->c;
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
        for (int j = 0; j < size(g[i]); j++)
            delete g[i][j];
    delete[] g;
    delete[] back;
    delete[] dist;
    return ii(flow, cost);
}
