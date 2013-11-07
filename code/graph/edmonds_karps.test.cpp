
void release(vector<vector<mf_edge*> > res) {
    for (int i = 0; i < size(res); i++)
        for (int j = 0; j < size(res[i]); j++)
            delete res[i][j];
}

void test() {
    /* Field testing: UVa259, UVa670, UVa10080, ICPC Live Archive 5905, ICPC Live Archive 3792 */

    pair<int, vector<vector<mf_edge*> > > res;

    vii* adj = new vii[4];
    adj[0].push_back(ii(1, 133700));
    adj[0].push_back(ii(2, 133700));
    adj[1].push_back(ii(2, 1));
    adj[1].push_back(ii(3, 133700));
    adj[2].push_back(ii(3, 133700));

    res = max_flow(4, 0, 3, adj);
    assert_equal(2 * 133700, res.first);
    release(res.second);
    delete[] adj;

    adj = new vii[5];
    adj[1].push_back(ii(2, 100));
    adj[1].push_back(ii(3, 50));
    adj[2].push_back(ii(3, 50));
    adj[2].push_back(ii(4, 50));
    adj[2].push_back(ii(0, 50));
    adj[3].push_back(ii(4, 100));
    adj[4].push_back(ii(0, 125));

    res = max_flow(5, 1, 0, adj);
    assert_equal(150, res.first);
    release(res.second);
    delete[] adj;

    adj = new vii[5];
    adj[1].push_back(ii(2, 100));
    adj[1].push_back(ii(3, 50));
    adj[2].push_back(ii(3, 50));
    adj[2].push_back(ii(4, 50));
    adj[2].push_back(ii(0, 50));
    adj[3].push_back(ii(4, 100));
    adj[4].push_back(ii(0, 75));

    res = max_flow(5, 1, 0, adj);
    assert_equal(125, res.first);
    release(res.second);
    delete[] adj;

    adj = new vii[5];
    adj[1].push_back(ii(2, 100));
    adj[1].push_back(ii(3, 50));
    adj[2].push_back(ii(4, 5));
    adj[2].push_back(ii(0, 5));
    adj[3].push_back(ii(4, 100));
    adj[4].push_back(ii(0, 125));

    res = max_flow(5, 1, 0, adj);
    assert_equal(60, res.first);
    release(res.second);
    delete[] adj;
}
