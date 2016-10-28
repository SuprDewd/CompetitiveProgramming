struct aho_corasick {
  struct out_node {
    string keyword; out_node *next;
    out_node(string k, out_node *n)
      : keyword(k), next(n) { } };
  struct go_node {
    map<char, go_node*> next;
    out_node *out; go_node *fail;
    go_node() { out = NULL; fail = NULL; } };
  go_node *go;
  aho_corasick(vector<string> keywords) {
    go = new go_node();
    iter(k, keywords) {
      go_node *cur = go;
      iter(c, *k)
        cur = cur->next.find(*c) != cur->next.end() ?
          cur->next[*c] : (cur->next[*c] = new go_node());
      cur->out = new out_node(*k, cur->out); }
    queue<go_node*> q;
    iter(a, go->next) q.push(a->second);
    while (!q.empty()) {
      go_node *r = q.front(); q.pop();
      iter(a, r->next) {
        go_node *s = a->second;
        q.push(s);
        go_node *st = r->fail;
        while (st && st->next.find(a->first) ==
            st->next.end()) st = st->fail;
        if (!st) st = go;
        s->fail = st->next[a->first];
        if (s->fail) {
          if (!s->out) s->out = s->fail->out;
          else {
            out_node* out = s->out;
            while (out->next) out = out->next;
            out->next = s->fail->out; } } } } }
  vector<string> search(string s) {
    vector<string> res;
    go_node *cur = go;
    iter(c, s) {
      while (cur && cur->next.find(*c) == cur->next.end())
        cur = cur->fail;
      if (!cur) cur = go;
      cur = cur->next[*c];
      if (!cur) cur = go;
      for (out_node *out = cur->out; out; out = out->next)
        res.push_back(out->keyword); }
    return res; } };
// vim: cc=60 ts=2 sts=2 sw=2:
