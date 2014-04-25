struct union_find {
    vi p; union_find(int n) : p(n, -1) { }
    int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
    bool unite(int x, int y) {
        int xp = find(x), yp = find(y);
        if (xp == yp) return false;
        if (p[xp] < p[yp]) p[xp] += p[yp], p[yp] = xp;
        else p[yp] += p[xp], p[xp] = yp;
        return true; }
    int size(int x) { return -p[find(x)]; } };
