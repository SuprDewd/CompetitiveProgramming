#include "intx.cpp"
#include "fft.cpp"
intx fastmul(const intx &an, const intx &bn) {
  string as = an.to_string(), bs = bn.to_string();
  int n = size(as), m = size(bs), l = 1,
    len = 5, radix = 100000,
    *a = new int[n], alen = 0,
    *b = new int[m], blen = 0;
  memset(a, 0, n << 2);
  memset(b, 0, m << 2);
  for (int i = n - 1; i >= 0; i -= len, alen++)
    for (int j = min(len - 1, i); j >= 0; j--)
      a[alen] = a[alen] * 10 + as[i - j] - '0';
  for (int i = m - 1; i >= 0; i -= len, blen++)
    for (int j = min(len - 1, i); j >= 0; j--)
      b[blen] = b[blen] * 10 + bs[i - j] - '0';
  while (l < 2*max(alen,blen)) l <<= 1;
  cpx *A = new cpx[l], *B = new cpx[l];
  rep(i,0,l) A[i] = cpx(i < alen ? a[i] : 0, 0);
  rep(i,0,l) B[i] = cpx(i < blen ? b[i] : 0, 0);
  fft(A, l); fft(B, l);
  rep(i,0,l) A[i] *= B[i];
  fft(A, l, true);
  ull *data = new ull[l];
  rep(i,0,l) data[i] = (ull)(round(real(A[i])));
  rep(i,0,l-1)
    if (data[i] >= (unsigned int)(radix)) {
      data[i+1] += data[i] / radix;
      data[i] %= radix; }
  int stop = l-1;
  while (stop > 0 && data[stop] == 0) stop--;
  stringstream ss;
  ss << data[stop];
  for (int i = stop - 1; i >= 0; i--)
    ss << setfill('0') << setw(len) << data[i];
  delete[] A; delete[] B;
  delete[] a; delete[] b;
  delete[] data;
  return intx(ss.str()); }
// vim: cc=60 ts=2 sts=2 sw=2:
