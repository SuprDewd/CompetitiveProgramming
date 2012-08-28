#include "unit_test.h"
#include <cstdio>
using namespace std;

unit_test::unit_test(string name) : name(name), test_cnt(0), test_fail_cnt(0) { }

string unit_test::get_name() const { return name; }
int unit_test::get_test_cnt() const { return test_cnt; }
int unit_test::get_test_fail_cnt() const { return test_fail_cnt; }

bool unit_test::assert_true(bool b)
{
	return test_finished(b);
}

bool unit_test::assert_false(bool b)
{
	return test_finished(!b);
}

bool unit_test::test_finished(bool ok)
{
	test_cnt++;
	if (!ok) test_fail_cnt++;
	printf("%c", ok ? '.' : 'F');
	if (test_cnt % TEST_DOT_LENGTH == 0) printf("\n");
	fflush(stdout);
	return ok;
}