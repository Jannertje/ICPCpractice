#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;
typedef pair<double, double> dd;

double a, b, v, f;
vector<dd> segments(10000);

int main() {
  int T; cin >> T;
  while( T--) {
    segments.clear();
    cin >> a >> b >> v >> f;
    int r; cin >> r;
    for( int i = 0; i < r; i++) {
      double xi, yi;
      cin >> xi >> yi;
      segments[i] = make_pair( xi, yi);
    }
  }
  //TODO: find out if it's possible at all -- maybe drive verrrry slowly?
  //binary search the answer.
  double lo = 0.0, hi = 24.0;
  while( fabs(lo - hi) > 1E-6) {
    double mid = (hi+lo)/2;
    if( can(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  return 0;
}
