ll slow(vector<ll> init, vector<ll> c, ll n, ll mod) {
    while (n >= init.size()) {
        ll cur = 0;
        for (int i = 0; i < c.size(); i++) {
            cur += c[i] * init[(int)init.size()-1-i] % mod;
            if (cur >= mod) cur -= mod;
        }
        init.push_back(cur);
    }
    return init[n];
}

void test() {
    // Field testing: Project Euler 258

    ll mod = 1000000007;
    for (int it = 0; it < 1000; it++) {
        int k = rng() % 10 + 1;
        vector<ll> init, c;
        rep(i,0,k) init.push_back(rng() % mod);
        rep(i,0,k) c.push_back(rng() % mod);
        for (int jt = 0; jt < 20; jt++) {
            ll n = rng() % 10;
            assert_equal(slow(init, c, n, mod), nth_term(init, c, n, mod), true);

            n = rng() % 100;
            assert_equal(slow(init, c, n, mod), nth_term(init, c, n, mod), true);

            n = rng() % 1000;
            assert_equal(slow(init, c, n, mod), nth_term(init, c, n, mod), true);

            n = rng() % 1000;
            assert_equal(slow(init, c, n, 123456), nth_term(init, c, n, 123456), true);
        }
    }
}
