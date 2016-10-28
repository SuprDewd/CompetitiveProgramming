struct segment {
  vi arr;
  segment(vi _arr) : arr(_arr) { } };
vector<segment> T;
int K;
void rebuild() {
  int cnt = 0;
  rep(i,0,size(T))
    cnt += size(T[i].arr);
  K = static_cast<int>(ceil(sqrt(cnt)) + 1e-9);
  vi arr(cnt);
  for (int i = 0, at = 0; i < size(T); i++)
    rep(j,0,size(T[i].arr))
      arr[at++] = T[i].arr[j];
  T.clear();
  for (int i = 0; i < cnt; i += K)
    T.push_back(segment(vi(arr.begin()+i,
                           arr.begin()+min(i+K, cnt)))); }
int split(int at) {
  int i = 0;
  while (i < size(T) && at >= size(T[i].arr))
    at -= size(T[i].arr), i++;
  if (i >= size(T)) return size(T);
  if (at == 0) return i;
  T.insert(T.begin() + i + 1,
      segment(vi(T[i].arr.begin() + at, T[i].arr.end())));
  T[i] = segment(vi(T[i].arr.begin(), T[i].arr.begin() + at));
  return i + 1; }
void insert(int at, int v) {
  vi arr; arr.push_back(v);
  T.insert(T.begin() + split(at), segment(arr)); }
void erase(int at) {
  int i = split(at); split(at + 1);
  T.erase(T.begin() + i); }
// vim: cc=60 ts=2 sts=2 sw=2:
