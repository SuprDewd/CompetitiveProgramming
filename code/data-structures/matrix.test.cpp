/* Field testing: http://codeforces.com/gym/100962 ABBA */
void test() {
  double det;
  int rank;

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

  matrix<int> A2(A);
  assert_equal(10946, A2(0, 0));
  assert_equal(6765, A2(1, 0));
  assert_equal(6765, A2(0, 1));
  assert_equal(4181, A2(1, 1));

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

  matrix<double> C(2, 3);
  C(0, 0) = 5;
  C(0, 1) = 7;
  C(0, 2) = 8;
  C(1, 0) = 1;
  C(1, 1) = 1;
  C(1, 2) = 2;
  C = C.rref(det,rank);
  assert_equal(1.0, C(0, 0));
  assert_equal(0.0, C(0, 1));
  assert_equal(3.0, C(0, 2));
  assert_equal(0.0, C(1, 0));
  assert_equal(1.0, C(1, 1));
  assert_equal(-1.0, C(1, 2));

  C = matrix<double>(2, 3);
  C(0, 0) = 2;
  C(0, 1) = 4;
  C(0, 2) = 8;
  C(1, 0) = 6;
  C(1, 1) = 12;
  C(1, 2) = 14;
  C = C.rref(det,rank);
  assert_equal(1.0, C(0, 0));
  assert_equal(2.0, C(0, 1));
  assert_equal(0.0, C(0, 2));
  assert_equal(0.0, C(1, 0));
  assert_equal(0.0, C(1, 1));
  assert_equal(1.0, C(1, 2));

  C = matrix<double>(3, 3);
  C(0, 0) = 2;
  C(0, 1) = 2;
  C(0, 2) = 4;
  C(1, 0) = 1;
  C(1, 1) = 1;
  C(1, 2) = 8;
  C(2, 0) = 7;
  C(2, 1) = 6;
  C(2, 2) = 5;
  C = C.rref(det,rank);
  assert_equal(1.0, C(0, 0));
  assert_equal(0.0, C(0, 1));
  assert_equal(0.0, C(0, 2));
  assert_equal(0.0, C(1, 0));
  assert_equal(1.0, C(1, 1));
  assert_equal(0.0, C(1, 2));
  assert_equal(0.0, C(2, 0));
  assert_equal(0.0, C(2, 1));
  assert_equal(1.0, C(2, 2));

  C = matrix<double>(2, 2);
  C(0, 0) = 1;
  C(0, 1) = 2;
  C(1, 0) = 3;
  C(1, 1) = 4;
  C = C.rref(det,rank);
  assert_equal(1.0, C(0, 0));
  assert_equal(0.0, C(0, 1));
  assert_equal(0.0, C(1, 0));
  assert_equal(1.0, C(1, 1));

  C = matrix<double>(2, 2);
  C(0, 0) = 3;
  C(0, 1) = 3;
  C(1, 0) = 9;
  C(1, 1) = 9;
  C = C.rref(det,rank);
  assert_equal(1.0, C(0, 0));
  assert_equal(1.0, C(0, 1));
  assert_equal(0.0, C(1, 0));
  assert_equal(0.0, C(1, 1));

  C = matrix<double>(3, 3);
  C(0, 0) = 1;
  C(0, 1) = 2;
  C(0, 2) = 3;
  C(1, 0) = 4;
  C(1, 1) = 5;
  C(1, 2) = 6;
  C = C.rref(det,rank);
  assert_equal(1.0, C(0, 0));
  assert_equal(0.0, C(0, 1));
  assert_equal(-1.0, C(0, 2));
  assert_equal(0.0, C(1, 0));
  assert_equal(1.0, C(1, 1));
  assert_equal(2.0, C(1, 2));

  C = matrix<double>(3, 3);
  C(0, 0) = -2;
  C(0, 1) = 2;
  C(0, 2) = 3;
  C(1, 0) = -1;
  C(1, 1) = 1;
  C(1, 2) = 3;
  C(2, 0) = 2;
  C(2, 1) = 0;
  C(2, 2) = -1;
  C.rref(det,rank);
  assert_equal(6.0, det);

  C = matrix<double>(3, 3);
  C(0, 0) = -2;
  C(0, 1) = 2;
  C(0, 2) = -3;
  C(1, 0) = -1;
  C(1, 1) = 1;
  C(1, 2) = 3;
  C(2, 0) = 2;
  C(2, 1) = 0;
  C(2, 2) = -1;
  C.rref(det,rank);
  assert_equal(18.0, det);

  C = matrix<double>(3,1);
  C(0,0) = -2;
  C(1,0) = 1;
  C(2,0) = 3;
  C.rref(det,rank);
  assert_equal(1, rank);

  C = matrix<double>(1,3);
  C(0,0) = -2;
  C(0,1) = 1;
  C(0,2) = 3;
  C.rref(det,rank);
  assert_equal(1, rank);

  C = matrix<double>(10, 10);
  for (int i = 0; i < 10; i++)
    C(i, i) = i + 1;

  C.rref(det,rank);
  assert_equal(3628800.0, det);
}
// vim: cc=60 ts=2 sts=2 sw=2:
