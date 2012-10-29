int _egcd_(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	} else {
		int d = _egcd_(b, a % b, x, y);
		x -= a / b * y;
		swap(x, y);
		return d;
	}
}

int egcd(int a, int b, int& x, int& y) {
	int d = _egcd_(abs(a), abs(b), x, y);
	if (a < 0) x = -x;
	if (b < 0) y = -y;
	return a < 0 && b < 0 ? -d : d;
}