#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef pair<int, int> ii;

int main() {
  int T;
  cin >> T;
  while( T--) {
    vector<ii> people;
    int p, n;
    int sum_ais = 0;
    cin >> p >> n;
    for( int i = 0; i < n; i++) {
      int ai;
      cin >> ai;
      people.push_back(make_pair( ai, n-i));
      sum_ais += ai;
    }
    if( sum_ais < p) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }

    sort( people.begin(), people.end());

    int paid[101];
    int k = n;
    for( int i = 0; i < n; i++) {
      ii curperson = people[i];
      paid[n-curperson.second] = min(curperson.first, p/k);
      p -= paid[n-curperson.second];
      k -= 1;
    }
    for( int i = 0; i < n; i++) {
      cout << paid[i];
      if( i < n-1) cout << " ";
    }
    cout << endl;
  }
  return 0;
}
