int bfs(int start, int end, vector<vi> adj_list) {
	queue<ii> Q;
	Q.push(ii(start, 0));

	while (true) {
		ii cur = Q.top(); Q.pop();

		if (cur.first == end) {
			return cur.second;
		}

		vi& adj = adj_list[cur.first];
		for (vi::iterator it = adj.begin(); it != adj.end(); it++) {
			Q.push(ii(*it, cur.second + 1));
		}
	}
}