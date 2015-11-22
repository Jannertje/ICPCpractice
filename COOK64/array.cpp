#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

long long A[100100];

long long ggd( long long a, long long b) {
  if( b > a) return ggd(b,a);

  if( b == 0) return a;
  return ggd(b, a%b);
}

int main() {
  long long T;
  cin >> T;
  while( T--) {
    memset(A, 0, sizeof A);
    long long N;
    cin >> N;
    for( long long i = 0; i < N ; i++) {
      cin >> A[i];
    }
    long long ggds = A[0];
    for( long long i = 1; i < N; i++) {
      ggds = ggd(ggds, A[i]);
    }
    cout << ggds * N << endl;
  }
  return 0;
}
