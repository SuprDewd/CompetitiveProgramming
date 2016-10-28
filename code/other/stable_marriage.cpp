vi stable_marriage(int n, int** m, int** w) {
  queue<int> q;
  vi at(n, 0), eng(n, -1), res(n, -1); vvi inv(n, vi(n));
  rep(i,0,n) rep(j,0,n) inv[i][w[i][j]] = j;
  rep(i,0,n) q.push(i);
  while (!q.empty()) {
    int curm = q.front(); q.pop();
    for (int &i = at[curm]; i < n; i++) {
      int curw = m[curm][i];
      if (eng[curw] == -1) { }
      else if (inv[curw][curm] < inv[curw][eng[curw]])
        q.push(eng[curw]);
      else continue;
      res[eng[curw] = curm] = curw, ++i; break; } }
  return res; }
// vim: cc=60 ts=2 sts=2 sw=2:
