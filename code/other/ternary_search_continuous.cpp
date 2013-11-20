template <class F>
double ternary_search_continuous(double lo, double hi, double eps, F f) {
    while (hi - lo > eps) {
        double m1 = lo + (hi - lo) / 3, m2 = hi - (hi - lo) / 3;
        if (f(m1) < f(m2)) lo = m1;
        else hi = m2;
    }
    return hi;
}
