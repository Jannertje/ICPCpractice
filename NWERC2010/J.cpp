#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;
#define MIL 1000005

int broken[MIL];

int main() {
  int T;
  cin >> T;
  while( T--) {
    int L, B, N;
    cin >> L >> B >> N;
    if( L == N) {
      cout << "0" << endl;
      continue;
    }
    int cnt = 0;
    for( int i = 0; i < N; i++) {
      char temp;
      cin >> temp;
      if( temp == '0') {
        cnt++;
      }
      broken[i] = cnt;
    }
    int w_pos = 0, leg_left = 0, turns = 0;
    while( 1) {
      int max_broken = broken[w_pos+B-1];
      int hi = N-L, lo = leg_left;
      int k = (hi+lo)/2;
      cout << "k is hier " << k << endl;
      if( max_broken - broken[hi-1] + hi <= L) {
        cout << "fire" << endl;
        k = hi;
      } else {
        while( hi - lo > 1) {
          cout << "nog een iter " << hi << " " << lo << endl;
          k = (hi + lo)/2;
          if( max_broken - broken[k-1] + k <= L) {
            lo = k;
          } else {
            hi = k;
          }
        }
        k = lo;
      }
      if( k == leg_left) {
        cout << "mb:" << max_broken << " ll:" << leg_left << " tu:" << turns << " wp:" << w_pos << endl;
        cout << "IMPOSSIBLE" << endl;
        goto final;
      }
      leg_left = k;
      turns += L;
      if( leg_left == N-L) {
        cout << turns << endl;
        goto final;
      }
      turns += leg_left - w_pos;
      w_pos = leg_left;
    }
    final:;
  }
  return 0;
}
