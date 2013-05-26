#include "gcd.cpp"
#include "egcd.cpp"

int crt(const vi& as, const vi& ns) {
    assert(size(as) == size(ns));
    int cnt = size(as), N = 1, x = 0, r, s, l;
    for (int i = 0; i < cnt; i++) {
        N *= ns[i];
        assert(ns[i] > 0);
        for (int j = 0; j < cnt; j++)
            if (i != j)
                assert(gcd(ns[i], ns[j]) == 1);
    }

    for (int i = 0; i < cnt; i++) {
        egcd(ns[i], l = N/ns[i], r, s);
        x += as[i] * s * l;
    }

    return mod(x, N);
}
