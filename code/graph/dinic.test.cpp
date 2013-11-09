#include "../code/graph/edmonds_karps.cpp"

void test1() {
    int N = 30;
    int MAX = 100000;

    vii *adj = new vii[N];
    flow_network mf(N);

    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            int cap = rand() % MAX + 1;
            adj[i].push_back(ii(j, cap));
            adj[j].push_back(ii(i, cap));
            adj[i].push_back(ii(j, cap));
            adj[j].push_back(ii(i, cap));
            mf.add_edge(i, j, cap, cap);
            mf.add_edge(i, j, cap, cap);
        }
    }

    /*
     * Compare each pair flow with Edmonds Karp's algorithm.
     */
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            assert_equal(max_flow(N, i, j, adj).first, mf.max_flow(i, j));
        }
    }

    delete[] adj;
}

void test() {
    /* Field testing: Uva10330, UVa10480, UVa12125 */

    flow_network mf(4, 4*4);
    mf.add_edge(0, 1, 133700);
    mf.add_edge(0, 2, 133700);
    mf.add_edge(1, 2, 1);
    mf.add_edge(1, 3, 133700);
    mf.add_edge(2, 3, 133700);
    assert_equal(2 * 133700, mf.max_flow(0, 3));

    mf = flow_network(5, 5*5);
    mf.add_edge(1, 2, 100);
    mf.add_edge(1, 3, 50);
    mf.add_edge(2, 3, 50);
    mf.add_edge(2, 4, 50);
    mf.add_edge(2, 0, 50);
    mf.add_edge(3, 4, 100);
    mf.add_edge(4, 0, 125);
    assert_equal(150, mf.max_flow(1, 0));

    mf = flow_network(5, 5*5);
    mf.add_edge(1, 2, 100);
    mf.add_edge(1, 3, 50);
    mf.add_edge(2, 3, 50);
    mf.add_edge(2, 4, 50);
    mf.add_edge(2, 0, 50);
    mf.add_edge(3, 4, 100);
    mf.add_edge(4, 0, 75);
    assert_equal(125, mf.max_flow(1, 0));

    mf = flow_network(5, 5*5);
    mf.add_edge(1, 2, 100);
    mf.add_edge(1, 3, 50);
    mf.add_edge(2, 4, 5);
    mf.add_edge(2, 0, 5);
    mf.add_edge(3, 4, 100);
    mf.add_edge(4, 0, 125);
    assert_equal(60, mf.max_flow(1, 0));

    test1();
}
