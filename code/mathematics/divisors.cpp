#include "factor.cpp"
template <class T>
vector<T> divisors(T n) {
  vector<T> res{{ 1 }};
  for (auto p : factor(n)) {
    auto offset = res.size();
    for (size_t i = 0; i < offset; i++) {
      for (T j = 1, m = p.fs; j <= p.sc; j++, m *= p.fs) {
        res.push_back(m * res[i]);
      }
    }
  }
  return res;
}
// vim: cc=60 ts=2 sts=2 sw=2:
