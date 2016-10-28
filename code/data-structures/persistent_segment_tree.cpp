int segcnt = 0;
struct segment {
  int l, r, lid, rid, sum;
} segs[2000000];
int build(int l, int r) {
  if (l > r) return -1;
  int id = segcnt++;
  segs[id].l = l;
  segs[id].r = r;
  if (l == r) segs[id].lid = -1, segs[id].rid = -1;
  else {
    int m = (l + r) / 2;
    segs[id].lid = build(l , m);
    segs[id].rid = build(m + 1, r); }
  segs[id].sum = 0;
  return id; }
int update(int idx, int v, int id) {
  if (id == -1) return -1;
  if (idx < segs[id].l || idx > segs[id].r) return id;
  int nid = segcnt++;
  segs[nid].l = segs[id].l;
  segs[nid].r = segs[id].r;
  segs[nid].lid = update(idx, v, segs[id].lid);
  segs[nid].rid = update(idx, v, segs[id].rid);
  segs[nid].sum = segs[id].sum + v;
  return nid; }
int query(int id, int l, int r) {
  if (r < segs[id].l || segs[id].r < l) return 0;
  if (l <= segs[id].l && segs[id].r <= r) return segs[id].sum;
  return query(segs[id].lid, l, r)
       + query(segs[id].rid, l, r); }
// vim: cc=60 ts=2 sts=2 sw=2:
