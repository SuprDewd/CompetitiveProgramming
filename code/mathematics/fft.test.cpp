#include "../code/mathematics/intx.cpp"

intx fastmul(intx an, intx bn)
{
  stringstream ss;
  ss << an;
  string as = ss.str();

  ss.str("");
  ss << bn;
  string bs = ss.str();

  int n = size(as),
    m = size(bs),
    len = 5,
    radix = 100000;

  int *a = new int[n],
    *b = new int[m];

  int alen = 0, blen = 0;
  for (int i = n - 1; i >= 0; i -= len)
  {
    int x = 0;
    for (int j = len - 1; j >= 0; j--)
    {
      if (i - j < 0) continue;
      x = x * 10 + as[i - j] - '0';
    }

    a[alen++] = x;
  }

  for (int i = m - 1; i >= 0; i -= len)
  {
    int x = 0;
    for (int j = len - 1; j >= 0; j--)
    {
      if (i - j < 0) continue;
      x = x * 10 + bs[i - j] - '0';
    }

    b[blen++] = x;
  }

  int l = 1;
  while (l < alen || l < blen) l <<= 1;
  l <<= 1;

  cpx *A = new cpx[l];
  cpx *B = new cpx[l];

  for (int i = 0; i < l; i++) A[i] = cpx(i < alen ? a[i] : 0, 0);
  for (int i = 0; i < l; i++) B[i] = cpx(i < blen ? b[i] : 0, 0);

  fft(A, l);
  fft(B, l);
  for (int i = 0; i < l; i++) A[i] *= B[i];
  fft(A, l, true);

  unsigned long long *data = new unsigned long long[l];
  for (int i = 0; i < l; i++) data[i] = (unsigned long long)(round(real(A[i])));
  for (int i = 0; i < l - 1; i++)
    if (data[i] >= (unsigned int)(radix)) {
      data[i+1] += data[i] / radix;
      data[i] %= radix;
    }

  int stop = l-1;
  while (stop > 0 && data[stop] == 0) stop--;

  ss.str("");
  ss << data[stop];
  for (int i = stop - 1; i >= 0; i--)
    ss << setfill('0') << setw(len) << data[i];

  delete[] A;
  delete[] B;
  delete[] a;
  delete[] b;
  delete[] data;

  return intx(ss.str());
}

intx randint(int len)
{
  stringstream ss;
  ss << rand() % 9 + 1;
  for (int i = 0; i < len-1; i++)
    ss << rand() % 10;

  return intx(ss.str());
}

void test() {
  /* Field testing: Kattis {polymul1,polymul2}, SPOJ {MUL,TMUL,VFMUL} */

  int ts = 100,
    l1 = 1,
    l2 = 1000;

  for (int t = 0; t < ts; t++)
  {
    int la = rand() % (l2 - l1 + 1) + l1,
      lb = rand() % (l2 - l1 + 1) + l1;

    intx a = randint(la),
       b = randint(lb),
       c1 = a * b,
       c2 = fastmul(a, b);

    bool same = !(c1 < c2 || c2 < c1);
    assert_true(same);
  }
}

// vim: cc=60 ts=2 sts=2 sw=2:
