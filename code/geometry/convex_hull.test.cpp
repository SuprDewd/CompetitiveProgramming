
void check(int mxn, int x) {
  bool kill = true;
  int n = randint(1,mxn);
  polygon p;
  rep(i,0,n) {
    p.push_back(point(randint(0,x), randint(0,x)));
  }
  int cnt = convex_hull(p);
  polygon q;
  rep(i,0,cnt) q.push_back(hull[i]);
  rep(i,0,size(q)) {
    rep(j,0,i) {
      assert_not_equal(q[i], q[j], kill);
    }
  }
  if (size(q) >= 3) {
    rep(i,0,size(q)) {
      int j = (i+1) % size(q),
        k = (i+2) % size(q);
      assert_true(ccw(q[i], q[j], q[k]) < 0, kill);
    }
    rep(i,0,size(p)) {
      assert_true(point_in_polygon(q, p[i]) <= 0, kill);
    }
  }
}

void test() {
  /* Field testing: UVa 681 */

  // polygon p;
  // p.push_back(point(1,1));
  // p.push_back(point(2,2));
  // p.push_back(point(3,3));
  // p.push_back(point(4,4));
  // p.push_back(point(1,-1));
  // p.push_back(point(2,-2));
  // p.push_back(point(3,-3));
  // p.push_back(point(4,-4));
  //
  // int cnt = convex_hull(p);
  // rep(i,0,cnt) {
  //     cout << hull[i] << endl;
  // }
  //
  // return;

  rep(n,1,20) {
    rep(k,1,100) {
      rep(it,0,1000) check(n,k);
    }
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
