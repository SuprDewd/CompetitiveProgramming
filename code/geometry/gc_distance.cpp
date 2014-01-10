double gc_distance(double pLat, double pLong,
                  double qLat, double qLong, double r) {
    pLat *= pi / 180; pLong *= pi / 180;
    qLat *= pi / 180; qLong *= pi / 180;
    return r * acos(cos(pLat) * cos(pLong) * cos(qLat) * cos(qLong) +
                    cos(pLat) * sin(pLong) * cos(qLat) * sin(qLong) +
                    sin(pLat) * sin(qLat)); }
