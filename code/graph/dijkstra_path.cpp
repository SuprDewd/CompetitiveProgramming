map<int, ii> dijkstra_path(int start, vvii& adj_list) {
	map<int, ii> parent;
	priority_queue<ii, vii, greater<ii> > pq;
	pq.push(ii(0, start));
	parent[start] = ii(0, start);
	
	while (!pq.empty()) {
		ii cur = pq.top(); pq.pop();

		if (cur.first > parent[cur.second].first)
			continue;

		vii &vtmp = adj_list[cur.second];
		for (vii::iterator it = vtmp.begin(); it != vtmp.end(); it++) {
			if (parent.find(it->second) == parent.end() || parent[it->second].first > cur.first + it->first) {
				parent[it->second] = ii(cur.first + it->first, cur.second);
				pq.push(ii(cur.first + it->first, it->second));
			}
		}
	}
	
	return parent;
}