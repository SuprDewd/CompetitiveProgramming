#include "lines.cpp"
struct caliper {
  ii pt;
  double angle;
  caliper(ii _pt, double _angle) : pt(_pt), angle(_angle) { }
  double angle_to(ii pt2) {
    double x = angle - atan2(pt2.second - pt.second,
                             pt2.first - pt.first);
    while (x >= pi) x -= 2*pi;
    while (x <= -pi) x += 2*pi;
    return x; }
  void rotate(double by) {
    angle -= by;
    while (angle < 0) angle += 2*pi; }
  void move_to(ii pt2) { pt = pt2; }
  double dist(const caliper &other) {
    point a(pt.first,pt.second),
       b = a + exp(point(0,angle)) * 10.0,
       c(other.pt.first, other.pt.second);
    return abs(c - closest_point(a, b, c)); } };
// int h = convex_hull(pts);
// double mx = 0;
// if (h > 1) {
//     int a = 0,
//         b = 0;
//     rep(i,0,h) {
//         if (hull[i].first < hull[a].first)
//             a = i;
//         if (hull[i].first > hull[b].first)
//             b = i; }
//     caliper A(hull[a], pi/2), B(hull[b], 3*pi/2);
//     double done = 0;
//     while (true) {
//         mx = max(mx, abs(point(hull[a].first,hull[a].second)
//                     - point(hull[b].first,hull[b].second)));
//         double tha = A.angle_to(hull[(a+1)%h]),
//                 thb = B.angle_to(hull[(b+1)%h]);
//         if (tha <= thb) {
//             A.rotate(tha);
//             B.rotate(tha);
//             a = (a+1) % h;
//             A.move_to(hull[a]);
//         } else {
//             A.rotate(thb);
//             B.rotate(thb);
//             b = (b+1) % h;
//             B.move_to(hull[b]); }
//         done += min(tha, thb);
//         if (done > pi) {
//             break;
//         } } }
// vim: cc=60 ts=2 sts=2 sw=2:
