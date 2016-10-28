/* Field testing: UVa 12526 */

void test() {

  trie<char> t; string s;

  s = "";
  assert_equal(0, t.countMatches(s.begin(), s.end()));

  s = "X";
  assert_equal(0, t.countMatches(s.begin(), s.end()));

  s = "XX";
  assert_equal(0, t.countMatches(s.begin(), s.end()));

  s = "XXX";
  assert_equal(0, t.countMatches(s.begin(), s.end()));

  s = "Hello, World!";
  assert_equal(0, t.countMatches(s.begin(), s.end()));

  s = "";
  assert_equal(0, t.countPrefixes(s.begin(), s.end()));

  s = "X";
  assert_equal(0, t.countPrefixes(s.begin(), s.end()));

  s = "XX";
  assert_equal(0, t.countPrefixes(s.begin(), s.end()));

  s = "XXX";
  assert_equal(0, t.countPrefixes(s.begin(), s.end()));

  s = "Hello, World!";
  assert_equal(0, t.countPrefixes(s.begin(), s.end()));

  s = "XX";
  t.insert(s.begin(), s.end());

  s = "";
  assert_equal(0, t.countMatches(s.begin(), s.end()));

  s = "X";
  assert_equal(0, t.countMatches(s.begin(), s.end()));

  s = "XX";
  assert_equal(1, t.countMatches(s.begin(), s.end()));

  s = "XXX";
  assert_equal(0, t.countMatches(s.begin(), s.end()));

  s = "Hello, World!";
  assert_equal(0, t.countMatches(s.begin(), s.end()));

  s = "";
  assert_equal(1, t.countPrefixes(s.begin(), s.end()));

  s = "X";
  assert_equal(1, t.countPrefixes(s.begin(), s.end()));

  s = "XX";
  assert_equal(1, t.countPrefixes(s.begin(), s.end()));

  s = "XXX";
  assert_equal(0, t.countPrefixes(s.begin(), s.end()));

  s = "Hello, World!";
  assert_equal(0, t.countPrefixes(s.begin(), s.end()));

  s = "Hello, World!";
  t.insert(s.begin(), s.end());

  s = "";
  assert_equal(0, t.countMatches(s.begin(), s.end()));

  s = "X";
  assert_equal(0, t.countMatches(s.begin(), s.end()));

  s = "XX";
  assert_equal(1, t.countMatches(s.begin(), s.end()));

  s = "XXX";
  assert_equal(0, t.countMatches(s.begin(), s.end()));

  s = "Hello, World!";
  assert_equal(1, t.countMatches(s.begin(), s.end()));

  s = "";
  assert_equal(2, t.countPrefixes(s.begin(), s.end()));

  s = "X";
  assert_equal(1, t.countPrefixes(s.begin(), s.end()));

  s = "XX";
  assert_equal(1, t.countPrefixes(s.begin(), s.end()));

  s = "XXX";
  assert_equal(0, t.countPrefixes(s.begin(), s.end()));

  s = "Hello, World!";
  assert_equal(1, t.countPrefixes(s.begin(), s.end()));

  s = "XXX";
  t.insert(s.begin(), s.end());

  s = "";
  assert_equal(0, t.countMatches(s.begin(), s.end()));

  s = "X";
  assert_equal(0, t.countMatches(s.begin(), s.end()));

  s = "XX";
  assert_equal(1, t.countMatches(s.begin(), s.end()));

  s = "XXX";
  assert_equal(1, t.countMatches(s.begin(), s.end()));

  s = "Hello, World!";
  assert_equal(1, t.countMatches(s.begin(), s.end()));

  s = "";
  assert_equal(3, t.countPrefixes(s.begin(), s.end()));

  s = "X";
  assert_equal(2, t.countPrefixes(s.begin(), s.end()));

  s = "XX";
  assert_equal(2, t.countPrefixes(s.begin(), s.end()));

  s = "XXX";
  assert_equal(1, t.countPrefixes(s.begin(), s.end()));

  s = "Hello, World!";
  assert_equal(1, t.countPrefixes(s.begin(), s.end()));

  s = "XX";
  t.insert(s.begin(), s.end());

  s = "";
  assert_equal(0, t.countMatches(s.begin(), s.end()));

  s = "X";
  assert_equal(0, t.countMatches(s.begin(), s.end()));

  s = "XX";
  assert_equal(2, t.countMatches(s.begin(), s.end()));

  s = "XXX";
  assert_equal(1, t.countMatches(s.begin(), s.end()));

  s = "Hello, World!";
  assert_equal(1, t.countMatches(s.begin(), s.end()));

  s = "";
  assert_equal(4, t.countPrefixes(s.begin(), s.end()));

  s = "X";
  assert_equal(3, t.countPrefixes(s.begin(), s.end()));

  s = "XX";
  assert_equal(3, t.countPrefixes(s.begin(), s.end()));

  s = "XXX";
  assert_equal(1, t.countPrefixes(s.begin(), s.end()));

  s = "Hello, World!";
  assert_equal(1, t.countPrefixes(s.begin(), s.end()));
}
// vim: cc=60 ts=2 sts=2 sw=2:
