#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

char grid[500][500];

int main() {
  int T;
  while( T--) {
    int n, m;
    cin >> n >> m;
    for( int i = 0; i < n; i++) {
      for( int j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }
  }
  return 0;
}
