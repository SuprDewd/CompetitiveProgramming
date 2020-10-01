
double INF = 1e100;
double EPS = 1e-12;


struct line
{	double a, b, c; // ax+by=c
	line() {}
	// Construct line through (x1,y1) and (x2,y2)
	line (int x1, int y1, int x2, int y2)
	{	/*int d = __gcd(abs(x1-x2), abs(y1-y2));
		if (x1-x2 < 0)
			d = -d;
		a = -(y1-y2)/d;
		b = (x1-x2)/d;
		c = a*x1 + b*y1;*/
		a = y1 - y2;
		b = x2 - x1;
		double k = sqrt(a * a + b * b);
		a /= k, b /= k;
		if(a < -EPS || (a < EPS && b < -EPS))
			a = -a, b = -b;
		c = -(a * x1 + b * y1);
	}
};

bool operator < (line L1, line L2)
{	return L1.a < L2.a || (L1.a == L2.a && (L1.b < L2.b || (L1.b == L2.b && L1.c < L2.c)));

}

struct PT {
	double x, y;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}
	PT(const PT &p) : x(p.x), y(p.y)    {}
	PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
	PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
	PT operator * (double c)     const { return PT(x*c,   y*c  ); }
	PT operator / (double c)     const { return PT(x/c,   y/c  ); }
	bool operator<( const PT &p ) const{return make_pair ( x, y ) <    make_pair ( p.x, p.y );}
	bool operator==( const PT &p ) const{return make_pair ( x, y ) == make_pair ( p.x, p.y );}
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
	os << "(" << p.x << "," << p.y << ")";
}

// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p)   { return PT(-p.y,p.x); }
PT RotateCW90(PT p)    { return PT(p.y,-p.x); }
PT RotateCCW(PT p, double t) {
	return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}

// project point c onto line through a and b
// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c) {
	return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

PT reflectAroundLine(PT p, PT a, PT b) {
	return ProjectPointLine(p,a,b) * 2.0 - p;
}

// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c) {
	double r = dot(b-a,b-a);
	if (fabs(r) < EPS) return a;
	r = dot(c-a, b-a)/r;
	if (r < 0) return a;
	if (r > 1) return b;
	return a + (b-a)*r;
}

// compute distance from c to segment between a and b
double DistancePointSegment(PT a, PT b, PT c) {
	return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}

// compute distance between point (x,y,z) and plane ax+by+cz=d
double DistancePointPlane(double x, double y, double z,
						  double a, double b, double c, double d)
{
	return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}

// 1 = RIGTH, 0 = collinear, -1 = LEFT
int isLeft(PT o,PT a,PT b) {
	double isLeft = cross(a - o, b - o);
	return isLeft < -EPS ? -1 : (isLeft > EPS ? 1 : 0 );
}

// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(PT a, PT b, PT c, PT d) {
	return fabs(cross(b-a, c-d)) < EPS;
}

bool LinesCollinear(PT a, PT b, PT c, PT d) {
	return LinesParallel(a, b, c, d)
		   && fabs(cross(a-b, a-c)) < EPS
		   && fabs(cross(c-d, c-a)) < EPS;
}

// determine if line segment from a to b intersects with
// line segment from c to d
bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
	if (LinesCollinear(a, b, c, d)) {
		if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
			dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
		if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
			return false;
		return true;
	}
	if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
	if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
	return true;
}


// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if
// segments intersect first
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
	b=b-a; d=c-d; c=c-a;
	assert(dot(b, b) > EPS && dot(d, d) > EPS);
	return a + b*cross(c, d)/cross(b, d);
}

#define pdd pair<double, double>
pdd lineLineIntersection(pdd A, pdd B, pdd C, pdd D)
{
	double a1 = B.second - A.second;
	double b1 = A.first - B.first;
	double c1 = a1*(A.first) + b1*(A.second);
	double a2 = D.second - C.second;
	double b2 = C.first - D.first;
	double c2 = a2*(C.first)+ b2*(C.second);

	double determinant = a1*b2 - a2*b1;

	if (determinant == 0)
		return make_pair(FLT_MAX, FLT_MAX);

	double x = (b2*c1 - b1*c2)/determinant;
	double y = (a1*c2 - a2*c1)/determinant;

	if(!((x >= A.f && x <= B.f) || (x >= B.f && x <= A.f)))
		return make_pair(FLT_MAX, FLT_MAX);
	if(!((x >= C.f && x <= D.f) || (x >= D.f && x <= C.f)))
		return make_pair(FLT_MAX, FLT_MAX);
	if(!((y >= A.s && y <= B.s) || (y >= B.s && y <= A.s)))
		return make_pair(FLT_MAX, FLT_MAX);
	if(!((y >= C.s && y <= D.s) || (y >= D.s && y <= C.s)))
		return make_pair(FLT_MAX, FLT_MAX);
	return make_pair(x, y);
}

// compute center of circle given three points
PT ComputeCircleCenter(PT a, PT b, PT c) {
	b=(a+b)/2;
	c=(a+c)/2;
	return ComputeLineIntersection(b, b+RotateCW90(a-b), c, c+RotateCW90(a-c));
}

// determine if point is in a possibly non-convex polygon (by William
// Randolph Franklin); returns 1 for strictly interior points, 0 for
// strictly exterior points, and 0 or 1 for the remaining points.
// Note that it is possible to convert this into an *exact* test using
// integer arithmetic by taking care of the division appropriately
// (making sure to deal with signs properly) and then by writing exact
// tests for checking point on polygon boundary
bool PointInPolygon(const vector<PT> &p, PT q) {
	bool c = 0;
	for (int i = 0; i < p.size(); i++){
		int j = (i+1)%p.size();
		if ((p[i].y <= q.y && q.y < p[j].y ||
			 p[j].y <= q.y && q.y < p[i].y) &&
			q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
			c = !c;
	}
	return c;
}

// determine if point is on the boundary of a polygon
bool PointOnPolygon(const vector<PT> &p, PT q) {
	for (int i = 0; i < p.size(); i++)
		if (dist2(ProjectPointSegment(p[i], p[(i+1)%p.size()], q), q) < EPS)
			return true;
	return false;
}

// compute intersection of line through points a and b with
// circle centered at c with radius r > 0
vector<PT> CircleLineIntersection(PT a, PT b, PT c, double r) {
	vector<PT> ret;
	b = b-a;
	a = a-c;
	double A = dot(b, b);
	double B = dot(a, b);
	double C = dot(a, a) - r*r;
	double D = B*B - A*C;
	if (D < -EPS) return ret;
	ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
	if (D > EPS)
		ret.push_back(c+a+b*(-B-sqrt(D))/A);
	return ret;
}

// compute intersection of circle centered at a with radius r
// with circle centered at b with radius R
vector<PT> CircleCircleIntersection(PT a, PT b, double r, double R) {
	vector<PT> ret;
	double d = sqrt(dist2(a, b));
	if (d > r+R || d+min(r, R) < max(r, R)) return ret;
	double x = (d*d-R*R+r*r)/(2*d);
	double y = sqrt(r*r-x*x);
	PT v = (b-a)/d;
	ret.push_back(a+v*x + RotateCCW90(v)*y);
	if (y > 0)
		ret.push_back(a+v*x - RotateCCW90(v)*y);
	return ret;
}

//return the common area of two circle
double cirAreaCut(double a, double r) {
	double s1 = a * r * r / 2;
	double s2 = sin(a) * r * r / 2;
	return s1 - s2;
}
double commonCircleArea(PT c1, double r, PT c2, double R) {
	if (r < R) swap(c1, c2),swap(r,R);
	double d = sqrt(dist2(c1,c2));
	if (d + R <= r + EPS) return R*R*acos(-1.0);
	if (d >= r + R - EPS) return 0.0;
	double a1 = acos((d*d + r*r - R*R) / 2 / d / r);
	double a2 = acos((d*d + R*R - r*r) / 2 / d / R);
	return cirAreaCut(a1*2, r) + cirAreaCut(a2*2, R);
}

pair<PT,double> getCircumcircle(PT a, PT b, PT c) {
	double d = 2.0 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
	assert(fabs(d) > EPS);
	double x = (dot(a,a) * (b.y - c.y) + dot(b,b) * (c.y - a.y) + dot(c,c)* (a.y - b.y)) / d;
	double y = (dot(a,a) * (c.x - b.x) + dot(b,b) * (a.x - c.x) + dot(c,c)* (b.x - a.x)) / d;
	PT p(x, y);
	return {p, sqrt(dist2(p,a))};
}
pair<PT,double> getEnclosingCircle(vector<PT> &p) {
	random_shuffle(p.begin(), p.end());
	PT c(0,0);
	double r = 0;
	int n = p.size();
	for (int i = 1; i < n; i++)
		if (dist2(p[i],c) > r * r + EPS) {
			c = p[i],r = 0;
			for (int j = 0; j < i; j++)
				if (dist2(p[j],c) > r * r + EPS) {
					c = (p[i] + p[j]) / 2, r = sqrt(dist2(p[i], p[j])) / 2;
					for (int k = 0; k < j; k++)
						if (dist2(p[k],c) > r * r + EPS) {
							auto cir = getCircumcircle(p[i], p[j], p[k]);
							c = cir.first;
							r = cir.second;
						}
				}
		}
	return {c,r};
}
vector<PT> pointCircleTangent(const PT &x, double r, const PT &a) {
	double dist = dist2(x,a);
	vector<PT> res;
	if(fabs(dist) < EPS)
		res.push_back(a);
	else if(dist > r * 1LL * r) {
		PT v = a - x;
		v = v * (r * 1.0 / sqrt(dist));
		double theta = acos(sqrt(dist) / r);
		res.push_back(x + RotateCCW(v, theta));
		res.push_back(x + RotateCCW(v, -theta));
	}
	return res;
}
vector<PT> circleCircleTangent(PT &a, int r1, PT &b, int r2) {
	vector<PT> res;
	if(r1 == r2) {
		PT v = (b - a) / sqrt(dist2(a,b));
		PT p1 = PT(-v.y, v.x) * r1;
		PT p2 = PT(v.y, -v.x) * r1;
		res.push_back(p1 + a);
		res.push_back(p2 + a);
		res.push_back(p1 + b);
		res.push_back(p2 + b);
		return res;
	}
	if(r1 < r2) {
		swap(a, b);
		swap(r1, r2);
	}
	double r = r1 - r2;
	res = pointCircleTangent(a, r, b);
	PT t1 = res[0], t2 = res[1];
	PT p1 = (t1 - a) / sqrt(dist2(a,t1));
	PT p2 = (t2 - a) / sqrt(dist2(a,t1));
	res.push_back(p1 * r1 + a);
	res.push_back(p2 * r1 + a);
	res.push_back(p1 * r2 + b);
	res.push_back(p2 * r2 + b);
	return res;
}


// This code computes the area or centroid of a (possibly nonconvex)
// polygon, assuming that the coordinates are listed in a clockwise or
// counterclockwise fashion.  Note that the centroid is often known as
// the "center of gravity" or "center of mass".
double ComputeSignedArea(const vector<PT> &p) {
	double area = 0;
	for(int i = 0; i < p.size(); i++) {
		int j = (i+1) % p.size();
		area += p[i].x*p[j].y - p[j].x*p[i].y;
	}
	return area / 2.0;
}

double ComputeArea(const vector<PT> &p) {
	return fabs(ComputeSignedArea(p));
}

PT ComputeCentroid(const vector<PT> &p) {
	PT c(0,0);
	double scale = 6.0 * ComputeSignedArea(p);
	for (int i = 0; i < p.size(); i++){
		int j = (i+1) % p.size();
		c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);
	}
	return c / scale;
}

// tests whether or not a given polygon (in CW or CCW order) is simple
bool IsSimple(const vector<PT> &p) {
	for (int i = 0; i < p.size(); i++) {
		for (int k = i+1; k < p.size(); k++) {
			int j = (i+1) % p.size();
			int l = (k+1) % p.size();
			if (i == l || j == k) continue;
			if (SegmentsIntersect(p[i], p[j], p[k], p[l]))
				return false;
		}
	}
	return true;
}

bool PolygonIsConvex(const vector<PT> &P) {
	int n = (int) P.size();
	if (n <= 2) return false;
	int start = isLeft(P[0],P[1],P[2]);
	for (int i = 1; i < n; i++)
		if (isLeft(P[i], P[(i+1) % n], P[(i+2) % n]) * start < 0)
			return false;
	return true;
}


vector < PT > convexHull( vector < PT > &poly ){
	sort ( poly.begin (), poly.end ());
	vector < PT > res;
	for( int i = 0 ; i < ( int ) poly.size () ; i++ ){
		while( res.size () > 1 && cross ( res.back () - res[res.size () - 2], poly[i] - res[res.size () - 2] ) <= 0 )
			res.pop_back ();
		res.push_back ( poly[i] );
	}
	int t = res.size ();
	for( int i = ( int ) poly.size () - 1 ; i >= 0 ; i-- ){
		while(( int ) res.size () > t &&
			  cross (res.back () - res[res.size () - 2], poly[i] - res[res.size () - 2] ) <= 0 )
			res.pop_back ();
		res.push_back ( poly[i] );
	}
	if(res.size ())
		res.pop_back ();
	poly = res;
	return res;
}

// modifaied cress product..
inline ll CROSS(PT o, PT a,PT b){
	return (a.y * b.x * o.x * o.y - a.y * o.x * b.x * b.y - o.y * b.x * a.x * a.y + a.x * b.x * a.y * b.y) -
		   (a.x * b.y * o.x * o.y - a.x * o.y * b.x * b.y - o.x * b.y * a.x * a.y + a.x * b.x * a.y * b.y);
}

vector < PT > upperHull( vector < PT > &poly ){
	sort ( poly.begin (), poly.end ());
	poly.erase(unique (poly.begin (), poly.end ()), poly.end ());
	vector < PT > res;
	for( int i = ( int ) poly.size () - 1 ; i >= 0 ; i-- ){
		while(( int ) res.size () > 1 &&
			  CROSS (res[res.size () - 2], res[res.size () - 1], poly[i]) < 0 )
			res.pop_back ();
		res.push_back ( poly[i] );
	}
	poly = res;
	return res;
}

// polygon polygon intersect O(N*M)
int sgn (double x) {
	if (x > EPS)
		return 1;
	else
	if (x < -EPS)
		return -1;
	return 0;
}

vector <PT> isect (vector <PT> A, PT p1, PT p2, PT P) {
	double a = p1.y - p2.y;
	double b = p2.x - p1.x;
	double c = - a * p1.x - b * p1.y;
	int W = sgn (P.x * a + P.y * b + c);
	vector <PT> res;
	for (int i = 0;i < A.size(); i++) {
		if (sgn (A[i].x * a + A[i].y * b + c) * W >= 0)
			res.push_back (A[i]);
		int next = (i + 1) % A.size();
		if (sgn (A[i].x * a + A[i].y * b + c) * sgn (A[next].x * a + A[next].y * b + c) < 0) {
			double a1 = A[i].y - A[next].y;
			double b1 = A[next].x - A[i].x;
			double c1 = -a1 * A[i].x - b1 * A[i].y;
			double d =  a * b1 - b * a1;
			double dx = b * c1 - c * b1;
			double dy = c * a1 - a * c1;
			PT tmp (dx / d, dy / d);
			res.push_back (tmp);
		}
	}
	return res;
}

vector <PT> intersect (vector <PT> A, vector <PT> B) {
	for (int i = 0; i < B.size();i ++)
		A = isect (A, B[i], B[(i+1)%B.size()], B[(i+2) % B.size()]);
	return A;
}

//----------------------------------

// rectangle Union Area O(NLONGN)

#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())

struct rectangle { int xl, yl, xh, yh; };
long long rectangle_area(vector<rectangle> rs) {
  vector<int> ys; // coordinate compression
  for (int i = 0; i < rs.size(); ++i) {
    ys.push_back(rs[i].yl);
    ys.push_back(rs[i].yh);
  }
  sort(all(ys)); ys.erase(unique(all(ys)), ys.end());

  int n = ys.size(); // measure tree
  vector<int> C(8*n), A(8*n);
  function<void (int,int,int,int,int,int)> aux = 
  [&](int a, int b, int c, int l, int r, int k) {
    if ((a = max(a,l)) >= (b = min(b,r))) return;
    if (a == l && b == r) C[k] += c;
    else {
      aux(a, b, c, l, (l+r)/2, 2*k+1);
      aux(a, b, c, (l+r)/2, r, 2*k+2);
    }
    if (C[k]) A[k] = ys[r] - ys[l];
    else      A[k] = A[2*k+1] + A[2*k+2];
  };

  struct event { int x, l, h, c; }; // plane sweep
  vector<event> es;
  for (auto r: rs) {
    int l = distance(ys.begin(), lower_bound(all(ys), r.yl));
    int h = distance(ys.begin(), lower_bound(all(ys), r.yh));
    es.push_back({r.xl, l, h, +1});
    es.push_back({r.xh, l, h, -1});
  }
  sort(all(es), [](event a, event b) { return a.x != b.x ? a.x < b.x : a.c > b.c; });
  long long area = 0, prev = 0;
  for (auto &e: es) {
    area += (e.x - prev) * A[0];
    prev = e.x;
    aux(e.l,e.h,e.c,0,n,0);
  }
  return area;
}


//---------------------------------- 
const long double EPS = 1e-4;

typedef complex < double > pt;
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define angle(v) (atan2((v).Y,(v).X))
#define length(v) ((long double)hypot((v).Y,(v).X))
#define lengthSqr(v) (dot(v,v))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define rotate(v,t) (polar(v,t))
#define rotateabout(v,t,a) (rotate(vec(a,v),t)+(a))
#define reflect(p,m) ((conj((p)/(m)))*(m))
#define normalize(p) ((p)/length(p))
#define same(a,b) (lengthSqr(vec(a,b))<EPS)
#define mid(a,b) (((a)+(b))/point(2,0))
#define perp(a) (point(-(a).Y,(a).X))

bool isSquare(vector<pair < pt, pt > > arr){
	pt p1 = arr[0].f, p2 = arr[1].f, p3 = arr[2].f, p4 = arr[3].f;
	ll d2 = norm ( p1 - p2 ) + EPS;
	ll d3 = norm ( p1 - p3 ) + EPS;
	ll d4 = norm ( p1 - p4 ) + EPS;
	for( int i = 0 ; i < 4 ; i++ )
		for( int j = 0 ; j < 4 ; j++ )
			if( i != j && arr[i].f == arr[j].f )
				return false;
	if( d2 == d3 && 2 * d2 == d4 && 2 * d2 == ( ll ) (norm ( p2 - p3 ) + EPS)){
		ll d = norm ( p2 - p4 ) + EPS;
		return (d == ( ll ) (norm ( p3 - p4 ) + EPS) && d == d2);
	}
	if( d3 == d4 && 2 * d3 == d2 && 2 * d3 == ( ll ) (norm ( p3 - p4 ) + EPS)){
		ll d = norm ( p2 - p3 ) + EPS;
		return (d == ( ll ) (norm ( p2 - p4 ) + EPS) && d == d3);
	}
	if( d2 == d4 && 2 * d2 == d3 && 2 * d2 == ( ll ) (norm ( p2 - p4 ) + EPS)){
		ll d = norm ( p2 - p3 ) + EPS;
		return (d == ( ll ) (norm ( p3 - p4 ) + EPS) && d == d2);
	}
	return false;
}


typedef complex<double> Point;
const int MAX_POINTS = 500; 
Point arr[MAX_POINTS];
double dis[MAX_POINTS][MAX_POINTS];
 
bool com(pair < double, bool > a, pair < double, bool > b)
{
	if(a.f == b.f)
		return a.s;
	return a.f < b.f;
}

int getPointsInside(int i, double r, int n)
{
    vector<pair<double, bool> > angles;
 
    for (int j=0; j<n; j++)
    {
        if (i != j && dis[i][j] <= 2*r)
        {
            double B =  acos(dis[i][j]/(2*r));
            double A = arg(arr[j]-arr[i]);
            double alpha = A-B;
            double beta = A+B;
            angles.push_back(make_pair(alpha, true));
            angles.push_back(make_pair(beta, false));
	    alpha = A - B + 2 * PI;
            beta = A + B + 2 * PI;
	    angles.push_back ( make_pair ( alpha, true ));
	    angles.push_back ( make_pair ( beta, false ));
        }
    }
    sort(angles.begin(), angles.end(), com);
    int count = 1, res = 1;
    vector<pair<double, bool> >::iterator it;
    for (it=angles.begin(); it!=angles.end(); ++it)
    {
        if ((*it).second)
            count++;
        else
            count--;
        if (count > res)
            res = count;
    }
 
    return res;
}
 
// Returns count of maximum points that can lie in a circle of radius r O(N^2LOGN).
int maxPoints(Point arr[], int n, int r)
{
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
            dis[i][j] = dis[j][i] = abs(arr[i]-arr[j]);
 
    int ans = 0;
    for (int i=0; i<n; i++)
        ans = max(ans, getPointsInside(i, r, n));
 
    return ans;
}


// closest pair of pointes O(NLOGN)
typedef complex < double > pt;
#define x real()
#define y imag()
pair < pt, int > arr[N];
bool cmpY( int a, int b ){return arr[a].f.y < arr[b].f.y;}
bool cmpX( pair < pt, int > a, pair < pt, int > b ){return a.f.x < b.f.x;}
int ansi, ansj;
double ansd = inf;
double solve( int l, int r ){
	if( l >= r )
		return inf;
	int mid = (l + r) / 2;
	double d = min ( solve ( l, mid ), solve ( mid + 1, r ));
	vector < int > L, R;
	for( int i = l ; i <= r ; i++ ){
		if( i <= mid ){
			if( arr[mid].f.x + 1 - arr[i].f.x < d )
				L.push_back ( i );
		} else if( arr[i].f.x - arr[mid].f.x <= d )
			R.push_back ( i );
	}
	sort ( R.begin (), R.end (), cmpY );
	sort ( L.begin (), L.end (), cmpY );
	int le = 0, ra = 0;
	for( auto i :L ){
		while( ra + 1 < R.size () && arr[R[ra + 1]].f.y - arr[i].f.y < d )
			ra++;
		while( le < R.size () && arr[i].f.y - arr[R[le]].f.y > d )
			le++;
		for( int j = le ; j <= ra && j < R.size (); j++ ){
			d = min ( d, abs ( arr[i].f - arr[R[j]].f ));
			if( d < ansd ){
				ansd = d;
				ansi = arr[i].s;
				ansj = arr[R[j]].s;
			}
		}
	}
	return d;
}


typedef complex<double> P;
bool operator <(const P& a, const P& b) {
	return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
}


int ccw(P a, P b, P c) {
	b -= a;
	c -= a;
	if (cross(b, c) > 0)
		return +1; // counter clockwise
	if (cross(b, c) < 0)
		return -1; // clockwise
	if (dot(b, c) < 0)
		return +2; // c--a--b on line
	if (norm(b) < norm(c))
		return -2; // a--b--c on line
	return 0;
}

bool pointOnLine(const point& a, const point& b, const point& p){
	return fabs(cross(vec(a,b),vec(a,p))) < EPS;
}
inline bool pointOnRay (point a, point b, point p){
	return dot(vec(a,b),vec(a,p)) > -EPS && pointOnLine(a, b, p);
}

point polyginCentroid(vector<point> &polygon) {
	point res(0, 0);
	long double a = 0;
	for (int i = 0; i < (int) polygon.size(); i++) {
		int j = (i + 1) % polygon.size();
		res.X += (polygon[i].X + polygon[j].X) * (polygon[i].X
		* polygon[j].Y
		- polygon[j].X * polygon[i].Y);
		res.Y += (polygon[i].Y + polygon[j].Y) * (polygon[i].X
		* polygon[j].Y
		- polygon[j].X * polygon[i].Y);
		a += polygon[i].X * polygon[j].Y - polygon[i].Y *
		polygon[j].X;
	}
	a *= 0.5;
	res.X /= 6 * a;
	res.Y /= 6 * a;
	return res;
}

int picksTheorm(vector<point>& p) {
	long double area = 0;
	int bound = 0;
	for (int i = 0; i < sz(p); i++) {
		int j = (i + 1) % sz(p);
		area += cross(p[i],p[j]);
		point v = vec(p[i],p[j]);
		bound += abs(__gcd((int) v.X, (int) v.Y));
	}
	area /= 2;
	area = fabs(area);
	return round(area - bound / 2 + 1);
}

struct cmp {
	point about;
	cmp(point c) {
		about = c;
	}
	bool operator()(const point& p, const point& q) const {
		double cr = cross(vec(about,p),vec(about,q));
		if (fabs(cr) < EPS)
			return make_pair(p.Y, p.X) < make_pair(q.Y, q.X);
		return cr > 0;
	}
};
void sortAntiClockWise(vector<point>& pnts) {
	point mn(1 / 0.0, 1 / 0.0);
	for (int i = 0; i < sz(pnts); i++)
		if (make_pair(pnts[i].Y, pnts[i].X) < make_pair(mn.Y,mn.X))
			mn = pnts[i];
	sort(all(pnts),cmp(mn)) ;
}



//-----------------------------------------------------

// point in 3D traingle
struct PT
{
    ll x, y, z;
    PT() {}
    PT(ll x, ll y, ll z): x(x), y(y), z(z) {}
    bool operator < (const PT &rhs) const{return x < rhs.x || (x == rhs.x && y < rhs.y) || (x == rhs.x && y == rhs.y && z < rhs.z);}
    PT operator + (const PT &rhs) const{return PT(x + rhs.x, y + rhs.y, z + rhs.z);}
    PT operator - (const PT &rhs) const{return PT(x - rhs.x, y - rhs.y, z - rhs.z);}
    ll dot(const PT &rhs) const{return x * rhs.x + y * rhs.y + z * rhs.z;}
    PT det(const PT &rhs) const{return PT(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);}
};

bool inTriangle(PT &P, PT &A, PT &B, PT &C)
{
    ll a = (A - P).det(B - A).z;
    ll b = (B - P).det(C - B).z;
    ll c = (C - P).det(A - C).z;
    return (a <= 0 && b <= 0 && c <= 0) || (a >= 0 && b >= 0 && c >= 0);
}

map<PT,int>id;
vector<PT>points;
vector<int>vec[N];
PT A[N],B[N],C[N],s,e;
int vis[N],parnt[N],dis[N];

int genID(PT p)
{
    if(id[p])return id[p];
    id[p]=points.size();
    points.push_back(p);
    return points.size()-1;
}



