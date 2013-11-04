double integrate(double (*f)(double), double a, double b, double delta = 1) {
    if(abs(a - b) < delta) return (b-a)/6 * (f(a) + 4 * f((a+b)/2) + f(b));
    return integrate(f, a, (a+b)/2, delta) + integrate(f, (a+b)/2, b, delta);
}
