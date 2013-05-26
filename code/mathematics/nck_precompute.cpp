void nck_precompute(int** arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i][0] = arr[i][i] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 1; j < i; j++)
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
}
