double binary_search(double low, double high, double target, double eps, double (*f)(double)) {
	while (true) {
		double mid = (low + high) / 2, cur = f(mid);
		if (fabs(cur - target) < eps) return mid;
		else if (target < cur) high = mid;
		else low = mid;
	}
}