#define MAXN 5000
int low[MAXN], num[MAXN], curnum;
void dfs(const vvi &adj, vi &cp, vii &bri, int u, int p) {
    low[u] = num[u] = curnum++;
    int cnt = 0; bool found = false;
    for (int i = 0; i < size(adj[u]); i++) {
        int v = adj[u][i];
        if (num[v] == -1) {
            dfs(adj, cp, bri, v, u);
            low[u] = min(low[u], low[v]);
            cnt++;
            found = found || low[v] >= num[u];
            if (low[v] > num[u]) bri.push_back(ii(u, v));
        } else if (p != v) low[u] = min(low[u], num[v]); }
    if (found && (p != -1 || cnt > 1)) cp.push_back(u); }
pair<vi,vii> cut_points_and_bridges(const vvi &adj) {
    int n = size(adj);
    vi cp; vii bri;
    memset(num, -1, n << 2);
    curnum = 0;
    for (int i = 0; i < n; i++) if (num[i] == -1) dfs(adj, cp, bri, i, -1);
    return make_pair(cp, bri); }
