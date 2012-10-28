class union_find {
private:
	int* parent;
	int cnt;

public:
	union_find(int n) {
		parent = new int[cnt = n];
		for (int i = 0; i < cnt; i++)
			parent[i] = i;
	}

	union_find(const union_find& other) {
		parent = new int[cnt = other.cnt];
		for (int i = 0; i < cnt; i++)
			parent[i] = other.parent[i];
	}

	~union_find() {
		if (parent) {
			delete[] parent;
			parent = NULL;
		}
	}

	int find(int i) {
		assert(parent != NULL);
		return parent[i] == i ? i : (parent[i] = find(parent[i]));
	}

	bool unite(int i, int j) {
		assert(parent != NULL);

		int ip = find(i),
			jp = find(j);

		parent[ip] = jp;
		return ip != jp;
	}
};