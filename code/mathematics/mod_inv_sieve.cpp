vi inv_sieve(int n, int p) {
    vi inv(n,1);
    rep(i,2,n) inv[i] = (p - (ll)(p/i) * inv[p%i] % p) % p;
    return inv; }
