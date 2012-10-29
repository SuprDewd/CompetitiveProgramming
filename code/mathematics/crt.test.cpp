void test() {
	vi as, ns;

	as.clear();
	as.push_back(2);
	as.push_back(3);
	as.push_back(1);
	ns.clear();
	ns.push_back(3);
	ns.push_back(4);
	ns.push_back(5);
	assert_equal(11, crt(as, ns));

	as.clear();
	as.push_back(23);
	as.push_back(12);
	as.push_back(55);
	ns.clear();
	ns.push_back(11);
	ns.push_back(21);
	ns.push_back(31);
	assert_equal(5325, crt(as, ns));
}