void floyd_warshall(int** arr, int n) {
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (arr[i][k] != INF && arr[k][j] != INF)
					arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
}