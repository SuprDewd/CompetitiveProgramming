void test()
{
	assert_equal(1, nck(0, 0));
	assert_equal(1, nck(1, 0));
	assert_equal(1, nck(1, 1));
	assert_equal(2, nck(2, 1));
	assert_equal(45, nck(10, 8));
	assert_equal(462, nck(11, 5));
}