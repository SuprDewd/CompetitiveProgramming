void test()
{
	int n = 20;
	int** arr = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = new int[i + 1];
	}

	nck_precompute(arr, n);

	assert_equal(1, arr[0][0]);
	assert_equal(1, arr[1][0]);
	assert_equal(1, arr[1][1]);
	assert_equal(2, arr[2][1]);
	assert_equal(45, arr[10][8]);
	assert_equal(462, arr[11][5]);
}