#define MAXV 1000
#define MAXE 5000
vi adj[MAXV];
int n, m, indeg[MAXV], outdeg[MAXV], res[MAXE + 1];
ii start_end() {
  int start = -1, end = -1, any = 0, c = 0;
  rep(i,0,n) {
    if (outdeg[i] > 0) any = i;
    if (indeg[i] + 1 == outdeg[i]) start = i, c++;
    else if (indeg[i] == outdeg[i] + 1) end = i, c++;
    else if (indeg[i] != outdeg[i]) return ii(-1,-1); }
  if ((start == -1) != (end == -1) || (c != 2 && c != 0))
    return ii(-1,-1);
  if (start == -1) start = end = any;
  return ii(start, end); }
bool euler_path() {
  ii se = start_end();
  int cur = se.first, at = m + 1;
  if (cur == -1) return false;
  stack<int> s;
  while (true) {
    if (outdeg[cur] == 0) {
      res[--at] = cur;
      if (s.empty()) break;
      cur = s.top(); s.pop();
    } else s.push(cur), cur = adj[cur][--outdeg[cur]]; }
  return at == 0; }
// vim: cc=60 ts=2 sts=2 sw=2:
