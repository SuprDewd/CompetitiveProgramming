#define MAXN 100100
struct RMST {
  struct point {
    int i; ll x, y;
    point() : i(-1) { }
    ll d1() { return x + y; }
    ll d2() { return x - y; }
    ll dist(point other) {
      return abs(x - other.x) + abs(y - other.y); }
    bool operator <(const point &other) const {
      return y == other.y ? x > other.x : y < other.y; }
  } best[MAXN], arr[MAXN], tmp[MAXN];
  int n;
  RMST() : n(0) {}
  void add_point(int x, int y) {
    arr[arr[n].i = n].x = x, arr[n++].y = y; }
  void rec(int l, int r) {
    if (l >= r) return;
    int m = (l+r)/2;
    rec(l,m), rec(m+1,r);
    point bst;
    for (int i = l, j = m+1, k = l; i <= m || j <= r; k++) {
      if (j > r || (i <= m && arr[i].d1() < arr[j].d1())) {
        tmp[k] = arr[i++];
        if (bst.i != -1 && (best[tmp[k].i].i == -1
                        || best[tmp[k].i].d2() < bst.d2()))
          best[tmp[k].i] = bst;
      } else {
        tmp[k] = arr[j++];
        if (bst.i == -1 || bst.d2() < tmp[k].d2())
          bst = tmp[k]; } }
    rep(i,l,r+1) arr[i] = tmp[i]; }
  vector<pair<ll,ii> > candidates() {
    vector<pair<ll, ii> > es;
    rep(p,0,2) {
      rep(q,0,2) {
        sort(arr, arr+n);
        rep(i,0,n) best[i].i = -1;
        rec(0,n-1);
        rep(i,0,n) {
          if(best[arr[i].i].i != -1)
            es.push_back({arr[i].dist(best[arr[i].i]),
                         {arr[i].i, best[arr[i].i].i}});
          swap(arr[i].x, arr[i].y);
          arr[i].x *= -1, arr[i].y *= -1; } }
      rep(i,0,n) arr[i].x *= -1; }
    return es; } };
// vim: cc=60 ts=2 sts=2 sw=2:
