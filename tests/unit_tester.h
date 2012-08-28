#ifndef UNIT_TESTER_H
#define UNIT_TESTER_H

#include "unit_test.h"
#include <vector>
using namespace std;

class unit_tester
{
public:
	void add_test(unit_test* test);
	void run();
private:
	vector<unit_test*> tests;
};

#endif