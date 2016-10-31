
struct aho_corasick_slow {

  vector<string> keywords;

  aho_corasick_slow(vector<string> _keywords) : keywords(_keywords) {
  }

  vector<string> search(string s) {
    vector<string> res;
    for (int i = 0; i < size(s); i++) {
      for (int j = 0; j < size(keywords); j++) {
        string kw = keywords[j];
        if (i + size(kw) - 1 >= size(s))
          continue;

        bool ok = true;
        for (int k = 0; ok && k < size(kw); k++) {
          ok = s[i + k] == kw[k];
        }

        if (ok)
          res.push_back(kw);
      }
    }

    return res;
  }
};

string random_string(int n, int cc) {
  stringstream ss;
  for (int i = 0; i < n; i++) {
    ss << static_cast<char>(rand() % cc + 'a');
  }

  return ss.str();
}

void test() {
  /* Field testing: Kattis stringmultimatching, Codeforces 366C */

  int ts = 100,
    ts2 = 10;

  for (int t = 0; t < ts; t++) {
    int n = rand() % 1000;

    vector<string> kws;
    for (int i = 0; i < n; i++) {
      kws.push_back(random_string(rand() % 10 + 1, rand() % 5 + 1));
    }

    aho_corasick ac(kws);
    aho_corasick_slow ac2(kws);

    for (int p = 0; p < ts2; p++) {
      string s = random_string(rand() % 100, rand() % 5 + 1);
      vector<string> res = ac.search(s);
      vector<string> res2 = ac2.search(s);
      sort(res.begin(), res.end());
      sort(res2.begin(), res2.end());

      assert_equal(size(res2), size(res));

      for (int i = 0; i < size(res); i++) {
        assert_equal(res2[i], res[i]);
      }
    }
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
