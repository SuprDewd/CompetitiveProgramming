#ifndef NUMBER_THEORY_LCM
#define NUMBER_THEORY_LCM
#include "../header.cpp"
#include "./gcd.cpp"

int lcm(int a, int b) {
	if (a == 0 || b == 0) return 0;
	a = abs(a);
	b = abs(b);
	return a / gcd(a, b) * b;
}

#endif
