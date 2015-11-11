#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;
typedef long double ld;

int T;
int cf[10010];

ld f( ld irr) {
  ld npv = cf[0];
  ld irrpow = 1;
  for( int i = 1; i < T+1; i++) {
    irrpow *= 1.+irr;
    npv += cf[i]/irrpow;
  }
  return npv;
}

int main() {
  while( cin >> T && T > 0) {
    for( int i = 0; i < T+1; i++) {
      cin >> cf[i];
    }

    ld hi = 1;
    while( f(hi) >= 0.0) {
      hi *= 2;
    }
    ld lo = -1;

    ld mid = -1;
    while( fabs(hi - lo) > .0001) {
      mid = (lo + hi) / 2.;
      if( f(mid) > 0) {
        lo = mid;
      } else {
        hi = mid;
      }
    }

    printf("%.2Lf\n", mid);

  }
  return 0;
}
