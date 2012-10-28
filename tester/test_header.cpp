template <class T>
void assert_equal(T expected, T actual)
{
	if (!(expected == actual))
	{
		cout << "Assertion failed:" << endl;
		cout << "Expected: " << expected << endl;
		cout << "  Actual: " << actual << endl;
	}
}

template <class T>
void assert_not_equal(T not_expected, T actual)
{
	if (not_expected == actual)
	{
		cout << "Assertion failed:" << endl;
		cout << "Not expected: " << not_expected << endl;
		cout << "      Actual: " << actual << endl;
	}
}

void assert_true(bool actual)
{
	assert_equal(true, actual);
}

void assert_false(bool actual)
{
	assert_equal(false, actual);
}