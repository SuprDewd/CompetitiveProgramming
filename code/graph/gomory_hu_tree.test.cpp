
void test() {
    int N = 20;
    int MAX = 10000;

    flow_network g(N);
    pair<vii, vvi> gh;

    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            gh = construct_gh_tree(g);
            for(int x = 0; x < N; ++x) {
                for(int y = 0; y < N; ++y) {
                    assert_equal(g.max_flow(x, y), compute_max_flow(x, y, gh));
                }
            }

            int cap = rand() % MAX;
            g.add_edge(i, j, cap, cap);
        }
    }

    gh = construct_gh_tree(g);
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            assert_equal(g.max_flow(i, j), compute_max_flow(i, j, gh));
        }
    }
}

