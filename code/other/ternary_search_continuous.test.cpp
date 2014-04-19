struct monofunc {
    double a, b, c, d;
    monofunc(double _a, double _b, double _c, double _d) : a(_a), b(_b), c(_c), d(_d) { }
    double operator ()(double x) { return -c*(x-a)*(x-b) + d; }
};

void assert_almost_equal(double a, double b) {
    assert_true(abs(a - b) < 1e-5);
}

void test() {
    assert_almost_equal(0, ternary_search_continuous(-10, 10, 1e-9, monofunc(0,0,1,0)));
    assert_almost_equal(-1.5, ternary_search_continuous(-10, 10, 1e-9, monofunc(-6,3,1,7)));
    assert_almost_equal(-1.5, ternary_search_continuous(-10, 10, 1e-9, monofunc(-6,3,5,7)));
    assert_almost_equal(-10.5, ternary_search_continuous(-20, 20, 1e-9, monofunc(-24,3,5,7)));
    assert_almost_equal(-2.92575, ternary_search_continuous(-20, 20, 1e-9, monofunc(-2.71,-3.1415,0.43,0.97)));
    assert_almost_equal(-2.92575, ternary_search_continuous(-20, 20, 1e-9, monofunc(-3.1415,-2.71,0.43,0.97)));
}
