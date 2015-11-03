#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

void printgrid( int grid) {
  for( int i = 0; i < 3; i++) {
    for( int j = 0; j < 3; j++) {
      printf("%d", (0 != (grid & (1<<(3*i+j)))));
    }
    printf("\n");
  }
  printf("\n");
}

int f(int grid) {
  int out = 0;
  for( int i = 0; i < 3; i++) {
    for( int j = 0; j < 3; j++) {
      int cursum = 0;
      //int gridij = (0 != (grid & (1<<(3*i+j))));
      if( i > 0) cursum += (0 != (grid & 1 << (3*(i-1)+j)));
      if( j > 0) cursum += (0 != (grid & 1 << (3*(i)+j-1)));
      if( i < 2) cursum += (0 != (grid & 1 << (3*(i+1)+j)));
      if( j < 2) cursum += (0 != (grid & 1 << (3*(i)+j+1)));
      out |= (cursum % 2) << (3*i+j);
    }
  }
  return out;
}

int main() {
  int N;
  scanf("%d\n\n", &N);
  for( int n = 0; n < N; n++) {
    int grid = 0;
    for( int i = 0; i < 3; i++) {
      for( int j = 0; j < 3; j++) {
        char curchar;
        scanf("%c", &curchar);
        grid |= (curchar == '1' ? 1 : 0) << (3*i+j);
      }
      scanf("\n");
    }
    scanf("\n");

    int allgrids[1<<9] = {0};
    int curgrid = grid;
    for( int i = 0; i < 1<<9; i++) {
      allgrids[curgrid] = 1;
      curgrid = f(curgrid);
      if( allgrids[curgrid]) {
        printf("%d\n", i-1);
        break;
      }
    }
  }
  return 0;
}
