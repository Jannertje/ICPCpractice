#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

long long memo[51][51][51];

long long num_bc( int n, int k, int m) {
  if( k < 1)                return 0; //no bars in BC
  if( n <= 0)               return 0; //no units wide
  if( k > n)                return 0; //more bars than units available
  if( k == 1 && m < n)      return 0; //only one bar, but not wide enough

  if( k == n)               return memo[n][k][m] = 1; //exactly as many bars as units available
  if( k == 1 && m >= n)     return memo[n][k][m] = 1; //only one bar; it is wide enough
  if( memo[n][k][m] != -1)  return memo[n][k][m];     //DP smart stuff

  long long ans = 0;
  for( int j = 1; j <= m; j++) {
    ans += num_bc( n-j, k-1, m);
  }
  return memo[n][k][m] = ans;
}

int main() {
  int N, K, M;
  memset( memo, -1, sizeof memo);
  while( scanf("%d %d %d\n", &N, &K, &M) > 0) {
    cout << num_bc(N, K, M) << endl;
  }
  return 0;
}
