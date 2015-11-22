#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>


#define INF 2000000000
using namespace std;
#define MAX 1000000
int A[MAX];
int acc[MAX], leastl[MAX], leasth[MAX];
int main() {
  int N;
  while( cin >> N && N > 0) {
    cin >> A[0];
    acc[0] = A[0];
    leastl[0] = acc[0];
    for( int n = 1; n < N; n++) {
      cin >> A[n];
      acc[n] = A[n] + acc[n-1];
      leastl[n] = min(leastl[n-1], acc[n]);
    }
    leasth[N-1] = acc[N-1];
    for(int n = N-2; n >= 0; n--) {
      leasth[n] = min(leasth[n+1], acc[n]);
    }

    int cnt = 0;
    for( int n = 0; n < N; n++) {
      if(n == 0) {
        if(leasth[n] >= 0 && acc[N-1] >= 0)
          cnt++;
      } else if( leasth[n] >= acc[n-1]) {
        if( acc[N-1] - acc[n-1] + leastl[n-1]>=0) {
          cnt++;
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
