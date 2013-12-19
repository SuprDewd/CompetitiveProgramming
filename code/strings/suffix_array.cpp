struct entry { ii nr; int p; };
bool operator <(const entry &a, const entry &b) { return a.nr < b.nr; }
struct suffix_array {
    string s; int n; vvi P; vector<entry> L; vi idx;
    suffix_array(string s) : s(s), n(size(s)) {
        L = vector<entry>(n), P.push_back(vi(n)), idx = vi(n);
        for (int i = 0; i < n; i++) P[0][i] = s[i] - 'a';
        for (int stp = 1, cnt = 1; cnt >> 1 < n; stp++, cnt <<= 1) {
            P.push_back(vi(n));
            for (int i = 0; i < n; i++)
                L[L[i].p = i].nr = ii(P[stp - 1][i],
                        i + cnt < n ? P[stp - 1][i + cnt] : -1);
            sort(L.begin(), L.end());
            for (int i = 0; i < n; i++)
                P[stp][L[i].p] = i > 0 &&
                    L[i].nr == L[i - 1].nr ? P[stp][L[i - 1].p] : i;
        }
        for (int i = 0; i < n; i++) idx[P[size(P) - 1][i]] = i;
    }
    int lcp(int x, int y) {
        int res = 0;
        if (x == y) return n - x;
        for (int k = size(P) - 1; k >= 0 && x < n && y < n; k--)
            if (P[k][x] == P[k][y]) x += 1 << k, y += 1 << k, res += 1 << k;
        return res;
    }
};
