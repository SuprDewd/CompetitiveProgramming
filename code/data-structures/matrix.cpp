template <class K> bool eq(K a, K b) { return a == b; }
template <> bool eq<double>(double a, double b) { return abs(a - b) < EPS; }

template <class T>
class matrix {
private:
    vector<T> data;
    int cnt;
    inline T& at(int i, int j) { return data[i * cols + j]; }
public:
    int rows, cols;
    matrix(int r, int c) : rows(r), cols(c), cnt(r * c) { data.assign(cnt, T(0)); }
    matrix(const matrix& other) : rows(other.rows), cols(other.cols), cnt(other.cnt), data(other.data) { }
    T& operator()(int i, int j) { return at(i, j); }
    void operator +=(const matrix& other) {
        assert(rows == other.rows && cols == other.cols);
        for (int i = 0; i < cnt; i++) data[i] += other.data[i];
    }
    void operator -=(const matrix& other) {
        assert(rows == other.rows && cols == other.cols);
        for (int i = 0; i < cnt; i++) data[i] -= other.data[i];
    }
    void operator *=(T other) {
        for (int i = 0; i < cnt; i++) data[i] *= other;
    }
    matrix<T> operator +(const matrix& other) {
        matrix<T> res(*this); res += other; return res;
    }
    matrix<T> operator -(const matrix& other) {
        matrix<T> res(*this); res -= other; return res;
    }
    matrix<T> operator *(T other) {
        matrix<T> res(*this); res *= other; return res;
    }
    matrix<T> operator *(const matrix& other) {
        assert(cols == other.rows);
        matrix<T> res(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++)
                    res(i, j) += at(i, k) * other.data[k * other.cols + j];
        return res;
    }
    matrix<T> transpose() {
        matrix<T> res(cols, rows);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                res(j, i) = at(i, j);
        return res;
    }
    matrix<T> pow(int p) {
        assert(rows == cols);
        matrix<T> res(rows, cols), sq(*this);
        for (int i = 0; i < rows; i++) res(i, i) = 1;
        while (p) {
            if (p & 1) res = res * sq;
            p >>= 1;
            if (p) sq = sq * sq;
        }
        return res;
    }
    matrix<T> rref() {
        matrix<T> mat(*this);
        for (int r = 0, c = 0; c < cols; c++) {
            int k = r;
            while (k < rows && eq<T>(mat(k, c), T(0))) k++;
            if (k >= rows) continue;
            if (k != r) for (int i = 0; i < cols; i++) swap(mat.at(k, i), mat.at(r, i));
            if (!eq<T>(mat(r, c), T(1))) for (int i = cols-1; i >= c; i--) mat(r, i) /= mat(r, c);
            for (int i = 0; i < rows; i++) {
                T m = mat(i, c);
                if (i != r && !eq<T>(m, T(0)))
                    for (int j = 0; j < cols; j++)
                        mat(i, j) -= m * mat(r, j);
            }
            r++;
        }
        return mat;
    }
};
