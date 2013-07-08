void test() {
    /* Field testing: NWERC 2012 Problem I, UVa 11294, UVa 10319 */

    for (int n = 1; n <= 20; n++) {
        for (int iter = 0; iter < 1000; iter++) {
            int cnt = randint(1, 4);
            vii clauses(cnt);
            for (int i = 0; i < cnt; i++) {
                int a = randint(1, n) * (randint(1, 2) == 1 ? 1 : -1);
                int b = randint(1, n) * (randint(1, 2) == 1 ? 1 : -1);
                clauses[i] = ii(a, b);
            }

            vi all_truthy;
            if (two_sat(n, clauses, all_truthy)) {
                vector<bool> is_true(n+1, false);
                for (int i = 0; i < size(all_truthy); i++) if (all_truthy[i] > 0) is_true[all_truthy[i]] = true;
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
