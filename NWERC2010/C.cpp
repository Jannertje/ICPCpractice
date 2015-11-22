#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
  int T;
  while( T--) {
    char s[1001];
    scanf("%s", s);
    int res = 0;
    for( int i = 0; i < strlen(s); i++) {
      int toA = s[i] - 'A';
      int toZ = 1 + ('Z' - s[i]);
      int tot = min(toA, toZ);
      res += tot;
    }
    cout << res;
  }
  return 0;
}
