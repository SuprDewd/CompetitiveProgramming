template <class T>
void assert_equal(T expected, T actual, bool kill = false) {
    if (!(expected == actual)) {
        cout << "Assertion failed:" << endl;
        cout << "Expected: " << expected << endl;
        cout << "  Actual: " << actual << endl;
        if (kill) assert(false);
    }
}

template <class T>
void assert_not_equal(T not_expected, T actual, bool kill = false) {
    if (not_expected == actual) {
        cout << "Assertion failed:" << endl;
        cout << "Not expected: " << not_expected << endl;
        cout << "      Actual: " << actual << endl;
        if (kill) assert(false);
    }
}

void assert_true(bool actual, bool kill = false) {
    if (true != actual) {
        cout << "Assertion failed:" << endl;
        cout << "Expected: " << "true" << endl;
        cout << "  Actual: " << "false" << endl;
        if (kill) assert(false);
    }
}

void assert_false(bool actual, bool kill = false) {
    if (false != actual) {
        cout << "Assertion failed:" << endl;
        cout << "Expected: " << "false" << endl;
        cout << "  Actual: " << "true" << endl;
        assert(false);
        if (kill) assert(false);
    }
}

int randint(int a, int b) {
    return static_cast<int>(static_cast<double>(rand()) / RAND_MAX * (b - a) + a + 0.5);
}
