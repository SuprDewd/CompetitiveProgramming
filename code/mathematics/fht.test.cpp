// Field testing: CSAcademy Random Nim Generator, CSAcademy And Closure

vi slow(vi a, vi b) {
    vi c(size(a));
    rep(i,0,size(a)) {
        rep(j,0,size(b)) {
            c[i^j] += a[i] * b[j];
        }
    }
    return c;
}

void test() {
    rep(it,0,1000) {
        int k = rng() % 10;
        int n = 1<<k;
        vi a(n), b(n);
        rep(i,0,n) {
            a[i] = uniform_int_distribution(-100, 100)(rng);
            b[i] = uniform_int_distribution(-100, 100)(rng);
        }
        vi ans = slow(a,b);

        fht(a);
        fht(b);

        rep(i,0,n) {
            a[i] *= b[i];
        }

        fht(a,true);
        assert(a == ans);
    }
}
