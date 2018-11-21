#include "primitives3d.cpp"
double mixed(P(a), P(b), P(c)) { return a % (b * c); }
bool cmpy(point3d& a, point3d& b) {
  if(abs(a.y-b.y) < EPS) {
    if(abs(a.x-b.x) < EPS) return a.z < b.z;
    else return a.x < b.x; }
  return a.y < b.y; }
point3d slp;
bool cmpsl(point3d& a, point3d& b) {
  point3d ad = a-slp, bd = b-slp;
  double al = sqrt(ad.x*ad.x + ad.z*ad.z),
         bl = sqrt(bd.x*bd.x + bd.z*bd.z);
  double aa = atan2(ad.y, al), ba = atan2(bd.y, bl);
  return aa < ba; }
set<vi> gift_wrap(vector<point3d> points) {
  int n = size(points);
  set<vi> res;
  if(n < 3) return res;
  int lowi = 0;
  rep(i,1,n) if(cmpy(points[i], points[lowi])) lowi = i;
  slp = points[lowi];
  int lowj = 0;
  if(lowj == lowi) lowj++;
  rep(j,lowj+1,n) {
    if(j == lowi) continue;
    if(cmpsl(points[j], points[lowj])) lowj = j; }
  if(lowi > lowj) swap(lowi, lowj);
  set<ii> vis;
  queue<ii> q;
  q.push(ii(lowi, lowj));
  while(!q.empty()) {
    ii cur = q.front();
    q.pop();
    if(vis.find(cur) != vis.end()) continue;
    vis.insert(cur);
    int mxi = 0, mni = 0;
    while(mni == cur.first || mni == cur.second) mni++;
    while(mxi == cur.first || mxi == cur.second) mxi++;
    rep(i,0,n) {
      if(i == cur.first || i == cur.second) continue;
      if(mixed(points[cur.second] - points[cur.first],
            points[mni] - points[cur.first],
            points[i] - points[cur.first]) < 0) mni = i;
      if(mixed(points[cur.second] - points[cur.first],
            points[mxi] - points[cur.first],
            points[i] - points[cur.first]) > 0) mxi = i; }
    vi a(2), b(2);
    a[0] = cur.first, a[1] = cur.second;
    b[0] = mni, b[1] = mxi;
    rep(i,0,2) {
      if(b[i] == -1) continue;
      bool either = false;
      rep(j,0,2) {
        ii st = ii(b[i], a[j]);
        if(st.first > st.second) swap(st.first, st.second);
        either = true;
        q.push(st); }
      vi v;
      v.push_back(a[0]);
      v.push_back(a[1]);
      v.push_back(b[i]);
      sort(v.begin(), v.end()); 
      res.insert(v); } } return res; }
// vim: cc=60 ts=2 sts=2 sw=2:
