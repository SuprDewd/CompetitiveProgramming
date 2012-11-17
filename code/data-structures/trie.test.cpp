void test() {
	trie<char> t; string s;

	s = "";
	assert_equal(0, t.countMatches(all(s)));

	s = "X";
	assert_equal(0, t.countMatches(all(s)));

	s = "XX";
	assert_equal(0, t.countMatches(all(s)));

	s = "XXX";
	assert_equal(0, t.countMatches(all(s)));

	s = "Hello, World!";
	assert_equal(0, t.countMatches(all(s)));

	s = "";
	assert_equal(0, t.countPrefixes(all(s)));

	s = "X";
	assert_equal(0, t.countPrefixes(all(s)));

	s = "XX";
	assert_equal(0, t.countPrefixes(all(s)));

	s = "XXX";
	assert_equal(0, t.countPrefixes(all(s)));

	s = "Hello, World!";
	assert_equal(0, t.countPrefixes(all(s)));

	s = "XX";
	t.insert(all(s));

	s = "";
	assert_equal(0, t.countMatches(all(s)));

	s = "X";
	assert_equal(0, t.countMatches(all(s)));

	s = "XX";
	assert_equal(1, t.countMatches(all(s)));

	s = "XXX";
	assert_equal(0, t.countMatches(all(s)));

	s = "Hello, World!";
	assert_equal(0, t.countMatches(all(s)));

	s = "";
	assert_equal(1, t.countPrefixes(all(s)));

	s = "X";
	assert_equal(1, t.countPrefixes(all(s)));

	s = "XX";
	assert_equal(1, t.countPrefixes(all(s)));

	s = "XXX";
	assert_equal(0, t.countPrefixes(all(s)));

	s = "Hello, World!";
	assert_equal(0, t.countPrefixes(all(s)));

	s = "Hello, World!";
	t.insert(all(s));

	s = "";
	assert_equal(0, t.countMatches(all(s)));

	s = "X";
	assert_equal(0, t.countMatches(all(s)));

	s = "XX";
	assert_equal(1, t.countMatches(all(s)));

	s = "XXX";
	assert_equal(0, t.countMatches(all(s)));

	s = "Hello, World!";
	assert_equal(1, t.countMatches(all(s)));

	s = "";
	assert_equal(2, t.countPrefixes(all(s)));

	s = "X";
	assert_equal(1, t.countPrefixes(all(s)));

	s = "XX";
	assert_equal(1, t.countPrefixes(all(s)));

	s = "XXX";
	assert_equal(0, t.countPrefixes(all(s)));

	s = "Hello, World!";
	assert_equal(1, t.countPrefixes(all(s)));

	s = "XXX";
	t.insert(all(s));

	s = "";
	assert_equal(0, t.countMatches(all(s)));

	s = "X";
	assert_equal(0, t.countMatches(all(s)));

	s = "XX";
	assert_equal(1, t.countMatches(all(s)));

	s = "XXX";
	assert_equal(1, t.countMatches(all(s)));

	s = "Hello, World!";
	assert_equal(1, t.countMatches(all(s)));

	s = "";
	assert_equal(3, t.countPrefixes(all(s)));

	s = "X";
	assert_equal(2, t.countPrefixes(all(s)));

	s = "XX";
	assert_equal(2, t.countPrefixes(all(s)));

	s = "XXX";
	assert_equal(1, t.countPrefixes(all(s)));

	s = "Hello, World!";
	assert_equal(1, t.countPrefixes(all(s)));

	s = "XX";
	t.insert(all(s));

	s = "";
	assert_equal(0, t.countMatches(all(s)));

	s = "X";
	assert_equal(0, t.countMatches(all(s)));

	s = "XX";
	assert_equal(2, t.countMatches(all(s)));

	s = "XXX";
	assert_equal(1, t.countMatches(all(s)));

	s = "Hello, World!";
	assert_equal(1, t.countMatches(all(s)));

	s = "";
	assert_equal(4, t.countPrefixes(all(s)));

	s = "X";
	assert_equal(3, t.countPrefixes(all(s)));

	s = "XX";
	assert_equal(3, t.countPrefixes(all(s)));

	s = "XXX";
	assert_equal(1, t.countPrefixes(all(s)));

	s = "Hello, World!";
	assert_equal(1, t.countPrefixes(all(s)));
}