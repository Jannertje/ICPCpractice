#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

int N, W, L, wag[10010];
int curwag;

int findnextwagon( int loc) {
  for (; curwag < W; curwag++) 
    if (wag[curwag] >= loc)
      return wag[curwag];
  return -1;
}

int main() {
  int T;
  cin >> T;
  while( T--) {
    cin >> N >> W >> L;
    for( int i = 0; i < W; i++) {
      cin >> wag[i];
    }

    int lo = 0;
    int hi = N/L + 1;
    while( abs(hi - lo) > 1) {
      curwag = 0;
      int mid = (lo + hi)/2;
      //printf("\n\n We gaan het nu proberen met mid=%d\n", mid);

      //see if it can
      int can = 0;
      int curloc = 1;
      for( int i = 0; i < L; i++) {
        int nextwagon = findnextwagon( curloc);
        //printf("Nextwagon is nu %d en curwag is %d\n", nextwagon, curwag);
        if( nextwagon == -1) {
          can = 1;
          break;
        }
        if( nextwagon > curloc + mid) {
          curloc = nextwagon;
        } else {
          curloc += mid;
        }
        if( curloc > N) can = 1;
      }
      if( can) {
        //printf("Het kan, high is nu %d\n", mid);
        hi = mid;
      } else {
        //printf("Het kan niet, low is nu %d\n", mid);
        lo = mid;
      }
    }
    cout << hi << endl;
  }
  return 0;
}
