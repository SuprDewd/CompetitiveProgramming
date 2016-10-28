
intx randint(int len) {
  stringstream ss;
  ss << rand() % 9 + 1;
  for (int i = 0; i < len-1; i++)
    ss << rand() % 10;

  return intx(ss.str());
}

void test() {
  /* Field testing: SPOJ {MUL,TMUL,VFMUL} */

  srand(1337); // TODO: remove this

  int ts = 1000,
    l1 = 1,
    l2 = 1000;

  for (int t = 0; t < ts; t++) {
    // printf("%d\n", t);

    int la = rand() % (l2 - l1 + 1) + l1,
      lb = rand() % (l2 - l1 + 1) + l1;

    intx a = randint(la),
       b = randint(lb),
       c1 = a * b,
       c2 = fastmul(a, b);

    bool same = !(c1 < c2 || c2 < c1);
    assert_true(same);
  }
}

// vim: cc=60 ts=2 sts=2 sw=2:
