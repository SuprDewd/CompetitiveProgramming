void test() {
    // Field testing: https://icpc.kattis.com/problems/checks
    rep(its,0,1000) {
        int n = rand() % 20 + 1,
            m = rand() % (4*n);
        vector<vi> cl;
        rep(i,0,m) {
            vi cur;
            while (cur.empty()) rep(j,0,n) {
                if (rand() % 4 == 0) {
                    if (rand() % 2 == 0) {
                        cur.push_back(-(j+1));
                    } else {
                        cur.push_back(j+1);
                    }
                }
            }
            cl.push_back(cur);
        }

        bool poss = false;
        rep(s,0,1<<n) {
            bool ok = true;
            rep(i,0,m) {
                bool found = false;
                iter(it,cl[i]) {
                    int t = abs(*it) - 1;
                    if (((s & (1<<t)) != 0) == (*it > 0)) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                poss = true;
                break;
            }
        }

        SAT sat;
        rep(i,0,n) sat.var();
        iter(it,cl) {
            sat.clause(*it);
        }

        bool found = sat.solve();

        assert_equal(poss, found);

        if (found) {
            rep(j,0,n) {
                assert_not_equal(sat.get_value(j+1), sat.get_value(-(j+1)));
            }

            rep(i,0,m) {
                bool any = false;
                iter(it,cl[i]) {
                    if (sat.get_value(*it)) {
                        any = true;
                    }
                }
                assert_true(any);
            }
        }
    }

}
