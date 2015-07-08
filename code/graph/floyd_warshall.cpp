void floyd_warshall(int** arr, int n) {
    rep(k,0,n) rep(i,0,n) rep(j,0,n)
        if (arr[i][k] != INF && arr[k][j] != INF)
            arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
}
