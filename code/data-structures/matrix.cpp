template <class K> bool eq(K a, K b) { return a == b; }
template <> bool eq<double>(double a, double b) { return abs(a - b) < EPS; }
template <class T>
class matrix {
public:
    int rows, cols;
    matrix(int r, int c) : rows(r), cols(c), cnt(r * c) {
        data.assign(cnt, T(0)); }
    matrix(const matrix& other) : rows(other.rows), cols(other.cols),
        cnt(other.cnt), data(other.data) { }
    T& operator()(int i, int j) { return at(i, j); }
    void operator +=(const matrix& other) {
        rep(i,0,cnt) data[i] += other.data[i]; }
    void operator -=(const matrix& other) {
        rep(i,0,cnt) data[i] -= other.data[i]; }
    void operator *=(T other) {
        rep(i,0,cnt) data[i] *= other; }
    matrix<T> operator +(const matrix& other) {
        matrix<T> res(*this); res += other; return res; }
    matrix<T> operator -(const matrix& other) {
        matrix<T> res(*this); res -= other; return res; }
    matrix<T> operator *(T other) {
        matrix<T> res(*this); res *= other; return res; }
    matrix<T> operator *(const matrix& other) {
        matrix<T> res(rows, other.cols);
        rep(i,0,rows) rep(j,0,other.cols) rep(k,0,cols)
                res(i, j) += at(i, k) * other.data[k * other.cols + j];
        return res; }
    matrix<T> transpose() {
        matrix<T> res(cols, rows);
        rep(i,0,rows) rep(j,0,cols) res(j, i) = at(i, j);
        return res; }
    matrix<T> pow(int p) {
        matrix<T> res(rows, cols), sq(*this);
        rep(i,0,rows) res(i, i) = T(1);
        while (p) {
            if (p & 1) res = res * sq;
            p >>= 1;
            if (p) sq = sq * sq;
        } return res; }
    matrix<T> rref(T &det) {
        matrix<T> mat(*this); det = T(1);
        for (int r = 0, c = 0; c < cols; c++) {
            int k = r;
            while (k < rows && eq<T>(mat(k, c), T(0))) k++;
            if (k >= rows) continue;
            if (k != r) {
                det *= T(-1);
                rep(i,0,cols)
                    swap(mat.at(k, i), mat.at(r, i));
            } det *= mat(r, r);
            T d = mat(r,c);
            rep(i,0,cols) mat(r, i) /= d;
            rep(i,0,rows) {
                T m = mat(i, c);
                if (i != r && !eq<T>(m, T(0)))
                    rep(j,0,cols) mat(i, j) -= m * mat(r, j);
            } r++;
        } return mat; }
private:
    int cnt;
    vector<T> data;
    inline T& at(int i, int j) { return data[i * cols + j]; }
};
