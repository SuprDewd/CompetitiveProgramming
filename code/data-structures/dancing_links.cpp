template <class T>
struct dancing_links {
  struct node {
    T item;
    node *l, *r;
    node(const T &_item, node *_l = NULL, node *_r = NULL)
      : item(_item), l(_l), r(_r) {
      if (l) l->r = this;
      if (r) r->l = this; } };
  node *front, *back;
  dancing_links() { front = back = NULL; }
  node *push_back(const T &item) {
    back = new node(item, back, NULL);
    if (!front) front = back;
    return back; }
  node *push_front(const T &item) {
    front = new node(item, NULL, front);
    if (!back) back = front;
    return front; }
  void erase(node *n) {
    if (!n->l) front = n->r; else n->l->r = n->r;
    if (!n->r) back = n->l; else n->r->l = n->l; }
  void restore(node *n) {
    if (!n->l) front = n; else n->l->r = n;
    if (!n->r) back = n; else n->r->l = n; } };
// vim: cc=60 ts=2 sts=2 sw=2:
