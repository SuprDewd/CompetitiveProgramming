#include "primitives.cpp"
point ch_main;
bool ch_cmp(P(a), P(b)) {
    if (collinear(ch_main, a, b)) return abs(a - ch_main) < abs(b - ch_main);
    return atan2(imag(a) - imag(ch_main), real(a) - real(ch_main)) < atan2(imag(b) - imag(ch_main),
            real(b) - real(ch_main)); }
polygon convex_hull(polygon pts, bool add_collinear = false) {
    int cnt = size(pts), main = 0, i = 1;
    if (cnt <= 3) return pts;
    for (int i = 1; i < cnt; i++)
        if (imag(pts[i]) < imag(pts[main]) || abs(imag(pts[i]) - imag(pts[main]) < EPS &&
                    imag(pts[i]) > imag(pts[main])))
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
            if (ccw(prev, now, pts[i]) > 0 || (add_collinear && abs(ccw(prev, now, pts[i])) < EPS))
                S.push(pts[i++]);
            else S.pop();
        } }
    vector<point> res;
    while (!S.empty()) res.push_back(S.top()), S.pop();
    return res;
}
