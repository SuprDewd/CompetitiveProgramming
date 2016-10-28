ii find_cycle(int x0, int (*f)(int)) {
  int t = f(x0), h = f(t), mu = 0, lam = 1;
  while (t != h) t = f(t), h = f(f(h));
  h = x0;
  while (t != h) t = f(t), h = f(h), mu++;
  h = f(t);
  while (t != h) h = f(h), lam++;
  return ii(mu, lam); }
// vim: cc=60 ts=2 sts=2 sw=2:
