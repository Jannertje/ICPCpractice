#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
char map[1005][1005];
int mapvis[1005][1005];
int mapmech[1005][1005];
int ruined;
int gi, gj, L, W;
int Di[4] = {-1, 0, 1, 0}, Dj[4] = {0, 1, 0, -1};

bool isvalid(int i, int j) {
  return !( i < 0 || j < 0 || i >= L || j >= W);
}

void walkgodzilla() {
  for( int i = 0; i < 4; i++) {
    int di = Di[i];
    int dj = Dj[i];
    if( isvalid(gi + di, gj + dj) && map[gi + di][gj + dj] == 'R') {
      map[gi + di][gj + dj] = 'X';
      mapvis[gi + di][gj + dj] = 1;
      ruined++;
      gi += di;
      gj += dj;
      //printf("godzilla walked and ruined\n");
      return;
    }
  }
  for( int i = 0; i < 4; i++) {
    int di = Di[i];
    int dj = Dj[i];
    if( isvalid(gi + di, gj + dj) && mapvis[gi + di][gj + dj] == 0) {
      mapvis[gi + di][gj + dj] = 1;
      gi += di;
      gj += dj;
      //printf("godzilla walked\n");
      return;
    }
  }
  //printf("godzilla roared\n");
  return;
}

void multiplymechs() {
  for( int i = 0; i < L; i++) {
    for( int j = 0; j < W; j++) {
      if( mapmech[i][j] == 1) {
        for( int k = 0; k < 4; k++) {
          int di = Di[k];
          int dj = Dj[k];
          if( isvalid(i + di, j + dj) && map[i + di][j + dj] != 'R') {
            mapmech[i + di][j + dj] = 2;
          }
        }
      }
    }
  }
  for( int i = 0; i < L; i++) {
    for( int j = 0; j < W; j++) {
      if( mapmech[i][j] == 2) mapmech[i][j] = 1;
    }
  }
}

int finished() {
  for( int i = gi; i < L; i++) {
    if( mapmech[i][gj]) return 1;
    if( map[i][gj] == 'R') break;
  }

  for( int i = gi; i >= 0; i--) {
    if( mapmech[i][gj]) return 1;
    if( map[i][gj] == 'R') break;
  }

  for( int j = gj; j < W ; j++) {
    if( mapmech[gi][j]) return 1;
    if( map[gi][j] == 'R') break;
  }

  for( int j = gj; j >= 0; j--) {
    if( mapmech[gi][j]) return 1;
    if( map[gi][j] == 'R') break;
  }

  return 0;
}

void print() {
  for( int i = 0; i < L; i++) {
    for( int j = 0; j < W; j++) {
      printf("%c", map[i][j]);
    } printf("    ");
    for( int j = 0; j < W; j++) {
      printf("%d", mapvis[i][j]);
    } printf("    ");
    for( int j = 0; j < W; j++) {
      printf("%d", mapmech[i][j]);
    } printf("    ");
  printf("\n");
  }
  printf("\n");
}

int main() {
  int T;
  cin >> T;
  while( T--) {
    ruined = 0;
    cin >> W >> L;
    for( int i = 0; i < L; i++) {
      for( int j = 0; j < W; j++) {
        cin >> map[i][j];
        mapvis[i][j] = 0;
        mapmech[i][j] = 0;
        if( map[i][j] == 'M') {
          map[i][j] = '.';
          mapmech[i][j] = 1;
        } else if( map[i][j] == 'G') {
          gi = i; gj = j; mapvis[i][j] = 1;
          map[i][j] = '.';
        }
      }
    }

    //print();
    while( 1) {
      //godzilla walks
      walkgodzilla();

      //print();
      //mechs multiply in every direction (flood fill)
      multiplymechs();
      //print();

      //check if godzilla is within range of a mech
      if( finished()) {
        cout << ruined << endl;
        break;
      }
    }
  }
  return 0;
}
