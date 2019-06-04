
#include "../code/mathematics/mod_inv.cpp"

struct Mod {
    ll x;
    Mod(ll _x = 0) {
        x = (_x % 1000000007 + 1000000007) % 1000000007;
    }
    Mod operator +(const Mod &other) const {
        return x + other.x;
    }
    Mod operator -(const Mod &other) const {
        return x - other.x;
    }
    Mod operator -() const {
        return -x;
    }
    Mod operator *(const Mod &other) const {
        return x * other.x;
    }
    Mod operator /(const Mod &other) const {
        return x * mod_inv(other.x, 1000000007);
    }
    bool operator ==(const Mod &other) const {
        return x == other.x;
    }
};
ostream& operator <<(ostream &outs, const Mod &x) {
    return outs << x.x;
}

void testMod() {
    for (int it = 0; it < 10000; it++) {
        int K = rand() % 20 + 1,
            S = rand() % 1000 + 1;

        int k = rand() % K + 1;
        vector<Mod> init(k);
        rep(i,0,k) init[i] = rand() % (2*S) - S;

        vector<Mod> c(k);
        rep(i,0,k) c[i] = rand() % (2*S) - S;
        rep(i,0,k) {
            Mod cur = 0;
            rep(j,0,k) {
                cur = cur + init[(int)init.size()-1 - j] * c[j];
            }
            init.push_back(cur);
        }

        vector<Mod> res = berlekamp_massey<Mod>(init);
        assert(res.size() <= k);
        for (int i = k; i < init.size(); i++) {
            Mod cur = 0;
            rep(j,0,res.size()) {
                cur = cur + init[i-1 - j] * res[j];
            }
            assert_equal(init[i], cur, true);
        }
    }
}

void testDouble() {
    for (int it = 0; it < 10000; it++) {
        int K = rand() % 5 + 1,
            S = rand() % 10 + 1;

        int k = rand() % K + 1;
        vector<long double> init(k);
        rep(i,0,k) init[i] = rand() % (2*S) - S;

        vector<long double> c(k);
        rep(i,0,k) c[i] = rand() % (2*S) - S;
        rep(i,0,k) {
            long double cur = 0;
            rep(j,0,k) {
                cur = cur + init[(int)init.size()-1 - j] * c[j];
            }
            init.push_back(cur);
        }

        vector<long double> res = berlekamp_massey<long double>(init);
        assert(res.size() <= k);
        for (int i = k; i < init.size(); i++) {
            long double cur = 0;
            rep(j,0,res.size()) {
                cur = cur + init[i-1 - j] * res[j];
            }
            assert_almost_equal(init[i], cur, 1e-6, true);
        }
    }
}

void test() {
    testMod();
    testDouble();
}
