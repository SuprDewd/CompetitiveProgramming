void uf_init(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}
}

int uf_find(int* arr, int i) {
	return arr[i] == i ? i : (arr[i] = uf_find(arr, arr[i]));
}

void uf_union(int* arr, int i, int j) {
	arr[uf_find(arr, i)] = uf_find(uf_find(arr, j));
}