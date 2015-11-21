#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>


#define INF 2000000
using namespace std;

int main() {
  int N;
  while( cin >> N && N > 0) {
    int A[N];
    int acc[N+1], leastl[N+1], leasth[N+1];
    acc[0] = 0; leastl[0] = INF;
    for( int n = 0; n < N; n++) {
      cin >> A[n];
      acc[n+1] = A[n] + acc[n];
      leastl[n+1] = min(leastl[n], acc[n]);
    }
    leasth[N] = INF;
    for( int n = N-1; n >= 0; n--) {
      leasth[n] = min(leasth[n+1], acc[n]);
    }

    int cnt = 0;
    for( int n = 0; n < N; n++) {
      if( acc[n+1] >= leasth[n]) {
        if( acc[N] - acc[n] >= leastl[n]) {
          cnt++;
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
