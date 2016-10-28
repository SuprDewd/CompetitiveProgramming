// TODO: Add longest common subsring
const int MAXL = 100000;
struct suffix_automaton {
  vi  len, link, occur, cnt;
  vector<map<char,int> > next;
  vector<bool> isclone;
  ll *occuratleast;
  int sz, last;
  string s;
  suffix_automaton() : len(MAXL*2), link(MAXL*2),
    occur(MAXL*2), next(MAXL*2), isclone(MAXL*2) { clear(); }
  void clear() { sz = 1; last = len[0] = 0; link[0] = -1;
                 next[0].clear(); isclone[0] = false; }
  bool issubstr(string other){
    for(int i = 0, cur = 0; i < size(other); ++i){
      if(cur == -1) return false; cur = next[cur][other[i]]; }
    return true; }
  void extend(char c){ int cur = sz++; len[cur] = len[last]+1;
    next[cur].clear(); isclone[cur] = false; int p = last;
    for(; p != -1 && !next[p].count(c); p = link[p])
      next[p][c] = cur;
    if(p == -1){ link[cur] = 0; }
    else{ int q = next[p][c];
      if(len[p] + 1 == len[q]){ link[cur] = q; }
      else { int clone = sz++; isclone[clone] = true;
        len[clone] = len[p] + 1;
        link[clone] = link[q]; next[clone] = next[q];
        for(; p != -1 && next[p].count(c) && next[p][c] == q;
              p = link[p]){
          next[p][c] = clone; }
        link[q] = link[cur] = clone;
      } } last = cur; }
  void count(){
    cnt=vi(sz, -1); stack<ii> S; S.push(ii(0,0));
    map<char,int>::iterator i;
    while(!S.empty()){
      ii cur = S.top(); S.pop();
      if(cur.second){
        for(i = next[cur.first].begin();
            i != next[cur.first].end();++i){
          cnt[cur.first] += cnt[(*i).second]; } }
      else if(cnt[cur.first] == -1){
        cnt[cur.first] = 1; S.push(ii(cur.first, 1));
        for(i = next[cur.first].begin();
            i != next[cur.first].end();++i){
          S.push(ii((*i).second, 0)); } } } }
  string lexicok(ll k){
    int st = 0; string res; map<char,int>::iterator i;
    while(k){
      for(i = next[st].begin(); i != next[st].end(); ++i){
        if(k <= cnt[(*i).second]){ st = (*i).second;
          res.push_back((*i).first); k--; break;
        } else { k -= cnt[(*i).second]; } } }
    return res; }
  void countoccur(){
    for(int i = 0; i < sz; ++i){ occur[i] = 1 - isclone[i]; }
    vii states(sz);
    for(int i = 0; i < sz; ++i){ states[i] = ii(len[i],i); }
    sort(states.begin(), states.end());
    for(int i = size(states)-1; i >= 0; --i){
      int v = states[i].second;
      if(link[v] != -1) { occur[link[v]] += occur[v]; }}}};
// vim: cc=60 ts=2 sts=2 sw=2:
