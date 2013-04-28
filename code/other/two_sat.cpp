/* TODO: implement linear version using Tarjan's SCC algorithm */
bool two_sat(int n, const vii& clauses, vi& all_truthy) {
	all_truthy.clear();
	vi* adj = new vi[2 * n + 1];
	for (int i = 0, cnt = size(clauses); i < cnt; i++) {
		adj[-clauses[i].first + n].push_back(clauses[i].second);
		if (clauses[i].first != clauses[i].second)
			adj[-clauses[i].second + n].push_back(clauses[i].first);
	}

	char* ass = new char[2 * n + 1];
	bool* negpath = new bool[2 * n + 1];
	for (int i = -n; i <= n; i++) {
		if (i == 0) continue;
		memset(ass, 0, 2 * n + 1);
		negpath[i + n] = false;
		ass[i + n] = true;
		queue<int> Q;
		Q.push(i);
		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			for (int j = 0, cnt = size(adj[cur + n]); j < cnt; j++) {
				int nxt = adj[cur + n][j];
				if (nxt == -i) {
					negpath[i + n] = true;
					break;
				}
				if (!ass[nxt + n]) {
					ass[nxt + n] = true;
					Q.push(nxt);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (negpath[i + n] && negpath[-i + n]) {
			delete[] ass;
			delete[] negpath;
			delete[] adj;
			return false;
		}
	
	memset(ass, 0, 2 * n + 1);
	for (int i = -n; i <= n; i++) {
		if (i == 0 || ass[i + n] != 0 || negpath[i + n]) continue;
		ass[i + n] = 1;
		assert(ass[-i + n] != 1);
		ass[-i + n] = 2;
		queue<int> Q;
		Q.push(i);
		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			for (int j = 0, cnt2 = size(adj[cur + n]); j < cnt2; j++) {
				int nxt = adj[cur + n][j];
				if (ass[nxt + n] != 0) { assert(ass[nxt + n] == 1); continue; }
				ass[nxt + n] = 1;
				assert(ass[-nxt + n] != 1);
				ass[-nxt + n] = 2;
				Q.push(nxt);
			}
		}
	}

	for (int i = -n; i <= n; i++) {
		if (i == 0 || ass[i + n] != 1) continue;
		all_truthy.push_back(i);
	}

	delete[] ass;
	delete[] negpath;
	delete[] adj;
	return true;
}
