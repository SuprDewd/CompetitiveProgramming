#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <string>
#include <cstdio>
using namespace std;

#define TEST_DOT_LENGTH 50

class unit_test
{
public:

	/* Assertions */
	bool assert_true(bool b);
	bool assert_false(bool b);

	template <class T>
	bool assert_equal(const T& expected, const T& actual)
	{
		return test_finished(expected == actual);
	}

	template <class T>
	bool assert_not_equal(const T& not_expected, const T& actual)
	{
		return test_finished(not_expected != actual);
	}

	/* To be implemented by user */
	virtual void run() { }

	/* Misc */
	unit_test(string name);
	string get_name() const;
	int get_test_cnt() const;
	int get_test_fail_cnt() const;

private:
	int test_cnt;
	int test_fail_cnt;
	string name;
	bool test_finished(bool ok);
};

#endif