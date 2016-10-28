struct node {
  int x, y, sz;
  node *l, *r;
  node(int _x, int _y)
    : x(_x), y(_y), sz(1), l(NULL), r(NULL) { } };
int tsize(node* t) { return t ? t->sz : 0; }
void augment(node *t) {
  t->sz = 1 + tsize(t->l) + tsize(t->r); }
pair<node*,node*> split(node *t, int x) {
  if (!t) return make_pair((node*)NULL,(node*)NULL);
  if (t->x < x) {
    pair<node*,node*> res = split(t->r, x);
    t->r = res.first; augment(t);
    return make_pair(t, res.second); }
  pair<node*,node*> res = split(t->l, x);
  t->l = res.second; augment(t);
  return make_pair(res.first, t); }
node* merge(node *l, node *r) {
  if (!l) return r; if (!r) return l;
  if (l->y > r->y) {
    l->r = merge(l->r, r); augment(l); return l; }
  r->l = merge(l, r->l); augment(r); return r; }
node* find(node *t, int x) {
  while (t) {
    if (x < t->x) t = t->l;
    else if (t->x < x) t = t->r;
    else return t; }
  return NULL; }
node* insert(node *t, int x, int y) {
  if (find(t, x) != NULL) return t;
  pair<node*,node*> res = split(t, x);
  return merge(res.first,
      merge(new node(x, y), res.second)); }
node* erase(node *t, int x) {
  if (!t) return NULL;
  if (t->x < x) t->r = erase(t->r, x);
  else if (x < t->x) t->l = erase(t->l, x);
  else { node *old = t; t = merge(t->l, t->r); delete old; }
  if (t) augment(t); return t; }
int kth(node *t, int k) {
  if (k < tsize(t->l)) return kth(t->l, k);
  else if (k == tsize(t->l)) return t->x;
  else return kth(t->r, k - tsize(t->l) - 1); }
// vim: cc=60 ts=2 sts=2 sw=2:
