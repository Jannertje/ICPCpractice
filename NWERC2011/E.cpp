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

char str[2500005];
int main() {
  int T;
  cin >> T;
  while( T--) {
    int n;
    cin >> n;
    scanf("%s", str);
    int cntr = 1;
    bool seen[256] = {false};
    int pos[256] { -1};
    int order[256] = {0};
    int occur[256] = {0};
    memset(seen, 0, sizeof(seen));
    memset(pos, -1, sizeof(pos));
    memset(order, 0, sizeof(order));
    memset(occur, 0, sizeof(occur));

    for(int i = n-1; i >= 0; i--) {
      if (!seen[str[i]]) {
        pos[str[i]] = i;
        seen[str[i]] = true;
        order[str[i]] = cntr++;
      }
      occur[str[i]]++;
    }
    int total = 0;
    int len_queue = 0;
    while(--cntr) {
      int find_pos = 0;
      for (int j = 0; j < 256; j++) {
        if (order[j] == cntr) {
          find_pos = j;
          break;
        }
      }
      len_queue += occur[find_pos];
      total += 5 * ( (pos[find_pos] + 1- len_queue) * occur[find_pos]);
    }
    cout << total << endl;
  }
  return 0;
}
