// const int ID = INF;
// int f(int a, int b) { return min(a, b); }
const int ID = 0;
int f(int a, int b) { return a + b; }
struct segment_tree {
    int n; vi data;
    segment_tree(const vi &arr) : n(size(arr)), data(4*n) {
        mk(arr, 0, n-1, 0); }
    int mk(const vi &arr, int l, int r, int i) {
        if (l == r) return data[i] = arr[l];
        int m = (l + r) / 2;
        return data[i] = f(mk(arr, l, m, 2*i+1), mk(arr, m+1, r, 2*i+2)); }
    int query(int a, int b) { return q(a, b, 0, n-1, 0); }
    int q(int a, int b, int l, int r, int i) {
        if (r < a || b < l) return ID;
        if (a <= l && r <= b) return data[i];
        int m = (l + r) / 2;
        return f(q(a, b, l, m, 2*i+1), q(a, b, m+1, r, 2*i+2)); }
    int update(int i, int v) { u(i, v, 0, n-1, 0); }
    int u(int i, int v, int l, int r, int j) {
        if (r < i || i < l) return data[j];
        if (l == i && r == i) return data[j] = v;
        int m = (l + r) / 2;
        return data[j] = f(u(i, v, l, m, 2*j+1), u(i, v, m+1, r, 2*j+2)); } };
