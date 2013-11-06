int egcd(int a, int b, int& x, int& y) {
    if (b == 0) { x = 1; y = 0; return a; }
    else {
        int d = egcd(b, a % b, x, y);
        x -= a / b * y;
        swap(x, y);
        return d;
    }
}
