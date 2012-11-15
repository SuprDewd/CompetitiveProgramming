int* bellman_ford(int n, int s, vii* adj, bool& has_negative_cycle) {
	has_negative_cycle = false;
	int* dist = new int[n];
	for (int i = 0; i < n; i++)
		dist[i] = INF;
	dist[s] = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0, len = size(adj[j]); k < len; k++)
				dist[adj[j][k].first] = min(dist[adj[j][k].first], dist[j] + adj[j][k].second);
	for (int j = 0; j < n; j++)
		for (int k = 0, len = size(adj[j]); k < len; k++)
			if (dist[j] + adj[j][k].second < dist[adj[j][k].first])
				has_negative_cycle = true;
	return dist;
}