#define MAXV 300
bool marked[MAXV], emarked[MAXV][MAXV];
int S[MAXV];
vi find_augmenting_path(const vector<vi> &adj,const vi &m){
  int n = size(adj), s = 0;
  vi par(n,-1), height(n), root(n,-1), q, a, b;
  memset(marked,0,sizeof(marked));
  memset(emarked,0,sizeof(emarked));
  rep(i,0,n) if (m[i] >= 0) emarked[i][m[i]] = true;
             else root[i] = i, S[s++] = i;
  while (s) {
    int v = S[--s];
    iter(wt,adj[v]) {
      int w = *wt;
      if (emarked[v][w]) continue;
      if (root[w] == -1) {
        int x = S[s++] = m[w];
        par[w]=v, root[w]=root[v], height[w]=height[v]+1;
        par[x]=w, root[x]=root[w], height[x]=height[w]+1;
      } else if (height[w] % 2 == 0) {
        if (root[v] != root[w]) {
          while (v != -1) q.push_back(v), v = par[v];
          reverse(q.begin(), q.end());
          while (w != -1) q.push_back(w), w = par[w];
          return q;
        } else {
          int c = v;
          while (c != -1) a.push_back(c), c = par[c];
          c = w;
          while (c != -1) b.push_back(c), c = par[c];
          while (!a.empty()&&!b.empty()&&a.back()==b.back())
            c = a.back(), a.pop_back(), b.pop_back();
          memset(marked,0,sizeof(marked));
          fill(par.begin(), par.end(), 0);
          iter(it,a) par[*it] = 1; iter(it,b) par[*it] = 1;
          par[c] = s = 1;
          rep(i,0,n) root[par[i] = par[i] ? 0 : s++] = i;
          vector<vi> adj2(s);
          rep(i,0,n) iter(it,adj[i]) {
            if (par[*it] == 0) continue;
            if (par[i] == 0) {
              if (!marked[par[*it]])  {
                adj2[par[i]].push_back(par[*it]);
                adj2[par[*it]].push_back(par[i]);
                marked[par[*it]] = true; }
            } else adj2[par[i]].push_back(par[*it]); }
          vi m2(s, -1);
          if (m[c] != -1) m2[m2[par[m[c]]] = 0] = par[m[c]];
          rep(i,0,n) if(par[i]!=0&&m[i]!=-1&&par[m[i]]!=0)
            m2[par[i]] = par[m[i]];
          vi p = find_augmenting_path(adj2, m2);
          int t = 0;
          while (t < size(p) && p[t]) t++;
          if (t == size(p)) {
            rep(i,0,size(p)) p[i] = root[p[i]];
            return p; }
          if (!p[0] || (m[c] != -1 && p[t+1] != par[m[c]]))
            reverse(p.begin(), p.end()), t = size(p)-t-1;
          rep(i,0,t) q.push_back(root[p[i]]);
          iter(it,adj[root[p[t-1]]]) {
            if (par[*it] != (s = 0)) continue;
            a.push_back(c), reverse(a.begin(), a.end());
            iter(jt,b) a.push_back(*jt);
            while (a[s] != *it) s++;
            if ((height[*it] & 1) ^ (s < size(a) - size(b)))
              reverse(a.begin(), a.end()), s = size(a)-s-1;
            while(a[s]!=c)q.push_back(a[s]),s=(s+1)%size(a);
            q.push_back(c);
            rep(i,t+1,size(p)) q.push_back(root[p[i]]);
            return q; } } }
      emarked[v][w] = emarked[w][v] = true; }
    marked[v] = true; } return q; }
vii max_matching(const vector<vi> &adj) {
  vi m(size(adj), -1), ap; vii res, es;
  rep(i,0,size(adj)) iter(it,adj[i]) es.emplace_back(i,*it);
  random_shuffle(es.begin(), es.end());
  iter(it,es) if (m[it->first] == -1 && m[it->second] == -1)
    m[it->first] = it->second, m[it->second] = it->first;
  do { ap = find_augmenting_path(adj, m);
       rep(i,0,size(ap)) m[m[ap[i^1]] = ap[i]] = ap[i^1];
  } while (!ap.empty());
  rep(i,0,size(m)) if (i < m[i]) res.emplace_back(i, m[i]);
  return res; }
// vim: cc=60 ts=2 sts=2 sw=2:
