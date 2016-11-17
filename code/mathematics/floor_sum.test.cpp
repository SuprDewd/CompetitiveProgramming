// Field testing: MIPT 2015, 4J Triangle

ll floor_sum_super_slow(ll n, ll a, ll b, ll c) {
    if (c < 0) return 0;
    ll cnt = 0;
    for (ll x = 0; x <= n; x++) {
        for (ll y = 0; y <= c; y++) {
            if (a*x + b*y <= c) {
                cnt++;
            }
        }
    }
    return cnt;
}
ll floor_sum_slow(ll n, ll a, ll b, ll c) {
    if (c < 0) return 0;
    ll cnt = 0;
    for (ll x = 0; x <= n; x++) {
        cnt += (c-a*x) / b + 1;
    }
    return cnt;
}
void test() {
    rep(n,0,100) {
        rep(a,1,100) rep(b,1,100) {
            rep(c,0,100) {
                if (c-n*a < 0) continue;
                // ll ans = floor_sum_super_slow(n,a,b,c);
                ll ans2 = floor_sum_slow(n,a,b,c);
                ll ans3 = floor_sum(n,a,b,c);
                // assert_equal(ans,ans2, true);
                assert_equal(ans2,ans3,true);
            }
        }
    }
}
