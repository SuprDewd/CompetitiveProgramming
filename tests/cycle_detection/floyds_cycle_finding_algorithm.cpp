#include "../unit_test.h"

#include "../../cycle_detection/floyds_cycle_finding_algorithm.cpp"

int __f1_m;
int __f1(int n)
{
	if (n < 0) return n + 1;
	return (n + 1) % __f1_m;
}

class floyds_cycle_finding_algorithm_test : public unit_test
{
public:
	floyds_cycle_finding_algorithm_test() : unit_test("floyds_cycle_finding_algorithm") { }

	void run()
	{
		for (int mod = 1; mod <= 50; mod++)
		{
			for (int start = -20; start <= 60; start++)
			{
				__f1_m = mod;
				assert_equal<ii>(ii(mod, start < 0 ? -start : start < mod ? 0 : 1), detect_cycle<int>(start, __f1));
			}
		}
	}
};
