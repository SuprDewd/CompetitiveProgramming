
/* Field testing: ICPC Live Archive 2755, ICPC Live Archive 4513, SPOJ DISUBSTR */

struct cmp {
  int *idx;
  string s;
  cmp(int *_idx, string _s) : idx(_idx), s(_s) { }
  bool operator()(int a, int b) {
    return s.substr(a) < s.substr(b);
  }
};

struct naive_suffix_array {
  string s;
  int n;
  int *idx;

  // naive_suffix_array(string s) : s(s + "\x0c"), n(size(s)+1) {
  naive_suffix_array(string _s) : s(_s), n(size(s)) {
    idx = new int[n];
    for (int i = 0; i < n; i++) idx[i] = i;
    sort(idx, idx + n, cmp(idx,s));
  }
};

void make_sure_ok(string s) {
  // s = s + "~";
  suffix_array sa1(s);
  naive_suffix_array sa2(s);

  // for (int i = 0; i < size(s); i++) {
  //     cout << s.substr(sa1.idx[i]) << endl;
  // }

  // cout << endl;
  // for (int i = 0; i < size(s); i++) {
  //     cout << s.substr(sa2.idx[i]) << endl;
  // }

  // cout << endl;

  for (int i = 0; i < size(s); i++) {

    assert_equal(sa1.idx[i], sa2.idx[i]);

    if (sa1.idx[i] != sa2.idx[i])
    {
      cout << s << endl;
    }
  }
}

void test() {
  make_sure_ok("GATAGACA");
  make_sure_ok("");
  make_sure_ok("A");
  make_sure_ok("AA");
  make_sure_ok("AAA");
  make_sure_ok("AAAA");
  make_sure_ok("AAAAA");
  make_sure_ok("AAAAAA");
  make_sure_ok("AAAAAAA");
  make_sure_ok("AAAAAAAA");
  make_sure_ok("B");
  make_sure_ok("BA");
  make_sure_ok("BAA");
  make_sure_ok("BAAA");
  make_sure_ok("BAAAA");
  make_sure_ok("BAAAAA");
  make_sure_ok("BAAAAAA");
  make_sure_ok("BAAAAAAA");
  make_sure_ok("BAAAAAAAA");
  make_sure_ok("AB");
  make_sure_ok("AAB");
  make_sure_ok("AAAB");
  make_sure_ok("AAAAB");
  make_sure_ok("AAAAAB");
  make_sure_ok("AAAAAAB");
  make_sure_ok("AAAAAAAB");
  make_sure_ok("AAAAAAAAB");
  make_sure_ok("AB");
  make_sure_ok("ABA");
  make_sure_ok("ABAA");
  make_sure_ok("ABAAA");
  make_sure_ok("ABAAAA");
  make_sure_ok("ABAAAAA");
  make_sure_ok("ABAAAAAA");
  make_sure_ok("ABAAAAAAA");

  for (int i = 0; i < 10000; i++) {
    int len = rand() % 1000;
    stringstream ss;
    for (int j = 0; j < len; j++) {
      ss << static_cast<char>('A' + (rand() % 26));
    }

    string s = ss.str();
    // cout << s << endl;
    make_sure_ok(s);
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
