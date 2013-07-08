#include "../data-structures/unionfind.cpp"
#define NN 1024

// Inputs (populate these).
int deg[NN];
int adj[NN][NN];

// Union-Find.
int uf[NN];
int FIND( int x ) { return uf[x] == x ? x : uf[x] = FIND( uf[x] ); }
void UNION( int x, int y ) { uf[FIND( x )] = FIND( y ); }

// dfsn[u] is the DFS number of vertex u.
int dfsn[NN], dfsnext;

// mindfsn[u] is the smallest DFS number reachable from u.
int mindfsn[NN];

// The O(1)-membership stack containing the vertices of the current component.
int comp[NN], ncomp;
bool incomp[NN];

void dfs( int n, int u )
{
  dfsn[u] = mindfsn[u] = dfsnext++;
  incomp[comp[ncomp++] = u] = true;
  for( int i = 0, v; v = adj[u][i], i < deg[u]; i++ )
  {
    if( !dfsn[v] ) dfs( n, v );
    if( incomp[v] ) mindfsn[u] = min(mindfsn[u], mindfsn[v]);
  }
  
  if( dfsn[u] == mindfsn[u] )
  {
    // u is the root of a connected component. Unify and forget it.
    do
    {
      UNION( u, comp[--ncomp] );
      incomp[comp[ncomp]] = false;
    } while( comp[ncomp] != u );
  }
}

pair<union_find, vi> tarjan_scc(vvi adj) {

    int n = size(adj);
    for (int i = 0; i < n; i++) {
        deg[i] = 0;
        for (int j = 0; j < size(adj[i]); j++) {
            adj[i][deg[i]++] = adj[i][j];
        }
    }

  // Init union-find and DFS numbers.
  for( int i = 0; i < n; i++ ) dfsn[uf[i] = i] = ncomp = incomp[i] = 0;
  dfsnext = 1;

  for( int i = 0; i < n; i++ ) if( !dfsn[i] ) dfs( n, i );

    union_find uf(n);
    for (int i = 0; i < n; i++) uf.unite(i, FIND(i));
    return pair<union_find, vi>(uf, vi());
}
