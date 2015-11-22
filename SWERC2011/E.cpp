#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

#define EPS 1E-10

struct point{ double x, y;
  point( double _x, double _y) { x = _x, y = _y; }
};

struct line { double a, b, c;} ;

double dist( point p1, point p2) {
  return hypot( p1.x - p2.x, p1.y - p2.y);
}

bool areSame( point p1, point p2) {
  return fabs(p1.x - p2.x) < EPS && fabs(p1.y - p2.y) < EPS;
}
void pointsToLine( point p1, point p2, line *l) {
  if( p1.x == p2.x) {
    l->a = 1.0; l->b = 0.0; l->c = -p1.x;
  } else {
    l->a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    l->b = 1.0;
    l->c = -(double)(l->a * p1.x) - (l->b * p1.y);
  }
}

bool areParallel( line l1, line l2) {
  return (fabs( l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

bool areSame( line l1, line l2) {
  return areParallel( l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

point rotate(point p, double theta) { //theta is in radians
  return point(p.x * cos(theta) - p.y * sin(theta), p.x * sin(theta) + p.y*cos(theta));
}

bool areIntersect( line l1, line l2, point *p) {
  if( areSame(l1, l2)) return false;
  if( areParallel( l1, l2)) return false;
  p->x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  if( fabs(l1.b) > EPS) p->y = -(l1.a * p->x + l1.c)/l1.b;
  else p->y = -(l2.a * p->x + l2.c) / l2.b;
  return true;
}

using namespace std;
pair<long double,long double> polypoints[1010][1010];
int main() {
  for( int n = 3; n < 1005; n++) {
    //het eerste punt ligt op (1,0)
    for( int k = 0; k < n; k++) {
      polypoints[n][k] = make_pair( cos( ((2.0*k)/n)*M_PI), sin( ((2.0*k)/n)*M_PI));
    }
  }
  double xi[3], yi[3];
  while( scanf("%lf %lf", &xi[0], &yi[0]) > 0) {
    scanf("%lf %lf", &xi[1], &yi[1]);
    scanf("%lf %lf", &xi[2], &yi[2]);
    //create points
    point p1(xi[0], yi[0]), p2(xi[1], yi[1]), p3(xi[2], yi[2]);

    //find midpoints of (p1, p2) and (p1, p3)
    point midpoint01((xi[0] + xi[1])/2, (yi[0] + yi[1])/2), 
    midpoint02((xi[0] + xi[2])/2, (yi[0] + yi[2])/2);
    //cout << midpoint01.x << " " << midpoint01.y << endl;
    //cout << midpoint02.x << " " << midpoint02.y << endl;

    //find lines perp to vectors through (p1, p2) and (p1, p3) through their midpoints
    line l01perp = {.a = p1.x - p2.x, .b = p1.y - p2.y, .c = 0};
    line l02perp = {.a = p1.x - p3.x, .b = p1.y - p3.y, .c = 0};
    if( p1.y == p2.y) {
      l01perp.a = 1.0; l01perp.b = 0.0; l01perp.c = -p1.y;
    } else {
      l01perp.a = l01perp.a/l01perp.b; l01perp.b = 1;
    }
    if( p1.y == p3.y) {
      l02perp.a = 1.0; l02perp.b = 0.0; l02perp.c = -p1.y;
    } else {
      l02perp.a = l02perp.a/l02perp.b; l02perp.b = 1;
    }
    l01perp.c = -(midpoint01.x*l01perp.a + midpoint01.y*l01perp.b);
    l02perp.c = -(midpoint02.x*l02perp.a + midpoint02.y*l02perp.b);

    //cout << "l01perp: " << l01perp.a << " " << l01perp.b << " " << l01perp.c << endl;
    //cout << "l02perp: " << l02perp.a << " " << l02perp.b << " " << l02perp.c << endl;

    //find intersection point
    point intersect(0, 0);
    areIntersect( l01perp, l02perp, &intersect);
    //cout << "intersect at " << intersect.x << " " << intersect.y << endl;

    //move center of circle to origin
    p1.x -= intersect.x; p2.x -= intersect.x; p3.x -= intersect.x;
    p1.y -= intersect.y; p2.y -= intersect.y; p3.y -= intersect.y;

    //scale
    point origin(0, 0);
    double length = dist(origin, p1); //hope this all has almost the same length
    p1.x /= length; p2.x /= length; p3.x /= length;
    p1.y /= length; p2.y /= length; p3.y /= length;

    //rotate all so p1 is at (1, 0)
    rotate( p1, acos(p1.x));
    rotate( p2, acos(p1.x));
    rotate( p3, acos(p1.x));

    for( int n = 3; n < 1001; n++) {
      int matches = 1;
      for( int k = 0; k < n; k++) {
        double diffx = fabs(polypoints[n][k].first - p2.x);
        double diffy = fabs(polypoints[n][k].second - p2.y);
        if( diffx + diffy < 1E-4) {
          matches += 1;
        }
        diffx = fabs(polypoints[n][k].first - p3.x);
        diffy = fabs(polypoints[n][k].second - p3.y);
        if( diffx + diffy < 1E-4) {
          matches += 1;
        }
      }
      if( matches == 3) {
        cout << n << endl;
        break;
      }
    }
  }
  return 0;
}
