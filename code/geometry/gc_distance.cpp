double gc_distance(double pLat, double pLong,
         double qLat, double qLong, double r) {
  pLat *= pi / 180; pLong *= pi / 180;
  qLat *= pi / 180; qLong *= pi / 180;
  return r * acos(cos(pLat) * cos(qLat) * cos(pLong - qLong) +
          sin(pLat) * sin(qLat)); }
// vim: cc=60 ts=2 sts=2 sw=2:
