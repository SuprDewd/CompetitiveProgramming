vector<int> nth_permutation(int cnt, int n) {
	vector<int> idx(cnt), per(cnt), fac(cnt);
	for (int i = 0; i < cnt; i++) idx[i] = i;
	for (int i = 1; i <= cnt; i++) fac[i - 1] = n % i, n /= i;
	for (int i = cnt - 1; i >= 0; i--) per[cnt - i - 1] = idx[fac[i]], idx.erase(idx.begin() + fac[i]);
	return per;
}