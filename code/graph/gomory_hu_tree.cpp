#include "edmonds_karps.cpp"
vector<int> max_flow_all_pairs(int s, vector<vii> &adj) {
    vector<int> flows(size(adj));
    int *back = new int[size(adj)];
    memset(back, -1, sizeof(int) * size(adj));
    queue<ii> Q; Q.push(ii(s, INF));
    while (!Q.empty()) {
        ii bla = Q.front(); Q.pop();
        int cur = bla.first;
        for (int i = 0; i < size(adj[cur]); i++) {
            ii nxt = adj[cur][i];
            if (back[nxt.first] == -1 && nxt.first != s) {
                flows[nxt.first] = min(bla.second, nxt.second);
                back[nxt.first] = cur;
                Q.push(ii(nxt.first, min(bla.second, nxt.second)));
            } } }
    delete[] back;
    return flows;
}
pair<set<int>, int> max_flow_min_cut(int n, int s, int t, vii *adj) {
    pair<int, vector<vector<mf_edge*> > > mf = max_flow(n, s, t, adj);
    int *back = new int[n];
    memset(back, -1, sizeof(int) * n);
    queue<int> Q; Q.push(s);
    set<int> cut;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        cut.insert(cur);
        for (int i = 0; i < size(mf.second[cur]); i++) {
            mf_edge *nxt = mf.second[cur][i];
            if (back[nxt->v] == -1 && nxt->w > 0) {
                back[nxt->v] = cur;
                Q.push(nxt->v);
            } } }
    delete[] back;
    for(int i = 0; i < size(mf.second); i++)
        for(int j = 0; j < size(mf.second[i]); j++)
            delete mf.second[i][j];
    return make_pair(cut, mf.first);
}
vector<vii> gomory_hu_tree(int n, vii *adj) {
    assert(n >= 0);
    vector<vii> T(n);
    if(n == 1) T[0].push_back(ii(0, 0));
    if(n < 2) return T;
    map<ii, set<int> > cuts;
    pair<set<int>, int> m = max_flow_min_cut(n, 0, 1, adj);
    cuts[ii(0, 1)] = m.first;
    T[0].push_back(ii(1, m.second));
    T[1].push_back(ii(0, m.second));
    int *back = new int[n];
    int t1 = 0, t2 = -1;
    vector<pair<int, ii> > edges;
    for(int k = 2; k < n; ++k) {
        while(true) {
            int alpha = -1, beta = -1, m_arc = INF;
            memset(back, -1, sizeof(int) * n);
            queue<int> Q; Q.push(t1);
            while (!Q.empty()) {
                int cur = Q.front(); Q.pop();
                for (int i = 0, len = size(T[cur]); i < len; i++) {
                    ii nxt = T[cur][i];
                    if(T[cur][i].second < m_arc) {
                        m_arc = T[cur][i].second;
                        alpha = cur;
                        beta = T[cur][i].first;
                    }
                    if (back[nxt.first] == -1) {
                        back[nxt.first] = cur;
                        Q.push(nxt.first);
                    } } }
            if(alpha > beta) swap(alpha, beta);
            if(cuts[ii(alpha, beta)].find(k) != cuts[ii(alpha, beta)].end())
                t1 = alpha, t2 = beta;
            else
                t1 = beta, t2 = alpha;
            T[t1].erase(find(T[t1].begin(), T[t1].end(), ii(t2, m_arc)));
            edges.push_back(make_pair(t1, ii(t2, m_arc)));
            if(T[t1].size() == 0) {
                for(int i = 0; i < edges.size(); ++i)
                    T[edges[i].first].push_back(ii(edges[i].second.first, edges[i].second.second));
                edges.clear();
                pair<set<int>, int> m = max_flow_min_cut(n, t1, k, adj);
                cuts[ii(t1, k)] = m.first;
                T[t1].push_back(ii(k, m.second));
                T[k].push_back(ii(t1, m.second));
                break;
            } } }
    delete[] back;
    return T;
}
