void tsort_dfs(int cur, char* color, const vvi& adj, stack<int>& res, bool& has_cycle) {
    color[cur] = 1;
    for (int i = 0; i < size(adj[cur]); i++) {
        int nxt = adj[cur][i];
        if (color[nxt] == 0)
            tsort_dfs(nxt, color, adj, res, has_cycle);
        else if (color[nxt] == 1)
            has_cycle = true;
        if (has_cycle) return;
    }
    color[cur] = 2;
    res.push(cur);
}

vi tsort(int n, vvi adj, bool& has_cycle) {
    has_cycle = false;
    stack<int> S;
    vi res;
    char* color = new char[n];
    memset(color, 0, n);
    for (int i = 0; i < n; i++) {
        if (!color[i]) {
            tsort_dfs(i, color, adj, S, has_cycle);
            if (has_cycle) return res;
        }
    }
    while (!S.empty()) res.push_back(S.top()), S.pop();
    return res;
}
