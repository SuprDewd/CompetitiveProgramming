#include "egcd.cpp"
vi linear_congruence(int a, int b, int n) {
    int x, y, d = egcd(a, n, x, y);
    vi res;
    if (b % d != 0) return res;
    int x0 = mod(b / d * x, n);
    for (int k = 0; k < d; k++) res.push_back(mod(x0 + k * n / d, n));
    return res;
}
