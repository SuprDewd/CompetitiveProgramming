struct segment_tree_slow {
    vi arr;
    segment_tree_slow(vi _arr) : arr(_arr) { }
    int query(int a, int b) {
        int s = 0;
        for (int i = a; i <= b; i++) s += arr[i];
        return s;
    }
    void update(int i, int v) {
        arr[i] = v;
    }
};

void test() {
    int n = 100000;
    vi arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = randint(-1000, 1000);
    }

    segment_tree x(arr);
    segment_tree_slow xslow(arr);

    for (int i = 0; i < 100000; i++) {
        int op = randint(0, 1);
        if (op == 0) {
            int a = randint(0, n-1),
                b = randint(a, n-1);
            assert_equal(xslow.query(a, b), x.query(a, b));
        } else {
            int idx = randint(0, n-1),
                val = randint(-1000, 1000);
            x.update(idx, val);
            xslow.update(idx, val);
        }
    }
}
