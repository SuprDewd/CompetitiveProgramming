int bfs(int start, int end, vvi& adj_list) {
	set<int> visited;
	queue<ii> Q;
	Q.push(ii(start, 0));
	visited.insert(start);

	while (!Q.empty()) {
		ii cur = Q.front(); Q.pop();

		if (cur.first == end)
			return cur.second;

		vi& adj = adj_list[cur.first];
		for (vi::iterator it = adj.begin(); it != adj.end(); it++)
			if (visited.find(*it) == visited.end()) {
				Q.push(ii(*it, cur.second + 1));
				visited.insert(*it);
			}
	}

	return -1;
}