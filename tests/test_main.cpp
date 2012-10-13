#include "unit_test.h"
#include "unit_tester.h"
#include <cstdio>
using namespace std;

#include "number_theory_and_related/is_prime.cpp"
#include "number_theory_and_related/gcd.cpp"
#include "number_theory_and_related/lcm.cpp"
#include "cycle_detection/floyds_cycle_finding_algorithm.cpp"

int main()
{
	unit_tester tester;

	tester.add_test(new is_prime_test());
	tester.add_test(new gcd_test());
	tester.add_test(new lcm_test());
	tester.add_test(new floyds_cycle_finding_algorithm_test());

	tester.run();

	return 0;
}
