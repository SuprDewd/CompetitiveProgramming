
void test() {
  /* Field testing: SPOJ STABLEMP */

  int ts = 100,
    maxn = 300;

  int **m = new int*[maxn],
    **w = new int*[maxn],
    **minv = new int*[maxn],
    **winv = new int*[maxn];

  for (int i = 0; i < maxn; i++) {
    m[i] = new int[maxn];
    w[i] = new int[maxn];
    minv[i] = new int[maxn];
    winv[i] = new int[maxn];
  }

  for (int t = 0; t < ts; t++) {

    int n = rand() % maxn;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        m[i][j] = w[i][j] = j;
      }

      random_shuffle(m[i], m[i] + n);
      random_shuffle(w[i], w[i] + n);

      for (int j = 0; j < n; j++) {
        minv[i][m[i][j]] = j;
        winv[i][w[i][j]] = j;
      }
    }

    vi res = stable_marriage(n, m, w);
    vi rev(n, -1);

    for (int i = 0; i < n; i++) {
      assert_equal(-1, rev[res[i]]);
      rev[res[i]] = i;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        assert_true( minv[i][res[i]] < minv[i][res[j]] || winv[res[j]][j] < winv[res[j]][i] );
      }
    }
  }
}

// vim: cc=60 ts=2 sts=2 sw=2:
