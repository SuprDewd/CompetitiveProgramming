#define INC(c) ((c) == K - 1 ? 0 : (c) + 1)
template <int K> struct kd_tree {
  struct pt {
    double coord[K];
    pt() {}
    pt(double c[K]) { rep(i,0,K) coord[i] = c[i]; }
    double dist(const pt &other) const {
      double sum = 0.0;
      rep(i,0,K) sum += pow(coord[i] - other.coord[i], 2.0);
      return sqrt(sum); } };
  struct cmp {
    int c;
    cmp(int _c) : c(_c) {}
    bool operator ()(const pt &a, const pt &b) {
      for (int i = 0, cc; i <= K; i++) {
        cc = i == 0 ? c : i - 1;
        if (abs(a.coord[cc] - b.coord[cc]) > EPS)
          return a.coord[cc] < b.coord[cc];
      }
      return false; } };
  struct bb {
    pt from, to;
    bb(pt _from, pt _to) : from(_from), to(_to) {}
    double dist(const pt &p) {
      double sum = 0.0;
      rep(i,0,K) {
        if (p.coord[i] < from.coord[i])
          sum += pow(from.coord[i] - p.coord[i], 2.0);
        else if (p.coord[i] > to.coord[i])
          sum += pow(p.coord[i] - to.coord[i], 2.0);
      }
      return sqrt(sum); }
    bb bound(double l, int c, bool left) {
      pt nf(from.coord), nt(to.coord);
      if (left) nt.coord[c] = min(nt.coord[c], l);
      else nf.coord[c] = max(nf.coord[c], l);
      return bb(nf, nt); } };
  struct node {
    pt p; node *l, *r;
    node(pt _p, node *_l, node *_r)
      : p(_p), l(_l), r(_r) {  } };
  node *root;
  // kd_tree() : root(NULL) { }
  kd_tree(vector<pt> pts) {
    root = construct(pts, 0, size(pts) - 1, 0); }
  node* construct(vector<pt> &pts, int from, int to, int c) {
    if (from > to) return NULL;
    int mid = from + (to - from) / 2;
    nth_element(pts.begin() + from, pts.begin() + mid,
          pts.begin() + to + 1, cmp(c));
    return new node(pts[mid],
            construct(pts, from, mid - 1, INC(c)),
            construct(pts, mid + 1, to, INC(c))); }
  bool contains(const pt &p) { return _con(p, root, 0); }
  bool _con(const pt &p, node *n, int c) {
    if (!n) return false;
    if (cmp(c)(p, n->p)) return _con(p, n->l, INC(c));
    if (cmp(c)(n->p, p)) return _con(p, n->r, INC(c));
    return true; }
  void insert(const pt &p) { _ins(p, root, 0); }
  void _ins(const pt &p, node* &n, int c) {
    if (!n) n = new node(p, NULL, NULL);
    else if (cmp(c)(p, n->p)) _ins(p, n->l, INC(c));
    else if (cmp(c)(n->p, p)) _ins(p, n->r, INC(c)); }
  void clear() { _clr(root); root = NULL; }
  void _clr(node *n) {
    if (n) _clr(n->l), _clr(n->r), delete n; }
  pair<pt, bool> nearest_neighbour(const pt &p,
      bool allow_same=true) {
    double mn = INFINITY, cs[K];
    rep(i,0,K) cs[i] = -INFINITY;
    pt from(cs);
    rep(i,0,K) cs[i] = INFINITY;
    pt to(cs), resp;
    _nn(p, root, bb(from, to), mn, resp, 0, allow_same);
    return make_pair(resp, !std::isinf(mn)); }
  void _nn(const pt &p, node *n, bb b,
      double &mn, pt &resp, int c, bool same) {
    if (!n || b.dist(p) > mn) return;
    bool l1 = true, l2 = false;
    if ((same || p.dist(n->p) > EPS) && p.dist(n->p) < mn)
        mn = p.dist(resp = n->p);
    node *n1 = n->l, *n2 = n->r;
    rep(i,0,2) {
      if (i == 1 || cmp(c)(n->p, p)) swap(n1,n2),swap(l1,l2);
      _nn(p, n1, b.bound(n->p.coord[c], c, l1), mn,
          resp, INC(c), same); } } };
// vim: cc=60 ts=2 sts=2 sw=2:
