bool handle_solution(vi rows) { return false; }
struct exact_cover {
  struct node {
    node *l, *r, *u, *d, *p;
    int row, col, size;
    node(int _row, int _col) : row(_row), col(_col) {
      size = 0; l = r = u = d = p = NULL; } };
  int rows, cols, *sol;
  bool **arr;
  node *head;
  exact_cover(int _rows, int _cols)
    : rows(_rows), cols(_cols), head(NULL) {
    arr = new bool*[rows];
    sol = new int[rows];
    rep(i,0,rows)
      arr[i] = new bool[cols], memset(arr[i], 0, cols); }
  void set_value(int row, int col, bool val = true) {
    arr[row][col] = val; }
  void setup() {
    node ***ptr = new node**[rows + 1];
    rep(i,0,rows+1) {
      ptr[i] = new node*[cols];
      rep(j,0,cols)
        if (i == rows || arr[i][j]) ptr[i][j] = new node(i,j);
        else ptr[i][j] = NULL; }
    rep(i,0,rows+1) {
      rep(j,0,cols) {
        if (!ptr[i][j]) continue;
        int ni = i + 1, nj = j + 1;
        while (true) {
          if (ni == rows + 1) ni = 0;
          if (ni == rows || arr[ni][j]) break;
          ++ni; }
        ptr[i][j]->d = ptr[ni][j];
        ptr[ni][j]->u = ptr[i][j];
        while (true) {
          if (nj == cols) nj = 0;
          if (i == rows || arr[i][nj]) break;
          ++nj; }
        ptr[i][j]->r = ptr[i][nj];
        ptr[i][nj]->l = ptr[i][j]; } }
    head = new node(rows, -1);
    head->r = ptr[rows][0];
    ptr[rows][0]->l = head;
    head->l = ptr[rows][cols - 1];
    ptr[rows][cols - 1]->r = head;
    rep(j,0,cols) {
      int cnt = -1;
      rep(i,0,rows+1)
        if (ptr[i][j]) cnt++, ptr[i][j]->p = ptr[rows][j];
      ptr[rows][j]->size = cnt; }
    rep(i,0,rows+1) delete[] ptr[i];
    delete[] ptr; }
  #define COVER(c, i, j) \
    c->r->l = c->l, c->l->r = c->r; \
    for (node *i = c->d; i != c; i = i->d) \
      for (node *j = i->r; j != i; j = j->r) \
        j->d->u = j->u, j->u->d = j->d, j->p->size--;
  #define UNCOVER(c, i, j) \
    for (node *i = c->u; i != c; i = i->u) \
      for (node *j = i->l; j != i; j = j->l) \
        j->p->size++, j->d->u = j->u->d = j; \
    c->r->l = c->l->r = c;
  bool search(int k = 0) {
    if (head == head->r) {
      vi res(k);
      rep(i,0,k) res[i] = sol[i];
      sort(res.begin(), res.end());
      return handle_solution(res); }
    node *c = head->r, *tmp = head->r;
    for ( ; tmp != head; tmp = tmp->r)
      if (tmp->size < c->size) c = tmp;
    if (c == c->d) return false;
    COVER(c, i, j);
    bool found = false;
    for (node *r = c->d; !found && r != c; r = r->d) {
      sol[k] = r->row;
      for (node *j = r->r; j != r; j = j->r) {
        COVER(j->p, a, b); }
      found = search(k + 1);
      for (node *j = r->l; j != r; j = j->l) {
        UNCOVER(j->p, a, b); } }
    UNCOVER(c, i, j);
    return found; } };
// vim: cc=60 ts=2 sts=2 sw=2:
