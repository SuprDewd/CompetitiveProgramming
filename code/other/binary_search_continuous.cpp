double binary_search_continuous(double low, double high, double eps, double (*f)(double)) {
    while (true) {
        double mid = (low + high) / 2, cur = f(mid);
        if (abs(cur) < eps) return mid;
        else if (0 < cur) high = mid;
        else low = mid;
    }
}
