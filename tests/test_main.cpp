#include "unit_test.h"
#include "unit_tester.h"
#include <cstdio>
using namespace std;

#include "number_theory_and_related/is_prime.cpp"

int main()
{
	unit_tester tester;

	tester.add_test(new is_prime_test());

	tester.run();

	return 0;
}