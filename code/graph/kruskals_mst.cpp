#include "../data-structures/union_find.cpp"

// n is the number of vertices
// edges is a list of edges of the form (weight, (a, b))
// the edges in the minimum spanning tree are returned on the same form
vector<pair<int, ii> > mst(int n, vector<pair<int, ii> > edges) {
    union_find uf(n);
    sort(edges.begin(), edges.end());
    vector<pair<int, ii> > res;
    for (int i = 0; i < size(edges); i++)
        if (uf.find(edges[i].second.first) != uf.find(edges[i].second.second)) {
            res.push_back(edges[i]);
            uf.unite(edges[i].second.first, edges[i].second.second);
        }
    return res;
}
