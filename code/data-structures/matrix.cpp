template <class T>
class matrix {
private:
    vector<T> data;
    int cnt;
    inline T& at(int i, int j) {
        return data[i * cols + j];
    }

public:
    int rows, cols;

    matrix(int r, int c) {
        rows = r; cols = c;
        data = vector<T>(cnt = rows * cols);
        for (int i = 0; i < cnt; i++)
            data[i] = T(0);
    }

    matrix(const matrix& other) {
        rows = other.rows; cols = other.cols;
        data = vector<T>(cnt = rows * cols);
        for (int i = 0; i < cnt; i++)
            data[i] = other.data[i];
    }

    T& operator()(int i, int j) {
        return at(i, j);
    }

    void operator +=(const matrix& other) {
        assert(rows == other.rows && cols == other.cols);
        for (int i = 0; i < cnt; i++)
            data[i] += other.data[i];
    }

    void operator -=(const matrix& other) {
        assert(rows == other.rows && cols == other.cols);
        for (int i = 0; i < cnt; i++)
            data[i] -= other.data[i];
    }

    void operator *=(T other) {
        for (int i = 0; i < cnt; i++)
            data[i] *= other;
    }

    matrix<T> operator +(const matrix& other) {
        matrix<T> res(*this);
        res += other;
        return res;
    }

    matrix<T> operator -(const matrix& other) {
        matrix<T> res(*this);
        res -= other;
        return res;
    }

    matrix<T> operator *(T other) {
        matrix<T> res(*this);
        res *= other;
        return res;
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
        for (int i = 0; i < rows; i++)
            res(i, i) = 1;

        while (p) {
            if (p & 1) res = res * sq;
            p >>= 1;
            if (p) sq = sq * sq;
        }

        return res;
    }

    matrix<T> triangular_form() {
        matrix<T> res(*this);
        for (int k = 0; k < res.rows; k++) {
            int i_max = k;
            for (int i = k + 1; i < res.rows; i++) {
                if (res.at(i_max, k) < res.at(i, k)) {
                    i_max = i;
                }
            }

            assert(res.at(i_max, k) != T(0));

            for (int j = 0; j < res.cols; j++) {
                swap(res.at(k, j), res.at(i_max, j));
                //T tmp = res.at(k, j);
                //res.at(k, j) = res.at(i_max, j);
                //res.at(i_max, j) = tmp;
            }

            for (int i = k + 1; i < res.rows; i++) {
                for (int j = k + 1; j < res.cols; j++) {
                    res.at(i, j) -= res.at(k, j) * res.at(i, k) / res.at(k, k);
                }

                res.at(i, k) = T(0);
            }

            for (int j = res.cols - 1; j >= k; j--)
            {
                res.at(k, j) /= res.at(k, k);
            }
        }

        return res;
    }
};
