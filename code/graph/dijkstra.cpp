#define MAXEDGES 20000
bool done[MAXEDGES];

int dijkstra(int start, int end, vvii& adj_list) {
	memset(done, 0, MAXEDGES);
	priority_queue<ii, vii, greater<ii> > pq;
	pq.push(ii(0, start));
	
	while (!pq.empty()) {
		ii current = pq.top(); pq.pop();
		done[current.second] = true;
		
		if (current.second == end) 
			return current.first;

		vii &vtmp = adj_list[current.second];
		for (vii::iterator it=vtmp.begin(); it != vtmp.end(); it++)
			if (!done[it->second])
				pq.push(ii(current.first + it->first, it->second));
	}
	return -1;
}