/* Field testing: Timus 1047 */
void test() {
  long double eps = 1e-5;
  rep(it,0,5000) {
    int n = rand() % min(it+1, 4999) + 1;
    vector<long double> cX(n);
    rep(i,0,n) {
      A[i] = randdouble(-1000, 1000);
      B[i] = randdouble(-1000, 1000);
      C[i] = randdouble(-1000, 1000);
      cX[i] = randdouble(-1000, 1000);
      A[i] = round(A[i]*10000)/10000;
      B[i] = round(B[i]*10000)/10000;
      C[i] = round(C[i]*10000)/10000;
      cX[i] = round(cX[i]*10000)/10000;
    }
    A[0] = 0.0;
    C[n-1] = 0.0;
    if (n == 1) {
      D[0] = B[0] * cX[0];
    } else   {
      D[0] = B[0] * cX[0] + C[0] * cX[1];
      D[n-1] = A[n-1] * cX[n-2] + B[n-1] * cX[n-1];
      rep(i,1,n-1) {
        D[i] = A[i] * cX[i-1] + B[i] * cX[i] + C[i] * cX[i+1];
      }
    }
    solve(n);
    rep(i,0,n) {
      assert_true(abs(X[i] - cX[i]) < eps);
    }
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
