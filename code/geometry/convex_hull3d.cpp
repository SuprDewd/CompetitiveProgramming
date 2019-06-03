#include "primitives3d.cpp"
double mixed(P(a), P(b), P(c)) { return a % (b * c); }
bool cmpy(point3d& a, point3d& b) {
  if (abs(a.y-b.y) > EPS) return a.y < b.y;
  if (abs(a.x-b.x) > EPS) return a.x < b.x;
  return a.z < b.z; }
point3d slp;
bool cmpsl(point3d& a, point3d& b) {
  point3d ad = a-slp, bd = b-slp;
  return atan2(ad.y, sqrt(ad.x*ad.x + ad.z*ad.z)) <
         atan2(bd.y, sqrt(bd.x*bd.x + bd.z*bd.z)); }
set<vi> gift_wrap(vector<point3d> points) {
  int n = points.size(), lowi = 0, lowj = 0;
  set<vi> res; set<ii> vis; queue<ii> q;
  if (n < 3) return res;
  rep(i,1,n) if (cmpy(points[i], points[lowi])) lowi = i;
  slp = points[lowi];
  if (lowj == lowi) lowj++;
  rep(j,lowj+1,n)
    if (j!=lowi && cmpsl(points[j], points[lowj])) lowj=j;
  q.push(ii(min(lowi,lowj), max(lowi,lowj)));
  while (!q.empty()) {
    ii cur = q.front(); q.pop();
    if (!vis.insert(cur).second) continue;
    int mni = 0, mxi = 0;
    while (mni==cur.first || mni==cur.second) mni++,mxi++;
    rep(i,0,n) {
      if (i == cur.first || i == cur.second) continue;
      if (mixed(points[cur.second] - points[cur.first],
            points[mni] - points[cur.first],
            points[i] - points[cur.first]) < 0) mni = i;
      if (mixed(points[cur.second] - points[cur.first],
            points[mxi] - points[cur.first],
            points[i] - points[cur.first]) > 0) mxi = i; }
    vi a = {cur.first,cur.second}, b = {mni,mxi};
    rep(i,0,2) {
      if (b[i] == -1) continue;
      rep(j,0,2) q.push({min(b[i],a[j]), max(b[i],a[j])});
      vi v = {a[0], a[1], b[i]};
      sort(v.begin(), v.end());
      res.insert(v); } } return res; }
// vim: cc=60 ts=2 sts=2 sw=2:
