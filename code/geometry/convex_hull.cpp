#include "primitives.cpp"

point ch_main;
bool ch_cmp(const point& a, const point& b) {
    if (collinearPoints(ch_main, a, b))
        return ch_main.vectorTo(a).magnitude() < ch_main.vectorTo(b).magnitude();
    return atan2(a.y - ch_main.y, a.x - ch_main.x) < atan2(b.y - ch_main.y, b.x - ch_main.x);
}

vector<point> convex_hull(vector<point> pts, bool add_collinear = false) {
    int cnt = size(pts), main = 0, i = 1;
    if (cnt <= 3) return pts;
    for (int i = 1; i < cnt; i++)
        if (pts[i].y < pts[main].y || (abs(pts[i].y - pts[main].y) < EPS && pts[i].y > pts[main].y))
            main = i;
    swap(pts[0], pts[main]);
    ch_main = pts[0];
    sort(++pts.begin(), pts.end(), ch_cmp);
    point prev, now;
    stack<point> S; S.push(pts[cnt - 1]); S.push(pts[0]);
    while (i < cnt) {
        now = S.top(); S.pop();
        if (S.empty()) {
            S.push(now);
            S.push(pts[i++]);
        } else {
            prev = S.top();
            S.push(now);
            if (ccw(prev, now, pts[i]) > 0 || (add_collinear && abs(ccw(prev, now, pts[i])) < EPS)) S.push(pts[i++]);
            else S.pop();
        }
    }
    vector<point> res;
    while (!S.empty()) res.push_back(S.top()), S.pop();
    return res;
}
