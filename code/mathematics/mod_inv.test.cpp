#include "../code/mathematics/gcd.cpp"

void test() {
    for (int a = -20; a < 20; a++) {
        for (int b = 2; b < 40; b++) {
            if (gcd(a, b) == 1) {
                assert_equal(1, mod((a * mod_inv(a, b)), b));
            } else {
                assert_equal(-1, mod_inv(a, b));
            }
        }
    }
}
