#include "dinic.cpp"

bool same[MAXV];
pair<vii, vvi> construct_gh_tree(flow_network &g) {
    int n = g.n, v;
    vii par(n, ii(0, 0)); vvi cap(n, vi(n, -1));
    for (int s = 1; s < n; s++) {
        int l = 0, r = 0;
        par[s].second = g.max_flow(s, par[s].first, false);
        memset(d, 0, n * sizeof(int));
        memset(same, 0, n * sizeof(int));
        d[q[r++] = s] = 1;
        while (l < r) {
            same[v = q[l++]] = true;
            for (int i = g.head[v]; i != -1; i = g.e[i].nxt)
                if (g.e[i].cap > 0 && d[g.e[i].v] == 0)
                    d[q[r++] = g.e[i].v] = 1;
        }
        for (int i = s + 1; i < n; i++)
            if (par[i].first == par[s].first && same[i]) par[i].first = s;
        g.reset();
    }
    for (int i = 0; i < n; i++) {
        int mn = INF, cur = i;
        while (true) {
            cap[cur][i] = mn;
            if (cur == 0) break;
            mn = min(mn, par[cur].second), cur = par[cur].first;
        }
    }
    return make_pair(par, cap);
}
int compute_max_flow(int s, int t, const pair<vii, vvi> &gh) {
    if (s == t) return 0;
    int cur = INF, at = s;
    while (gh.second[at][t] == -1)
        cur = min(cur, gh.first[at].second), at = gh.first[at].first;
    return min(cur, gh.second[at][t]);
}
