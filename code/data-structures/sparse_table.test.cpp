struct sparse_table_slow {
    vi arr;
    sparse_table_slow(vi _arr) : arr(_arr) {
    }
    int query(int l, int r) {
        int mn = INF;
        rep(i,l,r+1) {
            mn = min(mn, arr[i]);
        }
        return mn;
    }
};

void test() {
    rep(n,0,257) {
        vi arr(n);
        rep(i,0,n) arr[i] = rand() % 1000000000;

        sparse_table_slow A(arr);
        sparse_table B(arr);
        rep(l,0,n) {
            rep(r,l+1,n) {
                assert_equal(A.query(l,r), B.query(l,r), true);
            }
        }
    }
}
