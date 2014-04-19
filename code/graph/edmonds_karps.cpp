#define MAXV 2000
int q[MAXV], d[MAXV], p[MAXV];
struct flow_network {
    struct edge {
        int v, cap, nxt;
        edge(int _v, int _cap, int _nxt) : v(_v), cap(_cap), nxt(_nxt) {  }
    };
    int n, ecnt, *head;
    vector<edge> e, e_store;
    flow_network(int _n, int m = -1) : n(_n), ecnt(0) {
        e.reserve(2 * (m == -1 ? n : m));
        memset(head = new int[n], -1, n << 2);
    }
    void destroy() { delete[] head; }
    void reset() { e = e_store; }
    void add_edge(int u, int v, int uv, int vu=0) {
        e.push_back(edge(v, uv, head[u])); head[u] = ecnt++;
        e.push_back(edge(u, vu, head[v])); head[v] = ecnt++;
    }
    int max_flow(int s, int t, bool res = true) {
        if (s == t) return 0;
        e_store = e;
        int f = 0, l, r, v;
        while (true) {
            memset(d, -1, n << 2);
            memset(p, -1, n << 2);
            l = r = 0, d[q[r++] = s] = 0;
            while (l < r)
                for (int u = q[l++], i = head[u]; i != -1; i = e[i].nxt)
                    if (e[i].cap > 0 && (d[v = e[i].v] == -1 || d[u] + 1 < d[v]))
                        d[v] = d[u] + 1, p[q[r++] = v] = i;
            if (p[t] == -1) break;
            int x = INF, at = p[t];
            while (at != -1) x = min(x, e[at].cap), at = p[e[at^1].v];
            at = p[t], f += x;
            while (at != -1)
                e[at].cap -= x, e[at^1].cap += x, at = p[e[at^1].v];
        }
        if (res) reset();
        return f;
    }
};
