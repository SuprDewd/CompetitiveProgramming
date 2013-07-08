#include "../graph/scc.cpp"

bool two_sat(int n, const vii& clauses, vi& all_truthy) {
    all_truthy.clear();
    vvi adj(2*n+1);
    for (int i = 0, cnt = size(clauses); i < cnt; i++) {
        adj[-clauses[i].first + n].push_back(clauses[i].second + n);
        if (clauses[i].first != clauses[i].second)
            adj[-clauses[i].second + n].push_back(clauses[i].first + n);
    }
    pair<union_find, vi> res = scc(adj);
    union_find scc = res.first;
    vi dag = res.second;
    vi truth(2*n+1, -1);
    for (int i = 2*n; i >= 0; i--) {
        int cur = order[i] - n, p = scc.find(cur + n), o = scc.find(-cur + n);
        if (cur == 0) continue;
        if (p == o) return false;
        if (truth[p] == -1) truth[p] = 1;
        truth[cur + n] = truth[p];
        truth[o] = 1 - truth[p];
        if (truth[p] == 1) all_truthy.push_back(cur);
    }
}
