struct convex_hull_trick {
  vector<pair<double,double> > h;
  double intersect(int i) {
    return (h[i+1].second-h[i].second) /
      (h[i].first-h[i+1].first); }
  void add(double m, double b) {
    h.push_back(make_pair(m,b));
    while (size(h) >= 3) {
      int n = size(h);
      if (intersect(n-3) < intersect(n-2)) break;
      swap(h[n-2], h[n-1]);
      h.pop_back(); } }
  double get_min(double x) {
    int lo = 0, hi = size(h) - 2, res = -1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (intersect(mid) <= x) res = mid, lo = mid + 1;
      else hi = mid - 1; }
    return h[res+1].first * x + h[res+1].second; } };
// vim: cc=60 ts=2 sts=2 sw=2:
