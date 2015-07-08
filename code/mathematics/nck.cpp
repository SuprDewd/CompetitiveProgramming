int nck(int n, int k) {
    if (n - k < k) k = n - k;
    int res = 1;
    rep(i,1,k+1) res = res * (n - (k - i)) / i;
    return res;
}
