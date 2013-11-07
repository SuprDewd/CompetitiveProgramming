
void test() {
    int N = 5;
    int MAX = 100000;

    vii *adj = new vii[N];

    vector<vii> sep;

    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {

            sep = gomory_hu_tree(N, adj);
            for(int x = 0; x < N; ++x) {
                vector<int> ms = max_flow_all_pairs(x, sep);
                for(int y = 0; y < N; ++y) {
                    assert_equal(max_flow_min_cut(N, x, y, adj).second, ms[y]);
                }
            }

            int cap = rand() % MAX;
            adj[i].push_back(ii(j, cap));
            adj[j].push_back(ii(i, cap));
        }
    }

    sep = gomory_hu_tree(N, adj);

    for(int i = 0; i < N; ++i) {
        vector<int> ms = max_flow_all_pairs(i, sep);
        for(int j = 0; j < N; ++j) {
            assert_equal(max_flow_min_cut(N, i, j, adj).second, ms[j]);
        }
    }


    delete[] adj;
}
