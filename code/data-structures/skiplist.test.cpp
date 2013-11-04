#include "../code/data-structures/avl_tree.cpp"

void test() {
    /* Field testing: UVa 978, UVa 1513, UVa 12049 */

    int cnt = 10000,
        range = 1000,
        runs = 100;

    skiplist<int> t1;
    set<int> t2;

    assert_equal(0, t1.size());

    for (int i = 0; i < cnt; i++) {
        int n = rand() % range;
        skiplist<int>::node *p = t1.insert(n);
        assert_equal(n, p->item);
        t2.insert(n);
        assert_equal(size(t2), size(t1));

        int n1 = rand() % range;
        skiplist<int>::node *b = t1.find(n1);
        if (b) assert_equal(n1, b->item);
        assert_equal(b == NULL, t2.find(n1) == t2.end());

        int n2 = rand() % range;
        t1.erase(n2);
        t2.erase(n2);
        assert_equal(size(t2), size(t1));
    }

    t1.clear();
    t2.clear();

    assert_equal(0, t1.size());

    for (int i = 0; i < cnt; i++) {
        int n = rand() % range;
        skiplist<int>::node *p = t1.insert(n);
        assert_equal(n, p->item);
        t2.insert(n);
        assert_equal(size(t2), size(t1));

        int n1 = rand() % range;
        skiplist<int>::node *b = t1.find(n1);
        if (b) assert_equal(n1, b->item);
        assert_equal(b == NULL, t2.find(n1) == t2.end());

        int n2 = rand() % range;
        t1.erase(n2);
        t2.erase(n2);
        assert_equal(size(t2), size(t1));
    }

    for(int j = 0; j < runs; ++j) {
        t1.clear();
        t2.clear();

        assert_equal(0, t1.size());

        int cmp = rand() % range;
        int ls = 0;

        for (int i = 0; i < cnt; i++) {
            int n = rand() % range;
            if(t2.find(n) != t2.end()) continue;

            if(n < cmp) ls++;

            skiplist<int>::node *p = t1.insert(n);
            t2.insert(n);
            assert_equal(n, p->item);

            assert_equal(ls, t1.count_less(cmp));
        }
    }

    avl_tree<int> at;

    for(int j = 0; j < runs; ++j) {

        t1.clear();
        at.clear();
        assert_equal(0, t1.size());
        assert_equal(0, at.size());

        for (int i = 0; i < cnt; i++) {
            int n = rand() % range;

            // cout << "Inserting " << n << endl;

            skiplist<int>::node *p = t1.insert(n);
            at.insert(n);
            assert_equal(n, p->item);

            assert_equal(at.size(), t1.size());

            if(at.nth(n) == NULL) {
                assert_equal(true, t1.nth(n) == NULL);
            } else {
                assert_equal(at.nth(n)->item, t1.nth(n)->item);
            }
        }
    }
}
