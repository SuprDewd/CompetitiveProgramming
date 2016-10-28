int* compute_pi(const string &t) {
  int m = t.size();
  int *pit = new int[m + 1];
  if (0 <= m) pit[0] = 0;
  if (1 <= m) pit[1] = 0;
  rep(i,2,m+1) {
    for (int j = pit[i - 1]; ; j = pit[j]) {
      if (t[j] == t[i - 1]) { pit[i] = j + 1; break; }
      if (j == 0) { pit[i] = 0; break; } } }
  return pit; }
int string_match(const string &s, const string &t) {
  int n = s.size(), m = t.size();
  int *pit = compute_pi(t);
  for (int i = 0, j = 0; i < n; ) {
    if (s[i] == t[j]) {
      i++; j++;
      if (j == m) {
        return i - m;
        // or j = pit[j];
      } }
    else if (j > 0) j = pit[j];
    else i++; }
  delete[] pit; return -1; }
// vim: cc=60 ts=2 sts=2 sw=2:
