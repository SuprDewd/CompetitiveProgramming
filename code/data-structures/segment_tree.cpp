#ifdef SEG_MIN
const int ID = INF;
int f(int a, int b) { return min(a, b); }
#else
const int ID = 0;
int f(int a, int b) { return a + b; }
#endif
struct segment_tree {
    int n; vi data, lazy;
    segment_tree() {}
    segment_tree(const vi &arr) : n(size(arr)), data(4*n), lazy(4*n,INF) {
        mk(arr, 0, n-1, 0); }
    int mk(const vi &arr, int l, int r, int i) {
        if (l == r) return data[i] = arr[l];
        int m = (l + r) / 2;
        return data[i] = f(mk(arr, l, m, 2*i+1), mk(arr, m+1, r, 2*i+2)); }
    int query(int a, int b) { return q(a, b, 0, n-1, 0); }
    int q(int a, int b, int l, int r, int i) {
        propagate(l, r, i);
        if (r < a || b < l) return ID;
        if (a <= l && r <= b) return data[i];
        int m = (l + r) / 2;
        return f(q(a, b, l, m, 2*i+1), q(a, b, m+1, r, 2*i+2)); }
    void update(int i, int v) { u(i, v, 0, n-1, 0); }
    int u(int i, int v, int l, int r, int j) {
        propagate(l, r, j);
        if (r < i || i < l) return data[j];
        if (l == i && r == i) return data[j] = v;
        int m = (l + r) / 2;
        return data[j] = f(u(i, v, l, m, 2*j+1), u(i, v, m+1, r, 2*j+2)); }
    void range_update(int a, int b, int v) { ru(a, b, v, 0, n-1, 0); }
    int ru(int a, int b, int v, int l, int r, int i) {
        propagate(l, r, i);
        if (l > r) return ID;
        if (r < a || b < l) return data[i];
        if (a <= l && r <= b) return (lazy[i] = v) * (r - l + 1) + data[i];
        int m = (l + r) / 2;
        return data[i] = f(ru(a, b, v, l, m, 2*i+1),
                           ru(a, b, v, m+1, r, 2*i+2));
    }
    void propagate(int l, int r, int i) {
        if (l > r || lazy[i] == INF) return;
        data[i] += lazy[i] * (r - l + 1);
        if (l < r) {
            if (lazy[2*i+1] == INF) lazy[2*i+1] = lazy[i];
            else lazy[2*i+1] += lazy[i];
            if (lazy[2*i+2] == INF) lazy[2*i+2] = lazy[i];
            else lazy[2*i+2] += lazy[i];
        }
        lazy[i] = INF;
    }
};
