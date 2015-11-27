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

char orig[50][50];

int main() {
  int T;
  while( T--) {
    memset( orig, 0, sizeof orig);
    int w, h;
    cin >> w >> h;
    int d, f, b;
    cin >> d >> f >> b;
    for( int i = 0; i < h; i++) {
      for( int j = 0; j < w; j++) {
        cin >> orig[i][j];
      }
    }
  }
  return 0;
}
