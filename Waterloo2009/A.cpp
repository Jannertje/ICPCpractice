#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

char board[15][15];

int main() {
  char field;
  while( cin >> field && field != 'E') {
    board[0][0] = field;
    int hashes = (field == '#' ? 1 : 0);

    for( int i = 0; i < 15; i++) {
      for( int j = 0; j < 15; j++) {
        if( i == 0 && j == 0) continue;
        cin >> board[i][j];
        if( board[i][j] == '#') hashes++;
      }
    }

    int hoeveel = 0;
    while( hashes) {
      int bestscore = 0, besti = -1, bestj = -1;
      for( int i = 0; i < 15; i++) {
        for( int j = 0; j < 15; j++) {
          int cnt = 0;
          for( int k = 0; k < 15; k++) {
            if( board[i][k] == '#') cnt++;
            if( board[k][j] == '#') cnt++;
          }
          if( board[i][j] == '#') cnt--;
          if( cnt > bestscore) {
            bestscore = cnt;
            besti = i;
            bestj = j;
          }
        }
      }
      for( int k = 0; k < 15; k++) {
        if( board[besti][k] == '#') {
          board[besti][k] = '.';
        }
        if( board[k][bestj] == '#') {
          board[k][bestj] = '.';
        }
      }
      hashes -= bestscore;
      hoeveel++;
    }
    cout << hoeveel << endl;
  }
  return 0;
}
