int snoob(int x) {
	int y = x & -x, z = x + y;
	return z | ((x ^ z) >> 2) / y;
}