#include "egcd.cpp"
int crt(const vi& as, const vi& ns) {
    int cnt = size(as), N = 1, x = 0, r, s, l;
    for (int i = 0; i < cnt; i++) N *= ns[i]; 
    for (int i = 0; i < cnt; i++)
        egcd(ns[i], l = N/ns[i], r, s), x += as[i] * s * l;
    return mod(x, N); }
