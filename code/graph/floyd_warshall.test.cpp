void test() {
  int arr[4][4] = {
    {0, 5, INF, 30},
    {6, 0, INF, INF},
    {INF, INF, 0, 8},
    {4, 2, 1, 0}
  };

  int res[4][4] = {
    {0, 5, 31, 30},
    {6, 0, 37, 36},
    {12, 10, 0, 8},
    {4, 2, 1, 0}
  };

  int** r = new int*[4];
  for (int i = 0; i < 4; i++)
  {
    r[i] = new int[4];
    for (int j = 0; j < 4; j++)
    {
      r[i][j] = arr[i][j];
    }
  }

  floyd_warshall(r, 4);

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      assert_equal(res[i][j], r[i][j]);
    }
  }

  int arr2[3][3] = {
    {0, 2, 10},
    {INF, 0, 4},
    {INF, INF, 0}
  };

  int res2[3][3] = {
    {0, 2, 6},
    {INF, 0, 4},
    {INF, INF, 0}
  };

  int** r2 = new int*[3];
  for (int i = 0; i < 3; i++)
  {
    r2[i] = new int[3];
    for (int j = 0; j < 3; j++)
    {
      r2[i][j] = arr2[i][j];
    }
  }

  floyd_warshall(r2, 3);

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      assert_equal(res2[i][j], r2[i][j]);
    }
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
