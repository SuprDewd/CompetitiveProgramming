void test() {
    vi res = linear_congruence(3, 2, 6);
    assert_equal(0, size(res));

    res = linear_congruence(5, 2, 6);
    assert_equal(1, size(res));
    assert_equal(4, res[0]);

    res = linear_congruence(4, 2, 6);
    assert_equal(2, size(res));
    sort(res.begin(), res.end());
    assert_equal(2, res[0]);
    assert_equal(5, res[1]);

    res = linear_congruence(12, 20, 28);
    assert_equal(4, size(res));
    sort(res.begin(), res.end());
    assert_equal(4, res[0]);
    assert_equal(11, res[1]);
    assert_equal(18, res[2]);
    assert_equal(25, res[3]);
}

