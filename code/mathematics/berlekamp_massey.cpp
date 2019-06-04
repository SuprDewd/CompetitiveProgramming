template<class K> bool eq(K a, K b) { return a == b; }
template<> bool eq<long double>(long double a,long double b){
    return abs(a - b) < EPS; }
template <class Num>
vector<Num> berlekamp_massey(vector<Num> s) {
  int m = 1, L = 0; bool sw;
  vector<Num> C = {1}, B = {1}, T, res; Num b = 1, a;
  rep(i,0,s.size()) {
    Num d = s[i];
    rep(j,1,L+1) d = d + C[j] * s[i-j];
    if (eq(d,Num(0))) { m++; continue; }
    if ((sw = 2*L <= i)) C.resize((L = i+1-L)+1), T = C;
    a = d / b; for (int j = m; j < C.size(); j++)
      C[j] = C[j] - a * B[j-m];
    m++; if (sw) B = T, b = d, m = 1; }
  for (int i = 1; i <= L; i++) res.push_back(-C[i]);
  return res; }
// vim: cc=60 ts=2 sts=2 sw=2:
