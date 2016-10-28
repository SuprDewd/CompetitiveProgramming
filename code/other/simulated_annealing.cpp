double curtime() {
  return static_cast<double>(clock()) / CLOCKS_PER_SEC; }
int simulated_annealing(int n, double seconds) {
  default_random_engine rng;
  uniform_real_distribution<double> randfloat(0.0, 1.0);
  uniform_int_distribution<int> randint(0, n - 2);
  // random initial solution
  vi sol(n);
  rep(i,0,n) sol[i] = i + 1;
  random_shuffle(sol.begin(), sol.end());
  // initialize score
  int score = 0;
  rep(i,1,n) score += abs(sol[i] - sol[i-1]);
  int iters = 0;
  double T0 = 100.0, T1 = 0.001,
      progress = 0, temp = T0,
      starttime = curtime();
  while (true) {
    if (!(iters & ((1 << 4) - 1))) {
      progress = (curtime() - starttime) / seconds;
      temp = T0 * pow(T1 / T0, progress);
      if (progress > 1.0) break; }
    // random mutation
    int a = randint(rng);
    // compute delta for mutation
    int delta = 0;
    if (a > 0) delta += abs(sol[a+1] - sol[a-1])
                      - abs(sol[a] - sol[a-1]);
    if (a+2 < n) delta += abs(sol[a] - sol[a+2])
                        - abs(sol[a+1] - sol[a+2]);
    // maybe apply mutation
    if (delta >= 0 || randfloat(rng) < exp(delta / temp)) {
      swap(sol[a], sol[a+1]);
      score += delta;
      // if (score >= target) return;
    }
    iters++; }
  return score; }
// vim: cc=60 ts=2 sts=2 sw=2:
