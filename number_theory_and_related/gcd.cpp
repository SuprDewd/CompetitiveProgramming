#ifndef NUMBER_THEORY_GCD
#define NUMBER_THEORY_GCD
#include "../header.cpp"

int __gcd(int a, int b) {
	return b == 0 ? a : __gcd(b, a % b);
}

int gcd(int a, int b) {
	return __gcd(abs(a), abs(b));
}

#endif
