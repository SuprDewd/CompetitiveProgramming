template <class T>
class fraction {
private:
    T gcd(T a, T b) { return b == T(0) ? a : gcd(b, a % b); }
public:
    T n, d;
    fraction(T n_, T d_) {
        assert(d_ != 0);
        n = n_, d = d_;
        if (d < T(0)) n = -n, d = -d;
        T g = gcd(abs(n), abs(d));
        n /= g, d /= g; }
    fraction(T n_) : n(n_), d(1) { }
    fraction(const fraction<T>& other) : n(other.n), d(other.d) { }
    fraction<T> operator +(const fraction<T>& other) const {
        return fraction<T>(n * other.d + other.n * d, d * other.d);}
    fraction<T> operator -(const fraction<T>& other) const {
        return fraction<T>(n * other.d - other.n * d, d * other.d);}
    fraction<T> operator *(const fraction<T>& other) const {
        return fraction<T>(n * other.n, d * other.d); }
    fraction<T> operator /(const fraction<T>& other) const {
        return fraction<T>(n * other.d, d * other.n); }
    bool operator <(const fraction<T>& other) const {
        return n * other.d < other.n * d; }
    bool operator <=(const fraction<T>& other) const {
        return !(other < *this); }
    bool operator >(const fraction<T>& other) const {
        return other < *this; }
    bool operator >=(const fraction<T>& other) const {
        return !(*this < other); }
    bool operator ==(const fraction<T>& other) const {
        return n == other.n && d == other.d; }
    bool operator !=(const fraction<T>& other) const {
        return !(*this == other); }
};
