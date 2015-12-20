#include "egcd.cpp"
vi linear_congruence(int a, int b, int n) {
    int x, y, d = egcd(a, n, x, y);
    vi res;
    if (b % d != 0) return res;
    int x0 = smod(b / d * x, n);
    rep(k,0,d) res.push_back(smod(x0 + k * n / d, n));
    return res;
}
