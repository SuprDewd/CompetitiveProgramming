#include "egcd.cpp"

int mod_inv(int a, int m) {
    int x, y, d = egcd(a, m, x, y);
    if (d != 1) return -1;
    return x < 0 ? x + m : x;
}
