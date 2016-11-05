struct sparse_table { vvi m;
  sparse_table(vi arr) {
    m.push_back(arr);
    for (int k = 0; (1<<(++k)) <= size(arr); ) {
      m.push_back(vi(size(arr)-(1<<k)+1));
      rep(i,0,size(arr)-(1<<k)+1)
        m[k][i] = min(m[k-1][i], m[k-1][i+(1<<(k-1))]); } }
  int query(int l, int r) {
    int k = 0; while (1<<(k+1) <= r-l+1) k++;
    return min(m[k][l], m[k][r-(1<<k)+1]); } };
// vim: cc=60 ts=2 sts=2 sw=2:
