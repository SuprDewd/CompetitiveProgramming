struct node {
  node *p, *jmp[20];
  int depth;
  node(node *_p = NULL) : p(_p) {
    depth = p ? 1 + p->depth : 0;
    memset(jmp, 0, sizeof(jmp));
    jmp[0] = p;
    for (int i = 1; (1<<i) <= depth; i++)
      jmp[i] = jmp[i-1]->jmp[i-1]; } };
node* st[100000];
node* lca(node *a, node *b) {
  if (!a || !b) return NULL;
  if (a->depth < b->depth) swap(a,b);
  for (int j = 19; j >= 0; j--)
    while (a->depth - (1<<j) >= b->depth) a = a->jmp[j];
  if (a == b) return a;
  for (int j = 19; j >= 0; j--)
    while (a->depth >= (1<<j) && a->jmp[j] != b->jmp[j])
      a = a->jmp[j], b = b->jmp[j];
  return a->p; }
// vim: cc=60 ts=2 sts=2 sw=2:
