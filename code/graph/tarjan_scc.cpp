#include "../data-structures/unionfind.cpp"

stack<int> S;
int *num, *low, idx, v;
bool *visited;

void strongconnect(int u, vvi &adj, union_find &uf, vi &dag) {
    num[u] = low[u] = idx++;
    visited[u] = true, S.push(u);
    for (int i = 0, cnt = size(adj[u]); i < cnt; i++) {
        if (num[v = adj[u][i]] == -1) {
            strongconnect(v, adj, uf, dag);
            low[u] = min(low[u], low[v]);
        } else if (visited[v]) {
            low[u] = min(low[u], num[v]);
        }
    }

    if (num[u] != low[u]) return;
    do uf.unite(u, v = S.top()), visited[v] = false, S.pop();
    while (u != v);
    dag.push_back(uf.find(u));
}

pair<union_find, vi> tarjan_scc(vvi adj) {
    int n = size(adj);
    union_find uf(n);
    vi dag;
    num = new int[n];
    low = new int[n];
    visited = new bool[n];
    memset(num, 255, n << 2);
    memset(low, 0, n << 2);
    memset(visited, 0, n);
    for (int i = idx = 0; i < n; i++)
        if (num[i] == -1)
            strongconnect(i, adj, uf, dag);

    delete[] num;
    delete[] low;
    delete[] visited;
    return pair<union_find, vi>(uf, dag);
}
