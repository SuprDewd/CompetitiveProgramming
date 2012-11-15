int binary_search_high(int low, int high, int target, int (*f)(int)) {
	while (low <= high) {
		int mid = (low + high) / 2, cur = f(mid);
		if (target < cur) high = mid - 1;
		else low = mid + 1;
	}
	return high;
}