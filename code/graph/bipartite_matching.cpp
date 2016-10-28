vi* adj;
bool* done;
int* owner;
int alternating_path(int left) {
  if (done[left]) return 0;
  done[left] = true;
  rep(i,0,size(adj[left])) {
    int right = adj[left][i];
    if (owner[right] == -1 ||
        alternating_path(owner[right])) {
      owner[right] = left; return 1; } }
  return 0; }
// vim: cc=60 ts=2 sts=2 sw=2:
