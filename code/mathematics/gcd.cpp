int _gcd_(int a, int b) {
    return b == 0 ? a : _gcd_(b, a % b);
}

int gcd(int a, int b) {
    return (a < 0 && b < 0 ? -1 : 1) * _gcd_(abs(a), abs(b));
}
