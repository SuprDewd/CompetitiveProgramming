#include "circles.cpp"
vector<point> wP, wR;
pair<point,double> welzl() {
  if (wP.empty() || wR.size() == 3) {
    if (wR.empty()) return make_pair(point(), 0);
    if (wR.size() == 1) return make_pair(wR[0], 0);
    if (wR.size() == 2) return make_pair((wR[0]+wR[1])/2.0,
                                        abs(wR[0]-wR[1])/2);
    if (abs(cross(wR[1]-wR[0], wR[2]-wR[0])) < EPS) {
      point res; double mx = -INFINITY, d;
      rep(i,0,3) rep(j,i+1,3)
        if ((d = abs(wR[i] - wR[j])) > mx)
          mx = d, res = (wR[i] + wR[j]) / 2.0;
      return make_pair(res, mx/2.0); }
    return circumcircle(wR[0], wR[1], wR[2]); }
  swap(wP[rand() % wP.size()], wP.back());
  point res = wP.back(); wP.pop_back();
  pair<point,double> D = welzl();
  if (abs(res - D.first) > D.second + EPS) {
    wR.push_back(res); D = welzl(); wR.pop_back();
  } wP.push_back(res); return D; }
// vim: cc=60 ts=2 sts=2 sw=2:
