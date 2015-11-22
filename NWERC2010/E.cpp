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
  cin >> T;
  while( T--) {
    int lastyear_teams[501], lastyear_positions[501], ranking_teams[501];
    int lowerrank[501][501];
    memset(lowerrank, 0, sizeof lowerrank);
    memset(lastyear_teams, 0, sizeof lastyear_teams);
    memset(lastyear_positions, 0, sizeof lastyear_positions);
    int n; cin >> n;
    for( int i = 1; i <= n; i++) {
      cin >> lastyear_teams[i];
      lastyear_positions[lastyear_teams[i]] = i;
      ranking_teams[i] = lastyear_teams[i];
    }

    for( int i = 1; i <= n; i++) {
      for( int j = 1; j <= n; j++) {
        if( lastyear_positions[i] < lastyear_positions[j]) {
          lowerrank[i][j] = 1;
        } else {
          lowerrank[i][j] = 0;
        }
      }
    }


    int m; cin >> m;
    for( int j = 0; j < m; j++) {
      int ai, bi;
      cin >> ai >> bi;
      if( lowerrank[ai][bi] || lowerrank[bi][ai]) {
        lowerrank[ai][bi] = !lowerrank[ai][bi];
        lowerrank[bi][ai] = !lowerrank[bi][ai];
      }
    }

    for( int i = 1; i <= n; i++) {
      for( int j = 1; j < n; j++) {
        //bubble
        if( lowerrank[ranking_teams[j+1]][ranking_teams[j]]) {
          int temp = ranking_teams[j+1];
          ranking_teams[j+1] = ranking_teams[j];
          ranking_teams[j] = temp;
        }
      }
    }

    //check possible output
    for( int i = 1; i <= n; i++) {
      for( int j = i+1; j <= n; j++) {
        if( !lowerrank[ranking_teams[i]][ranking_teams[j]]) {
          cout << "IMPOSSIBLE" << endl;
          goto final;
        }
      }
    }

    for( int i = 1; i <= n; i++) {
      cout << ranking_teams[i];
      if( i < n) cout << " ";
    }
    cout << endl;
    final:;
  }
  return 0;
}
