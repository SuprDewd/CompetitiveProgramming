struct mf_edge {
    int u, v, w; mf_edge* rev;
    mf_edge(int _u, int _v, int _w, mf_edge* _rev = NULL) {
        u = _u; v = _v; w = _w; rev = _rev; } };
pair<int, vector<vector<mf_edge*> > > max_flow(int n, int s, int t, vii* adj) {
    int flow = 0, cur, cap;
    vector<vector<mf_edge*> > g(n);
    vector<mf_edge*> back(n);
    mf_edge *ce, *z;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < size(adj[i]); j++) {
            ce = new mf_edge(i, adj[i][j].first, adj[i][j].second);
            g[i].push_back(ce);
            ce->rev = new mf_edge(adj[i][j].first, i, 0, ce);
            g[ce->v].push_back(ce->rev); } }
    while (true) {
        back.assign(n, NULL);
        queue<int> Q; Q.push(s);
        while (!Q.empty() && (cur = Q.front()) != t) {
            Q.pop();
            for (int i = 0; i < size(g[cur]); i++) {
                mf_edge* nxt = g[cur][i];
                if (nxt->v != s && nxt->w > 0 && !back[nxt->v])
                    Q.push((back[nxt->v] = nxt)->v); } }
        if (!back[t] || back[t]->w == 0) break;
        for (int i = 0; i < size(g[t]); i++) {
            if (!(z = g[t][i]->rev) || (!back[z->u] && z->u != s)) continue;
            for (cap = z->w, ce = back[z->u]; ce && cap > 0; ce = back[ce->u])
                cap = min(cap, ce->w);
            if (cap == 0) continue;
            assert(cap < INF);
            z->w -= cap, z->rev->w += cap;
            for (ce = back[z->u]; ce; ce = back[ce->u])
                ce->w -= cap, ce->rev->w += cap;
            flow += cap; } }
    return make_pair(flow, g); }
