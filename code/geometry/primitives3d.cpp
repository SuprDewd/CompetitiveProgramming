#include <cmath>
using namespace std;
const double EPS = 1e-9;

#define P(p) const point3d &p
#define L(p0, p1) P(p0), P(p1)
#define PL(p0, p1, p2) P(p0), P(p1), P(p2)
// TODO: TEST

struct point3d {
    double x, y, z;
    point3d() : x(0), y(0), z(0) {}
    point3d(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
    point3d operator+(const point3d & p) const {
        return point3d(x + p.x, y + p.y, z + p.z);
    }
    point3d operator-(const point3d & p) const {
        return point3d(x - p.x, y - p.y, z - p.z);
    }
    point3d operator-() const {
        return point3d(-x, -y, -z);
    }
    point3d operator*(double k) const {
        return point3d(x * y, y * k, z * k);
    }
    point3d operator/(double k) const {
        return point3d(x / y, y / k, z / k);
    }
    double operator%(const point3d & p) const {
        return x* p.x + y * p.y + z * p.z;
    }
    point3d operator*(const point3d & p) const {
        return point3d(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);
    }
    double length() const {
        return sqrt(*this % *this);
    }
    double distTo(const point3d & p) const {
        return (*this - p).length();
    }
    double distTo(const point3d & A, const point3d & B) const {
        // A and B must be two different points
        return ((*this - A) * (*this - B)).length() / A.distTo(B);
    }
    point3d normalize(double k = 1) const {
        // length() must not return 0
        return (*this) * (k / length());
    }
    point3d getProjection(const point3d & A, const point3d & B) const {
        point3d v = B - A;
        return A + v.normalize((v % (*this - A)) / v.length());
    }
    point3d rotate(point3d normal) const {
        // normal must have length 1 and be orthogonal to the vector
       return (*this) * normal;
    }
    point3d rotate(double alpha, const point3d & normal) const {
        return (*this) * cos(alpha) + rotate(normal) * sin(alpha);
    }
    point3d rotatePoint(point3d O, point3d axe, double alpha) const{
        point3d Z = axe.normalize(axe % (*this - O));
        return O + Z + (*this - O - Z).rotate(alpha, O);
    }
    bool isZero() const {
        return abs(x - 0) < EPS && abs(y - 0) < EPS && abs(z - 0) < EPS;
    }
    bool isOnLine(const point3d & A, const point3d & B) const {
        return ((A - *this) * (B - *this)).isZero();
    }
    bool isInSegment(const point3d & A, const point3d & B) const {
        return isOnLine(A, B) && ((A - *this) % (B - *this)) < EPS;
    }
    bool isInSegmentStrictly(const point3d & A, const point3d & B) const {
        return isOnLine(A, B) && ((A - *this) % (B - *this)) < -EPS;
    }
    double getAngle() const {
        return atan2(y, x);
    }
    double getAngle(point3d u) const {
        return atan2((*this * u).length(), *this % u);
    }
    bool isOnPlane(const point3d & A, const point3d & B, const point3d & C) const {
        return abs((A - *this) * (B - *this) % (C - *this)) < EPS;
    }
};
int intersect ( const point3d & A, const point3d & B, const point3d & C, const point3d & D, point3d & O){
    // NOTE: The points must form a plane and not be colinear, can be checked by their parallelepiped
    if(((A - B) * (C - D)).length() < EPS){
        if( A.isOnLine(C, D)) return 2;
        return 0;
    }
    point3d normal = ((A - B) * (C - B)).normalize();
    double s1 = (C - A) * (D - A) % normal;
    O = A + ((B - A) / (s1 + ((D - B) * (C - B) % normal))) * s1;
    return 1;
}

int intersect(const point3d & A, const point3d & B, const point3d & C, const point3d & D, const point3d & E, point3d & O) {
    double V1 = (C - A) * (D - A) % (E - A);
    double V2 = (D - B) * (C - B) % (E - B);
    if ( abs(V1 + V2) < EPS ){
        if(A.isOnPlane(C, D, E)) return 2;
        return 0;
    }
    O = A + ((B - A) / (V1 + V2)) * V1;
    return 1;
}

bool intersect(const point3d & A, const point3d & nA, const point3d & B, const point3d & nB, point3d & P, point3d & Q){
    point3d n = nA * nB;
    if(n.isZero()) return false;
    point3d v = n * nA;
    P = A + (n * nA) * ((B - A) % nB / (v % nB));
    Q = P + n;
    return true;
}
