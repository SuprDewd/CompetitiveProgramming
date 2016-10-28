double integrate(double (*f)(double), double a, double b,
    double delta = 1e-6) {
  if (abs(a - b) < delta)
    return (b-a)/8 *
      (f(a) + 3*f((2*a+b)/3) + 3*f((a+2*b)/3) + f(b));
  return integrate(f, a,
      (a+b)/2, delta) + integrate(f, (a+b)/2, b, delta); }
// vim: cc=60 ts=2 sts=2 sw=2:
