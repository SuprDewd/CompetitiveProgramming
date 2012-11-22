struct vector2d;
struct point {
	double x, y;
	point(double _x = 0, double _y = 0) { x = _x; y = _y; }
	bool operator <(point other) {
		if (abs(x - other.x) > EPS) return x < other.x;
		if (abs(y - other.y) > EPS) return y < other.y;
		return false;
	}
	bool operator ==(point other) { return abs(x - other.x) < EPS && abs(y - other.y) < EPS; }
	vector2d vectorTo(point other);
	vector2d toVector();
};
struct vector2d {
	double x, y;
	vector2d(double _x = 0, double _y = 0) { x = _x; y = _y; }
	bool operator <(vector2d other) {
		if (abs(x - other.x) > EPS) return x < other.x;
		if (abs(y - other.y) > EPS) return y < other.y;
		return false;
	}
	bool operator ==(vector2d other) { return abs(x - other.x) < EPS && abs(y - other.y) < EPS; }
	vector2d operator +(vector2d other) { return vector2d(x + other.x, y + other.y); }
	vector2d operator -(vector2d other) { return vector2d(x - other.x, y - other.y); }
	vector2d operator *(double c) { return vector2d(x * c, y * c); }
	double dot(vector2d other) { return x * other.x + y * other.y; }
	double cross(vector2d other) { return x * other.y - y * other.x; }
	double magnitudeSquared() { return dot(*this); }
	double magnitude() { return sqrt(magnitudeSquared()); }
	double angleTo(vector2d other) { return acos(dot(other) / magnitude() / other.magnitude()); }
	double signedAngleTo(vector2d other) { return asin(cross(other) / magnitude() / other.magnitude()); }
	vector2d rotate(double theta) { return vector2d(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta)); }
};
vector2d point::vectorTo(point other) { return vector2d(other.x - x, other.y - y); }
vector2d point::toVector() { return vector2d(x, y); }
double ccw(point a, point b, point c) { return a.vectorTo(b).cross(a.vectorTo(c)); }
bool collinearPoints(point a, point b, point c) {
	return abs(a.vectorTo(b).signedAngleTo(a.vectorTo(c))) < EPS;
}
point closestPointOnLine(point a, point b, point c, bool is_segment = false) {
	if (is_segment) {
		if (a.vectorTo(b).dot(b.vectorTo(c)) > 0) return b;
		if (b.vectorTo(a).dot(a.vectorTo(c)) > 0) return a;
	}
	vector2d ac = a.vectorTo(c), ab = a.vectorTo(b);
	double t = ac.dot(ab) / ab.magnitudeSquared();
	return point(a.x + ab.x * t, a.y + ab.y * t);
}
struct line {
	// ax + by + c = 0
	double a, b, c;

	line(point p1, point p2) {
		if (abs(p1.x - p2.x) < EPS) { a = 1; b = 0; c = -p1.y; }
		else {
			a = -(p1.y - p2.y) / (p1.x - p2.y);
			b = 1;
			c = -a * p1.x - b * p1.y;
		}
	}

	bool parallelTo(line other) { return abs(a - other.a) < EPS && abs(b - other.b) < EPS; }
	bool operator ==(line other) { return parallelTo(other) && abs(c - other.c) < EPS; }
	point intersection(line other) {
		assert(!parallelTo(other));
		double x = (other.b * c - b * other.c) / (other.a * b - a * other.b), y;
		if (abs(b) > EPS) y = -(a * x + c) / b;
		else y = -(other.a * x + other.c) / other.b;
		return point(x, y);
	}
};
double polygon_area_signed(vector<point>& points) {
	double area = 0; int cnt = size(points);
	for (int i = 1; i + 1 < cnt; i++) {
		area += points[0].vectorTo(points[i]).cross(points[0].vectorTo(points[i + 1]));
	}
	return area / 2;
}
double polygon_area(vector<point>& points) {
	return abs(polygon_area_signed(points));
}