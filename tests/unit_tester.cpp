#include "unit_tester.h"
#include "unit_test.h"
#include <iostream>
#include <ctime>
using namespace std;

void unit_tester::add_test(unit_test* test)
{
	tests.push_back(test);
}

void unit_tester::run()
{
	for (vector<unit_test*>::iterator it = tests.begin(); it != tests.end(); it++)
	{
		cout << "[TEST " << (*it)->get_name() << "]:" << endl;
		clock_t start = clock(), duration;
		(*it)->run();
		duration = clock() - start;
		int total = (*it)->get_test_cnt(),
			failed = (*it)->get_test_fail_cnt();
		cout << endl << "[TEST " << (*it)->get_name() << "]: " << (failed == 0 ? "Completed. All" : "FAILED! Only") << " " << (total - failed) << "/" << total << " tests completed successfully. (" << duration / (CLOCKS_PER_SEC / 1000.0) << " ms)" << endl;
	}
}