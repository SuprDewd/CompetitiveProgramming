#include "circles.cpp"
vector<point> wP, wR;
pair<point,double> welzl() {
  point res;
  if (wP.empty() || wR.size() == 3) {
    if (wR.empty()) { }
    else if (wR.size() == 1) res = wR[0];
    else if (wR.size() == 2) res = (wR[0] + wR[1])/2.0;
    else if (abs(cross(wR[1]-wR[0], wR[2]-wR[0])) < EPS) {
      double mx = -INFINITY, d;
      rep(i,0,3) rep(j,i+1,3)
        if ((d = abs(wR[i] - wR[j])) > mx)
          mx = d, res = (wR[i] + wR[j]) / 2.0; }
    else res = circumcircle(wR[0], wR[1], wR[2]).first;
    double mx = 0.0;
    iter(it,wP) mx = max(mx, abs(res - *it));
    iter(it,wR) mx = max(mx, abs(res - *it));
    return make_pair(res, mx); }
  swap(wP[rand() % wP.size()], wP.back());
  res = wP.back(); wP.pop_back();
  pair<point,double> D = welzl();
  if (abs(res - D.first) > D.second + EPS) {
    wR.push_back(res); D = welzl(); wR.pop_back();
  } wP.push_back(res); return D; }
// vim: cc=60 ts=2 sts=2 sw=2:
