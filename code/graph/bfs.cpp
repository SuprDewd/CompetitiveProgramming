int bfs(int start, int end, vvi& adj_list) {
    queue<ii> Q;
    Q.push(ii(start, 0));
    while (true) {
        ii cur = Q.front(); Q.pop();
        if (cur.first == end) return cur.second;
        vi& adj = adj_list[cur.first];
        iter(it,adj) Q.push(ii(*it, cur.second + 1));
    }
}
