#define AVL_MULTISET 0
template <class T>
struct avl_tree {
  struct node {
    T item; node *p, *l, *r;
    int size, height;
    node(const T &_item, node *_p = NULL) : item(_item), p(_p),
    l(NULL), r(NULL), size(1), height(0) { } };
  avl_tree() : root(NULL) { }
  node *root;
  inline int sz(node *n) const { return n ? n->size : 0; }
  inline int height(node *n) const {
    return n ? n->height : -1; }
  inline bool left_heavy(node *n) const {
    return n && height(n->l) > height(n->r); }
  inline bool right_heavy(node *n) const {
    return n && height(n->r) > height(n->l); }
  inline bool too_heavy(node *n) const {
    return n && abs(height(n->l) - height(n->r)) > 1; }
  void delete_tree(node *n) { if (n) {
    delete_tree(n->l), delete_tree(n->r); delete n; } }
  node*& parent_leg(node *n) {
    if (!n->p) return root;
    if (n->p->l == n) return n->p->l;
    if (n->p->r == n) return n->p->r;
    assert(false); }
  void augment(node *n) {
    if (!n) return;
    n->size = 1 + sz(n->l) + sz(n->r);
    n->height = 1 + max(height(n->l), height(n->r)); }
  #define rotate(l, r) \
    node *l = n->l; \
    l->p = n->p; \
    parent_leg(n) = l; \
    n->l = l->r; \
    if (l->r) l->r->p = n; \
    l->r = n, n->p = l; \
    augment(n), augment(l)
  void left_rotate(node *n) { rotate(r, l); }
  void right_rotate(node *n) { rotate(l, r); }
  void fix(node *n) {
    while (n) { augment(n);
      if (too_heavy(n)) {
        if (left_heavy(n) && right_heavy(n->l))
          left_rotate(n->l);
        else if (right_heavy(n) && left_heavy(n->r))
          right_rotate(n->r);
        if (left_heavy(n)) right_rotate(n);
        else left_rotate(n);
        n = n->p; }
      n = n->p; } }
  inline int size() const { return sz(root); }
  node* find(const T &item) const {
    node *cur = root;
    while (cur) {
      if (cur->item < item) cur = cur->r;
      else if (item < cur->item) cur = cur->l;
      else break; }
    return cur; }
  node* insert(const T &item) {
    node *prev = NULL, **cur = &root;
    while (*cur) {
      prev = *cur;
      if ((*cur)->item < item) cur = &((*cur)->r);
#if AVL_MULTISET
      else cur = &((*cur)->l);
#else
      else if (item < (*cur)->item) cur = &((*cur)->l);
      else return *cur;
#endif
    }
    node *n = new node(item, prev);
    *cur = n, fix(n); return n; }
  void erase(const T &item) { erase(find(item)); }
  void erase(node *n, bool free = true) {
    if (!n) return;
    if (!n->l && n->r) parent_leg(n) = n->r, n->r->p = n->p;
    else if (n->l && !n->r)
      parent_leg(n) = n->l, n->l->p = n->p;
    else if (n->l && n->r) {
      node *s = successor(n);
      erase(s, false);
      s->p = n->p, s->l = n->l, s->r = n->r;
      if (n->l) n->l->p = s;
      if (n->r) n->r->p = s;
      parent_leg(n) = s, fix(s);
      return;
    } else parent_leg(n) = NULL;
    fix(n->p), n->p = n->l = n->r = NULL;
    if (free) delete n; }
  node* successor(node *n) const {
    if (!n) return NULL;
    if (n->r) return nth(0, n->r);
    node *p = n->p;
    while (p && p->r == n) n = p, p = p->p;
    return p; }
  node* predecessor(node *n) const {
    if (!n) return NULL;
    if (n->l) return nth(n->l->size-1, n->l);
    node *p = n->p;
    while (p && p->l == n) n = p, p = p->p;
    return p; }
  node* nth(int n, node *cur = NULL) const {
    if (!cur) cur = root;
    while (cur) {
      if (n < sz(cur->l)) cur = cur->l;
      else if (n > sz(cur->l))
        n -= sz(cur->l) + 1, cur = cur->r;
      else break;
    } return cur; }
  int count_less(node *cur) {
    int sum = sz(cur->l);
    while (cur) {
      if (cur->p && cur->p->r == cur) sum += 1 + sz(cur->p->l);
      cur = cur->p;
    } return sum; }
  void clear() { delete_tree(root), root = NULL; } };
// vim: cc=60 ts=2 sts=2 sw=2:
