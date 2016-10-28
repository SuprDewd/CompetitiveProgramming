void test() {
  /* Field testing: NWERC 2012 Problem I, Kattis pieceittogether */
  /* TODO: UVa 11294, UVa 10319 */

  for (int n = 1; n <= 15; n++) {
    for (int iter = 0; iter < 100; iter++) {
      int cnt = randint(1, 100);
      vii clauses(cnt);
      for (int i = 0; i < cnt; i++) {
        int a = randint(1, n) * (randint(1, 2) == 1 ? 1 : -1);
        int b = randint(1, n) * (randint(1, 2) == 1 ? 1 : -1);
        clauses[i] = ii(a, b);
      }
      // cout << n << " " << iter << " " << cnt << endl;

      TwoSat ts(n);
      iter(it,clauses) {
        ts.add_or(it->first, it->second);
      }
      if (ts.sat()) {
        vector<bool> is_true(n+1, false);
        // for (int i = 0; i < size(all_truthy); i++) if (all_truthy[i] > 0) is_true[all_truthy[i]] = true;
        rep(i,0,n) if (V[n+(i+1)].val == 1) is_true[i+1] = true;
        for (int i = 0; i < cnt; i++) {
          bool a = is_true[abs(clauses[i].first)],
             b = is_true[abs(clauses[i].second)];
          assert_true((clauses[i].first > 0 ? a : !a) || (clauses[i].second > 0 ? b : !b), true);
        }
      } else {
        for (int j = 0; j < (1<<n); j++) {

          bool ok = true;
          for (int i = 0; i < cnt; i++) {
            bool a = j & (1 << (abs(clauses[i].first) - 1)),
               b = j & (1 << (abs(clauses[i].second) - 1));
            ok = ok && ((clauses[i].first > 0 ? a : !a) || (clauses[i].second > 0 ? b : !b));
          }

          assert_false(ok, true);
        }
      }
    }
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
