#include "lines.cpp"
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
