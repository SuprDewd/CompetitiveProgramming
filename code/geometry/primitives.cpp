#include <complex>
#define P(p) const point &p
#define L(p0, p1) P(p0), P(p1)

typedef complex<double> point;
typedef vector<point> polygon;
double dot(P(a), P(b)) { return real(conj(a) * b); }
double cross(P(a), P(b)) { return imag(conj(a) * b); }
point rotate(P(p), P(about), double radians) {
    return (p - about) * exp(point(0, radians)) + about; }
point reflect(P(p), L(about1, about2)) {
    point z = p - about1, w = about2 - about1;
    return conj(z / w) * w + about1; }
point proj(P(u), P(v)) { return dot(u, v) / dot(u, u) * u; }
bool parallel(L(a, b), L(p, q)) { return abs(cross(b - a, q - p)) < EPS; }
double ccw(P(a), P(b), P(c)) { return cross(b - a, c - b); }
bool collinear(P(a), P(b), P(c)) { return abs(ccw(a, b, c)) < EPS; }
bool collinear(L(a, b), L(p, q)) {
    return abs(ccw(a, b, p)) < EPS && abs(ccw(a, b, q)) < EPS;  }
double angle(P(a), P(b), P(c)) {
    return acos(dot(b - a, c - b) / abs(b - a) / abs(c - b)); }
double signed_angle(P(a), P(b), P(c)) {
    return asin(cross(b - a, c - b) / abs(b - a) / abs(c - b)); }
bool intersect(L(a, b), L(p, q), point &res, bool segment = false) {
    // NOTE: check for parallel/collinear lines before calling this function
    point r = b - a, s = q - p;
    double c = cross(r, s), t = cross(p - a, s) / c, u = cross(p - a, r) / c;
    if (segment && (t < 0-EPS || t > 1+EPS || u < 0-EPS || u > 1+EPS))
        return false;
    res = a + t * r;
    return true;
}
point closest_point(L(a, b), P(c), bool segment = false) {
    if (segment) {
        if (dot(b - a, c - b) > 0) return b;
        if (dot(a - b, c - a) > 0) return a;
    }
    double t = dot(c - a, b - a) / norm(b - a);
    return a + t * (b - a);
}
double polygon_area_signed(polygon p) {
    double area = 0; int cnt = size(p);
    for (int i = 1; i + 1 < cnt; i++)
        area += cross(p[i] - p[0], p[i + 1] - p[0]);
    return area / 2;
}
double polygon_area(polygon p) { return abs(polygon_area_signed(p)); }
// pair<polygon, polygon> cut_polygon(const polygon &poly, point a, point b) {
//     polygon left, right;
//     point it(-100, -100);
//     for (int i = 0, cnt = poly.size(); i < cnt; i++) {
//         int j = i == cnt-1 ? 0 : i + 1;
//         point p = poly[i], q = poly[j];
//         if (ccw(a, b, p) <= 0) left.push_back(p);
//         if (ccw(a, b, p) >= 0) right.push_back(p);
//         // myintersect = intersect where
//         // (a,b) is a line, (p,q) is a line segment
//         if (myintersect(a, b, p, q, it))
//             left.push_back(it), right.push_back(it);
//     }
//     return pair<polygon, polygon>(left, right);
// }
