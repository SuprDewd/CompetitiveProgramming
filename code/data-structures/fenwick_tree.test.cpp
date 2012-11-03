void test() {
	fenwick_tree ft(20);

	for (int i = 0; i < 20; i++) {
		assert_equal(0, ft.get(i));
		ft.adjust(i, i);
		assert_equal(i, ft.get(i));
		ft.adjust(i, -i);
		assert_equal(0, ft.get(i));
	}

	ft.adjust(3, 1);
	for (int i = 0; i < 20; i++)
	{
		for (int j = i; j < 20; j++)
		{
			if (i <= 3 && 3 <= j)
			{
				assert_equal(1, ft.rsq(i, j));
			}
			else
			{
				assert_equal(0, ft.rsq(i, j));
			}
		}
	}

	ft.adjust(5, -2);
	assert_equal(-1, ft.rsq(1, 8));
	ft.adjust(4, 5);
	assert_equal(4, ft.rsq(1, 8));
	ft.adjust(0, 100);
	assert_equal(4, ft.rsq(1, 8));
	assert_equal(104, ft.rsq(0, 19));
	ft.adjust(19, -200);
	assert_equal(-96, ft.rsq(0, 19));
}