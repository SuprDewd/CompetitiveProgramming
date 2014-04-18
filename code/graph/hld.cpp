struct HLD {
    int n;
    vi sz;
    vvi below;

    vi head, parent, loc;
    int curhead, curloc;

    HLD(int _n) : n(_n), sz(n, 1), below(n), head(n), parent(n, -1), loc(n) { }

    void add_edge(int u, int v) {
        below[u].push_back(v);
        parent[v] = u;
    }

    void csz(int u) {
        for (int i = 0; i < size(below[u]); i++)
            csz(below[u][i]), sz[u] += sz[below[u][i]];
    }

    void part(int u) {
        head[u] = curhead;
        loc[u] = curloc++;

        int best = -1;
        for (int i = 0; i < size(below[u]); i++)
            if (best == -1 || sz[below[u][i]] > sz[best])
                best = below[u][i];

        if (best != -1)
            part(best);

        for (int i = 0; i < size(below[u]); i++)
            if (below[u][i] != best)
                part(curhead = below[u][i]);
    }

    void build() {
        int u = curloc = 0;
        while (parent[u] != -1) u++;
        csz(u);
        part(curhead = u);
    }

    int lca(int u, int v) {
        vi uat, vat;
        while (u != -1) uat.push_back(u), u = parent[head[u]];
        while (v != -1) vat.push_back(v), v = parent[head[v]];
        u = size(uat) - 1, v = size(vat) - 1;
        int res = -1;
        while (u >= 0 && v >= 0 && head[uat[u]] == head[vat[v]])
            res = (loc[uat[u]] < loc[vat[v]] ? uat[u] : vat[v]), u--, v--;
        return res;
    }
};
