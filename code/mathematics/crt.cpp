#include "egcd.cpp"
int crt(const vi& as, const vi& ns) {
    int cnt = size(as), N = 1, x = 0, r, s, l;
    rep(i,0,cnt) N *= ns[i];
    rep(i,0,cnt) egcd(ns[i], l = N/ns[i], r, s), x += as[i] * s * l;
    return mod(x, N); }
