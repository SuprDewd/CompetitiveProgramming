stack<int> t_s;
set<int> t_z;
int t_index;
int* t_idx;
int* t_ll;

void t_strongconnect(int v, vvi& adj) {
	t_idx[v] = t_ll[v] = t_index++;
	t_s.push(v);
	t_z.insert(v);

	int cnt = size(adj[v]);
	for (int i = 0; i < cnt; i++) {
		int w = adj[v][i];
		if (t_idx[w] == -1) {
			t_strongconnect(w, adj);
			t_ll[v] = min(t_ll[v], t_ll[w]);
		} else if (t_z.find(w) != t_z.end())
			t_ll[v] = min(t_ll[v], t_idx[w]);
	}

	if (t_ll[v] == t_idx[v])
		while (true) {
			// Vertices from top of stack down to v form a SCC
			int w = t_s.top(); t_s.pop(); t_z.erase(t_z.find(w));
			if (w == v) break;
		}
}

int* tarjan_scc(vvi adj) {
	int n = size(adj);
	t_idx = new int[n];
	t_ll = new int[n];
	t_index = 0;

	for (int i = 0; i < n; i++)
		t_idx[i] = t_ll[i] = -1;

	for (int i = 0; i < n; i++)
		if (t_idx[i] == -1)
			t_strongconnect(i, adj);

	delete[] t_idx;
	return t_ll;
}