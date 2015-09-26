#define P(p) const point &p
#define L(p0, p1) P(p0), P(p1)
#define C(p0, r) P(p0), double r
#define PP(pp) pair<point,point> &pp
typedef complex<double> point;
double dot(P(a), P(b)) { return real(conj(a) * b); }
double cross(P(a), P(b)) { return imag(conj(a) * b); }
point rotate(P(p), double radians = pi / 2, P(about) = point(0,0)) {
    return (p - about) * exp(point(0, radians)) + about; }
point reflect(P(p), L(about1, about2)) {
    point z = p - about1, w = about2 - about1;
    return conj(z / w) * w + about1; }
point proj(P(u), P(v)) { return dot(u, v) / dot(u, u) * u; }
point normalize(P(p), double k = 1.0) {
    return abs(p) == 0 ? point(0,0) : p / abs(p) * k; } //TODO: TEST
bool parallel(L(a, b), L(p, q)) { return abs(cross(b - a, q - p)) < EPS; }
double ccw(P(a), P(b), P(c)) { return cross(b - a, c - b); }
bool collinear(P(a), P(b), P(c)) { return abs(ccw(a, b, c)) < EPS; }
bool collinear(L(a, b), L(p, q)) {
    return abs(ccw(a, b, p)) < EPS && abs(ccw(a, b, q)) < EPS;  }
double angle(P(a), P(b), P(c)) {
    return acos(dot(b - a, c - b) / abs(b - a) / abs(c - b)); }
double signed_angle(P(a), P(b), P(c)) {
    return asin(cross(b - a, c - b) / abs(b - a) / abs(c - b)); }
double angle(P(p)) { return atan2(imag(p), real(p)); }
point perp(P(p)) { return point(-imag(p), real(p)); }
double progress(P(p), L(a, b)) {
    if (abs(real(a) - real(b)) < EPS)
        return (imag(p) - imag(a)) / (imag(b) - imag(a));
    else return (real(p) - real(a)) / (real(b) - real(a)); }
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
double line_segment_distance(L(a,b), L(c,d)) {
    double x = INFINITY;
    if (abs(a - b) < EPS && abs(c - d) < EPS) x = abs(a - c);
    else if (abs(a - b) < EPS) x = abs(a - closest_point(c, d, a, true));
    else if (abs(c - d) < EPS) x = abs(c - closest_point(a, b, c, true));
    else if ((ccw(a, b, c) < 0) != (ccw(a, b, d) < 0) &&
             (ccw(c, d, a) < 0) != (ccw(c, d, b) < 0)) x = 0;
    else {
        x = min(x, abs(a - closest_point(c,d, a, true)));
        x = min(x, abs(b - closest_point(c,d, b, true)));
        x = min(x, abs(c - closest_point(a,b, c, true)));
        x = min(x, abs(d - closest_point(a,b, d, true)));
    }
    return x;
}
int intersect(C(A, rA), C(B, rB), point & res1, point & res2) {
    double d = abs(B - A);
    if ((rA + rB) <  (d - EPS) || d < abs(rA - rB) - EPS) return 0;
    double a = (rA*rA - rB*rB + d*d) / 2 / d, h = sqrt(rA*rA - a*a);
    point v = normalize(B - A, a), u = normalize(rotate(B-A), h);
    res1 = A + v + u, res2 = A + v - u;
    if (abs(u) < EPS) return 1; return 2;
}
int intersect(L(A, B), C(O, r), point & res1, point & res2) {
     double h = abs(O - closest_point(A, B, O));
     if(r < h - EPS) return 0;
     point H = proj(O - A, B - A) + A, v = normalize((B - A), sqrt(r*r - h*h));
     res1 = H + v; res2 = H - v;
     if(abs(v) < EPS) return 1; return 2;
 }
int tangent(P(A), C(O, r), point & res1, point & res2) {
    point v = O - A; double d = abs(v);
    if (d < r - EPS) return 0;
    double alpha = asin(r / d), L = sqrt(d*d - r*r);
    v = normalize(v, L);
    res1 = A + rotate(v, alpha); res2 = A + rotate(v, -alpha);
    if (abs(r - d) < EPS || abs(v) < EPS) return 1;
    return 2;
}
void tangent_outer(point A, double rA, point B, double rB, PP(P), PP(Q)) {
    if (rA - rB > EPS) { swap(rA, rB); swap(A, B); }
    double theta = asin((rB - rA)/abs(A - B));
    point v = rotate(B - A, theta + pi/2), u = rotate(B - A, -(theta + pi/2));
    u = normalize(u, rA);
    P.first = A + normalize(v, rA); P.second = B + normalize(v, rB);
    Q.first = A + normalize(u, rA); Q.second = B + normalize(u, rB);
}
