void test() {
    matrix<int> A(2, 2);
    assert_equal(0, A(0, 0));
    assert_equal(0, A(1, 0));
    assert_equal(0, A(0, 1));
    assert_equal(0, A(1, 1));

    A(0, 0) = A(0, 1) = A(1, 0) = 1;
    assert_equal(1, A(0, 0));
    assert_equal(1, A(1, 0));
    assert_equal(1, A(0, 1));
    assert_equal(0, A(1, 1));

    A = A.pow(20);
    assert_equal(10946, A(0, 0));
    assert_equal(6765, A(1, 0));
    assert_equal(6765, A(0, 1));
    assert_equal(4181, A(1, 1));

    A = A * 5;
    assert_equal(10946 * 5, A(0, 0));
    assert_equal(6765 * 5, A(1, 0));
    assert_equal(6765 * 5, A(0, 1));
    assert_equal(4181 * 5, A(1, 1));

    A = A + A;
    assert_equal(10946 * 5 * 2, A(0, 0));
    assert_equal(6765 * 5 * 2, A(1, 0));
    assert_equal(6765 * 5 * 2, A(0, 1));
    assert_equal(4181 * 5 * 2, A(1, 1));

    A = A - A;
    assert_equal(0, A(0, 0));
    assert_equal(0, A(1, 0));
    assert_equal(0, A(0, 1));
    assert_equal(0, A(1, 1));

    matrix<int> B(1, 2);
    B(0, 0) = 1;
    B(0, 1) = 5;
    assert_equal(1, B.transpose()(0, 0));
    assert_equal(5, B.transpose()(1, 0));

    matrix<double> C(3, 4);
    C(0, 0) = 2;
    C(0, 1) = 1;
    C(0, 2) = -1;
    C(0, 3) = 8;
    C(1, 0) = -3;
    C(1, 1) = -1;
    C(1, 2) = 2;
    C(1, 3) = -11;
    C(2, 0) = -2;
    C(2, 1) = 1;
    C(2, 2) = 2;
    C(2, 3) = -3;

    C = C.triangular_form();

    for (int i = 0; i < C.rows; i++)
    {
        for (int j = 0; j < C.cols; j++)
        {
            printf("%lf ", C(i, j));
        }

        printf("\n");
    }
}
