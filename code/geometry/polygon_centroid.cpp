#include "polygon.cpp"
point polygon_centroid(polygon p) {
    double cx = 0.0, cy = 0.0;
    double mnx = 0.0, mny = 0.0;
    int n = size(p);
    for (int i = 0; i < n; i++)
        mnx = min(mnx, real(p[i])),
        mny = min(mny, imag(p[i]));
    for (int i = 0; i < n; i++)
        p[i] = point(real(p[i]) - mnx, imag(p[i]) - mny);
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        cx += (real(p[i]) + real(p[j])) * cross(p[i], p[j]);
        cy += (imag(p[i]) + imag(p[j])) * cross(p[i], p[j]); }
    return point(cx, cy) / 6.0 / polygon_area_signed(p) + point(mnx, mny); }
