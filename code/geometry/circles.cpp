#include "lines.cpp"
int intersect(C(A, rA), C(B, rB), point &r1, point &r2) {
  double d = abs(B - A);
  if ((rA + rB) <  (d - EPS) || d < abs(rA - rB) - EPS)
    return 0;
  double a = (rA*rA - rB*rB + d*d) / 2 / d,
         h = sqrt(rA*rA - a*a);
  point v = normalize(B - A, a),
        u = normalize(rotate(B-A), h);
  r1 = A + v + u, r2 = A + v - u;
  return 1 + (abs(u) >= EPS); }
int intersect(L(A, B), C(O, r), point &r1, point &r2) {
  point H = proj(B-A, O-A) + A; double h = abs(H-O);
  if (r < h - EPS) return 0;
  point v = normalize(B-A, sqrt(r*r - h*h));
  r1 = H + v, r2 = H - v;
  return 1 + (abs(v) > EPS); }
int tangent(P(A), C(O, r), point &r1, point &r2) {
  point v = O - A; double d = abs(v);
  if (d < r - EPS) return 0;
  double alpha = asin(r / d), L = sqrt(d*d - r*r);
  v = normalize(v, L);
  r1 = A + rotate(v, alpha), r2 = A + rotate(v, -alpha);
  return 1 + (abs(v) > EPS); }
void tangent_outer(point A, double rA,
                   point B, double rB, PP(P), PP(Q)) {
  if (rA - rB > EPS) { swap(rA, rB); swap(A, B); }
  double theta = asin((rB - rA)/abs(A - B));
  point v = rotate(B - A, theta + pi/2),
        u = rotate(B - A, -(theta + pi/2));
  u = normalize(u, rA);
  P.first = A + normalize(v, rA);
  P.second = B + normalize(v, rB);
  Q.first = A + normalize(u, rA);
  Q.second = B + normalize(u, rB); }
// vim: cc=60 ts=2 sts=2 sw=2:
