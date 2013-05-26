class fenwick_tree {
private:
    int* arr;
    int cnt;

    inline int lsone(int n) {
        return n & -n;
    }

public:
    fenwick_tree(int n) {
        arr = new int[(cnt = n) + 1];
        memset(arr, 0, (cnt + 1) << 2);
    }

    ~fenwick_tree() {
        if (arr) {
            delete[] arr;
            arr = NULL;
        }
    }

    fenwick_tree(const fenwick_tree& other) {
        arr = new int[(cnt = other.cnt) + 1];
        for (int i = 0; i <= cnt; i++)
            arr[i] = other.arr[i];
    }

    void adjust(int i, int v) {
        assert(arr != NULL);
        assert(i >= 0 && i < cnt);

        i++;
        while (i <= cnt) {
            arr[i] += v;
            i += lsone(i);
        }
    }

    int rsq(int i) {
        assert(arr != NULL);

        if (i < 0)
            return 0;
        if (i >= cnt)
            return rsq(cnt - 1);

        i++;
        int sum = 0;
        while (i) {
            sum += arr[i];
            i -= lsone(i);
        }

        return sum;
    }

    inline int rsq(int i, int j) {
        return rsq(j) - rsq(i - 1);
    }

    inline int get(int i) {
        return rsq(i) - rsq(i - 1);
    }
};
