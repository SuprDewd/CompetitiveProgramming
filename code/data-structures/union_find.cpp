struct union_find {
    vi parent;
    int cnt;
    union_find(int n) { parent.resize(cnt = n); for (int i = 0; i < cnt; i++) parent[i] = i; }
    int find(int i) { return parent[i] == i ? i : (parent[i] = find(parent[i])); }
    bool unite(int i, int j) {
        int ip = find(i), jp = find(j);
        parent[ip] = jp; return ip != jp; } };
