void test1() {
    fenwick_tree ft(20);

    for (int i = 0; i < 20; i++) {
        assert_equal(0, ft.get(i));
        ft.adjust(i, i);
        assert_equal(i, ft.get(i));
        ft.adjust(i, -i);
        assert_equal(0, ft.get(i));
    }

    ft.adjust(3, 1);
    for (int i = 0; i < 20; i++)
    {
        for (int j = i; j < 20; j++)
        {
            if (i <= 3 && 3 <= j)
            {
                assert_equal(1, ft.rsq(i, j));
            }
            else
            {
                assert_equal(0, ft.rsq(i, j));
            }
        }
    }

    ft.adjust(5, -2);
    assert_equal(-1, ft.rsq(1, 8));
    ft.adjust(4, 5);
    assert_equal(4, ft.rsq(1, 8));
    ft.adjust(0, 100);
    assert_equal(4, ft.rsq(1, 8));
    assert_equal(104, ft.rsq(0, 19));
    ft.adjust(19, -200);
    assert_equal(-96, ft.rsq(0, 19));
}

class fake_fenwick_tree {
public:
    vi arr;

    fake_fenwick_tree(int n) {
        arr.resize(n);
        fill(all(arr), 0);
    }

    void adjust(int i, int v) {
        arr[i] += v;
    }

    int rsq(int i) {
        int sum = 0;
        for (int j = 0; j <= i; j++) {
            sum += arr[j];
        }

        return sum;
    }

    int get(int i) {
        return arr[i];
    }

    int rsq(int i, int j) {
        int sum = 0;
        for (int k = i; k <= j; k++) {
            sum += arr[k];
        }

        return sum;
    }
};

void test2() {
    int n = 1000;
    fenwick_tree ft(n);
    fake_fenwick_tree fft(n);
    for (int i = 0; i < 1000000; i++) {
        int op = randint(0, 3);
        if (op == 0) {
            int at = randint(0, n-1);
            assert_equal(ft.get(at), fft.get(at));
        } else if (op == 1) {
            int j = randint(0, n-1),
                k = randint(j, n-1);
            assert_equal(ft.rsq(j, k), fft.rsq(j, k));
        } else if (op == 2) {
            int at = randint(0, n-1);
            assert_equal(ft.rsq(at), fft.rsq(at));
        } else {
            int at = randint(0, n-1),
                upd = randint(-1337, 1337);
            ft.adjust(at, upd);
            fft.adjust(at, upd);
        }
    }
}

void test() {
    test1();
    test2();
}

