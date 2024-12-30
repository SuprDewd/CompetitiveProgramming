
intx randint(int len) {
  stringstream ss;
  ss << rng() % 9 + 1;
  for (int i = 0; i < len-1; i++)
    ss << rng() % 10;

  return intx(ss.str());
}

void test() {
  /* Field testing: SPOJ {MUL,TMUL,VFMUL} */

  int ts = 1000,
    l1 = 1,
    l2 = 1000;

  for (int t = 0; t < ts; t++) {
    // printf("%d\n", t);

    int la = uniform_int_distribution(l1, l2)(rng),
      lb = uniform_int_distribution(l1, l2)(rng);

    intx a = randint(la),
       b = randint(lb),
       c1 = a * b,
       c2 = fastmul(a, b);

    bool same = !(c1 < c2 || c2 < c1);
    assert_true(same);
  }
}

// vim: cc=60 ts=2 sts=2 sw=2:
