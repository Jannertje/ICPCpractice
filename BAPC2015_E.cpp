#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;
int board[5004][5004]; 
int X2, Y2;
int N;

int min_moves(int X1, int Y1) {
  return  max(X2 - X1 ,Y2 - Y1);
}

int poss(int x, int y, int moves) {
  if (x > N || x < 1 || y < 1 || y > N) 
    return 0;
  
  if (min_moves(x,y) != moves) //No valid point, sorry!
    return 0;
    
  if (x == X2 - 1) 
    return 1;
    
  
  //if (moves == 1)
    //return 1;

  

  if (board[x][y] != -1 )
    return board[x][y];

  //int x_off[] = {-1, 0, 1, -1, 1, -1 , 0, 1};
  //int y_off[] = {1, 1, 1, 0, 0, -1 , -1, -1};
  int x_off[]  = {1, 1, 1};
  int y_off[] =  {-1, 0, 1};
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    ans += poss(x + x_off[i], y + y_off[i], moves - 1);
    ans %= 5318008;
  }
  return board[x][y] = ans;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) 
  {
    cin >> N;
    int X1, Y1;
    cin >> X1 >> Y1 >> X2 >> Y2;
    if (X1 > X2) {
      X1 = (N+1) - X1;
      X2 = (N+1) - X2;
    }
    if (Y1 > Y2) {
      Y1 = (N+1) - Y1;
      Y2 = (N+1) - Y2;
    }
    if (Y2 - Y1  > X2 - X1) {
      swap(X1,Y1);
      swap(X2,Y2);
    }
    //cout << X1 << " " << Y1 << " " << X2 << " " << Y2 << endl;
    memset(board, -1, sizeof(board));
    cout << poss(X1, Y1, min_moves(X1,Y1)) << endl;
  }

  return 0;
}
