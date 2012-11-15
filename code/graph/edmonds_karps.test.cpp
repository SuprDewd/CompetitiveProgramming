void test() {
	int** arr = new int*[4];
	for (int i = 0; i < 4; i++)
	{
		arr[i] = new int[4];
		for (int j = 0; j < 4; j++)
			arr[i][j] = 0;
	}

	arr[0][1] = 133700;
	arr[0][2] = 133700;
	arr[1][2] = 1;
	arr[1][3] = 133700;
	arr[2][3] = 133700;

	assert_equal(2 * 133700, max_flow(4, 0, 3, arr));


	arr = new int*[5];
	for (int i = 0; i < 5; i++)
	{
		arr[i] = new int[5];
		for (int j = 0; j < 5; j++)
			arr[i][j] = 0;
	}

	arr[1][2] = 100;
	arr[1][3] = 50;
	arr[2][3] = 50;
	arr[2][4] = 50;
	arr[2][0] = 50;
	arr[3][4] = 100;
	arr[4][0] = 125;

	assert_equal(150, max_flow(5, 1, 0, arr));

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			arr[i][j] = 0;

	arr[1][2] = 100;
	arr[1][3] = 50;
	arr[2][3] = 50;
	arr[2][4] = 50;
	arr[2][0] = 50;
	arr[3][4] = 100;
	arr[4][0] = 75;

	assert_equal(125, max_flow(5, 1, 0, arr));

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			arr[i][j] = 0;

	arr[1][2] = 100;
	arr[1][3] = 50;
	arr[2][4] = 5;
	arr[2][0] = 5;
	arr[3][4] = 100;
	arr[4][0] = 125;

	assert_equal(60, max_flow(5, 1, 0, arr));
}