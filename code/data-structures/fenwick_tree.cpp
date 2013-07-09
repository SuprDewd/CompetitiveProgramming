struct fenwick_tree {
    vi dataMul;
    vi dataAdd;

    fenwick_tree(int n) {
        dataMul.resize(n);
        dataAdd.resize(n);
        fill(all(dataMul), 0);
        fill(all(dataAdd), 0);
    }

    void adjust(int i, int v) {
        adjust(i, i, v);
    }

    inline int rsq(int i, int j) {
        return rsq(j) - rsq(i - 1);
    }

    inline int get(int i) {
        return rsq(i) - rsq(i - 1);
    }

    void adjust(int left, int right, int by) {
        internalUpdate(left, by, -by * (left - 1));
        internalUpdate(right, -by, by * right);
    }

    void internalUpdate(int at, int mul, int add) {
        while (at < size(dataMul)) {
            dataMul[at] += mul;
            dataAdd[at] += add;
            at |= (at + 1);
        }
    }

    int rsq(int at) {
        int mul = 0, add = 0, start = at;
        while (at >= 0) {
            mul += dataMul[at];
            add += dataAdd[at];
            at = (at & (at + 1)) - 1;
        }
        return mul * start + add;
    }
};
