template <int K>
struct naive_kd_tree {

  struct point {
    double coord[K];
    point() {}
    point(double c[K]) {
      for (int i = 0; i < K; i++)
        coord[i] = c[i];
    }

    double dist_to(const point &other) const {
      double sum = 0.0;
      for (int i = 0; i < K; i++)
        sum += pow(coord[i] - other.coord[i], 2.0);
      return sqrt(sum);
    }

    bool operator <(const point &other) const {
      for (int i = 0; i < K; i++)
        if (abs(coord[i] - other.coord[i]) > EPS)
          return coord[i] < other.coord[i];
      return false;
    }
  };

  set<point> pts;

  naive_kd_tree() { }
  naive_kd_tree(vector<point> _pts) {
    for (int i = 0; i < size(_pts); i++) {
      pts.insert(_pts[i]);
    }
  }

  bool contains(const point &p) {
    return pts.find(p) != pts.end();
  }

  void insert(const point &p) {
    pts.insert(p);
  }

  pair<point, bool> nearest_neighbour(const point &p, bool allow_same = true) {
    double mn = INFINITY;
    point res;
    bool found = false;
    for (typename set<point>::const_iterator it = pts.begin(); it != pts.end(); ++it) {
      double dist = p.dist_to(*it);
      if (abs(dist) < EPS && !allow_same) continue;
      if (dist < mn) {
        mn = dist;
        res = *it;
        found = true;
      }
    }
    return make_pair(res, found);
  }
};

#define CURK 3

double pt[CURK];
void randomize_pt() {
  double lo = -10,
      hi = 10;

  for (int i = 0; i < CURK; i++) {
    pt[i] = static_cast<double>(rand()) / RAND_MAX * (hi - lo) + lo;
    pt[i] = round(pt[i] * 3.0) / 3.0;
  }
}

#define TREE1 1
#define TREE2 1

void test() {
  /* Field testing: UVa 10245 */

  for (int t = 0; t < 100; t++) {
    // printf("%d\n", t);

    int startcnt = rand() % 1000;

    vector<kd_tree<CURK>::pt> pts1(startcnt);
    vector<naive_kd_tree<CURK>::point> pts2(startcnt);

    for (int i = 0; i < startcnt; i++) {
      randomize_pt();
      pts1[i] = kd_tree<CURK>::pt(pt);
      pts2[i] = naive_kd_tree<CURK>::point(pt);
    }

#if TREE1
    kd_tree<CURK> tree1(pts1);
#endif

#if TREE2
    naive_kd_tree<CURK> tree2(pts2);
#endif

    for (int i = 0; i < startcnt; i++) {
#if TREE1
      assert(tree1.contains(pts1[i]));
#endif

#if TREE2
      assert(tree2.contains(pts2[i]));
#endif
    }

    int ops = 1000;
    int found = 0;
    for (int cop = 0; cop < ops; cop++) {
      int op = rand() % 3;

      if (op == 0) {
        // insert
        randomize_pt();
#if TREE1
        tree1.insert(kd_tree<CURK>::pt(pt));
#endif

#if TREE2
        tree2.insert(naive_kd_tree<CURK>::point(pt));
#endif
      } else if (op == 1) {
        // contains
        randomize_pt();
#if TREE1
        bool a = tree1.contains(kd_tree<CURK>::pt(pt));
#endif

#if TREE2
        bool b = tree2.contains(naive_kd_tree<CURK>::point(pt));
#endif

#if TREE1
        if (a) found++;
#endif

        // printf("%d %d\n", a, b);

#if TREE1 && TREE2
        assert(a == b);
#endif
      } else if (op == 2) {
        // nearest neighbour
        randomize_pt();
        bool allow_same = rand() % 2 == 0;
        // bool allow_same = true;
#if TREE1
        pair<kd_tree<CURK>::pt, bool> a = tree1.nearest_neighbour(kd_tree<CURK>::pt(pt), allow_same);
#endif

#if TREE2
        pair<naive_kd_tree<CURK>::point, bool> b = tree2.nearest_neighbour(naive_kd_tree<CURK>::point(pt), allow_same);
#endif

#if TREE1 && TREE2
        assert(a.second == b.second);
#endif
#if TREE1
        if (!a.second) continue;
#endif
#if TREE2
        if (!b.second) continue;
#endif

#if TREE1
        double x = a.first.dist(kd_tree<CURK>::pt(pt));
#endif

#if TREE2
        double y = b.first.dist_to(naive_kd_tree<CURK>::point(pt));
#endif

#if TREE1 && TREE2
        if (abs(x - y) > EPS) {
          cout << x << " " << y << endl;
          assert(false);
        }
#endif
      }
    }

    // printf("%d %d\n", found, ops);

#if TREE1
    tree1.clear();
#endif
  }

}
// vim: cc=60 ts=2 sts=2 sw=2:
