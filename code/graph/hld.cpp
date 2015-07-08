#include "../data-structures/segment_tree.cpp"
struct HLD {
    int n, curhead, curloc;
    vi sz, head, parent, loc;
    vvi below; segment_tree values;
    HLD(int _n) : n(_n), sz(n, 1), head(n), parent(n, -1), loc(n), below(n) {
        vi tmp(n, ID); values = segment_tree(tmp); }
    void add_edge(int u, int v) { below[parent[v] = u].push_back(v); }
    void update_cost(int u, int v, int c) {
        if (parent[v] == u) swap(u, v); assert(parent[u] == v);
        values.update(loc[u], c); }
    void csz(int u) { rep(i,0,size(below[u]))
            csz(below[u][i]), sz[u] += sz[below[u][i]]; }
    void part(int u) {
        head[u] = curhead; loc[u] = curloc++;
        int best = -1;
        rep(i,0,size(below[u]))
            if (best == -1 || sz[below[u][i]] > sz[best]) best = below[u][i];
        if (best != -1) part(best);
        rep(i,0,size(below[u]))
            if (below[u][i] != best) part(curhead = below[u][i]); }
    void build() { int u = curloc = 0;
        while (parent[u] != -1) u++;
        csz(u); part(curhead = u); }
    int lca(int u, int v) {
        vi uat, vat; int res = -1;
        while (u != -1) uat.push_back(u), u = parent[head[u]];
        while (v != -1) vat.push_back(v), v = parent[head[v]];
        u = size(uat) - 1, v = size(vat) - 1;
        while (u >= 0 && v >= 0 && head[uat[u]] == head[vat[v]])
            res = (loc[uat[u]] < loc[vat[v]] ? uat[u] : vat[v]), u--, v--;
        return res; }
    int query_upto(int u, int v) { int res = ID;
        while (head[u] != head[v])
            res = f(res, values.query(loc[head[u]], loc[u])),
            u = parent[head[u]];
        return f(res, values.query(loc[v] + 1, loc[u])); }
    int query(int u, int v) { int l = lca(u, v);
        return f(query_upto(u, l), query_upto(v, l)); } };
