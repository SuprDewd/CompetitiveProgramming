#include <complex>
typedef complex<long double> cpx;
// NOTE: n must be a power of two
void fft(cpx *x, int n, bool inv=false) {
    for (int i = 0, j = 0; i < n; i++) {
        if (i < j) swap(x[i], x[j]);
        int m = n>>1;
        while (1 <= m && m <= j) j -= m, m >>= 1;
        j += m;
    }
    for (int mx = 1; mx < n; mx <<= 1) {
        cpx wp = exp(cpx(0, (inv ? -1 : 1) * pi / mx)), w = 1;
        for (int m = 0; m < mx; m++, w *= wp) {
            for (int i = m; i < n; i += mx << 1) {
                cpx t = x[i + mx] * w;
                x[i + mx] = x[i] - t;
                x[i] += t;
            }
        }
    }
    if (inv) for (int i = 0; i < n; i++) x[i] /= cpx(n);
}
void czt(cpx *x, int n, bool inv=false) {
    int len = 2*n+1;
    while (len & (len - 1)) len &= len - 1;
    len <<= 1;
    cpx w = exp(-2.0L * pi / n * cpx(0,1)),
        *c = new cpx[n], *a = new cpx[len],
        *b = new cpx[len];
    for (int i = 0; i < n; i++) c[i] = pow(w, (inv ? -1.0 : 1.0)*i*i/2);
    for (int i = 0; i < n; i++) a[i] = x[i] * c[i], b[i] = 1.0L/c[i];
    for (int i = 0; i < n - 1; i++) b[len - n + i + 1] = 1.0L/c[n-i-1];
    fft(a, len); fft(b, len);
    for (int i = 0; i < len; i++) a[i] *= b[i];
    fft(a, len, true);
    for (int i = 0; i < n; i++) {
        x[i] = c[i] * a[i];
        if (inv) x[i] /= cpx(n);
    }
    delete[] a;
    delete[] b;
    delete[] c;
}
