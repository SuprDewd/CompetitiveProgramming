int dijkstra(int start, int end, vvii& adj_list) {
	set<int> done;
	priority_queue<ii, vii, greater<ii> > pq;
	pq.push(ii(0, start));
	
	while (!pq.empty()) {
		ii current = pq.top(); pq.pop();

		if (done.find(current.second) != done.end())
			continue;

		if (current.second == end)
			return current.first;

		done.insert(current.second);

		vii &vtmp = adj_list[current.second];
		for (vii::iterator it = vtmp.begin(); it != vtmp.end(); it++)
			if (done.find(it->second) == done.end())
				pq.push(ii(current.first + it->first, it->second));
	}
	
	return -1;
}