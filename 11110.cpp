#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>

using namespace std;
int grid[100][100];
int N;

#define DFS_WHITE -1

void printgrid() {
  for( int i = 0; i < N; i++) {
    for( int j = 0; j < N; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

int floodfill( int i, int j, int c1, int c2) {
  //printf("Calling floodfill with i=%d, j=%d, c1=%d, c2=%d\n", i, j, c1, c2);
  if( i < 0 || i >= N || j < 0 || j >= N) return 0;
  if( grid[i][j] != c1) return 0;

  int dx[] = {0, 1, 0, -1};
  int dy[] = {-1, 0, 1, 0};

  grid[i][j] = c2;
  int ans = 1;

  for( int k = 0; k < 4; k++) {
    //cout << "Going into recursion" << endl;
    ans += floodfill( i+dx[k], j+dy[k], c1, c2);
    //cout << "Getting out of recursion" << endl;
  }

  return ans;
}

int main() {
  while( (cin >> N) && N > 0) {
    vector< pair<int,int> > firstloc(N-1);
    firstloc.clear();

    for( int i = 0; i < N; i++) {
      for( int j = 0; j < N; j++) {
        grid[i][j] = 0;
      }
    }

    for( int i = 1; i < N; i++) {
      for( int j = 0; j < N; j++) {
        int a1, a2;
        cin >> a1 >> a2;
        if( j == 0) { 
          firstloc.push_back( make_pair(a1-1, a2-1));
          //cout << "First time encountering color " << i << " at location " << a1-1 << " " << a2-1 << endl;
        }
        grid[a1-1][a2-1] = i;
      }
    }

    int wrong = 0;
    for( auto it = firstloc.begin(); it != firstloc.end(); it++)  {
      int i = (*it).first, j = (*it).second;
      if( grid[i][j] != DFS_WHITE)  {
        int c = grid[i][j];
        //printf("firstloc position i=%d j=%d c=%d\n", i, j, c);
        int ans = floodfill(i, j, grid[i][j], DFS_WHITE);
        //cout << "Removed " << ans << " of color " << c << endl;
        if( ans != N) wrong = 1;
      }
    }
    cout << (wrong ? "wrong" : "right") << endl;
  }
  return 0;
}
