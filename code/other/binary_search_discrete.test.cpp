int target;

bool f1(int x) {
    return x >= target;
}

bool f2(int x) {
    return x / 3 >= target;
}

bool f3(int x) {
    return x > target;
}

void test() {
    int res;

    for (target = -10; target <= 10; target++) {
        res = binary_search_discrete(-40, 40, f2);
        assert_true(f2(res));
        assert_true(!f2(res - 1));
    }

    target = 0;
    for (int i = 10; i <= 20; i++) {
        res = binary_search_discrete(10, i, f1);
        assert_equal(10, res);
    }

    target = 10;
    for (int i = 10; i <= 20; i++) {
        res = binary_search_discrete(10, i, f1);
        assert_equal(10, res);
    }

    target = 11;
    for (int i = 11; i <= 20; i++) {
        res = binary_search_discrete(10, i, f1);
        assert_equal(11, res);
    }

    target = 0;
    for (int i = 10; i <= 20; i++) {
        res = binary_search_discrete(10, i, f3);
        assert_equal(10, res);
    }

    target = 10;
    for (int i = 11; i <= 20; i++) {
        res = binary_search_discrete(10, i, f3);
        assert_equal(11, res);
    }

    target = 11;
    for (int i = 12; i <= 20; i++) {
        res = binary_search_discrete(10, i, f3);
        assert_equal(12, res);
    }
}
