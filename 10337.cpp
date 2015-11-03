#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

#define LL long long
#define constant value
using namespace std;
#define MAX_FUEL 1000000

int wind[1003][11];
int fuel_data[1003][11];
int X;
int fuel(int x, int h) {
  if (x < 0 || x > X || h < 0 || h > 9)
    return MAX_FUEL;

  if (x == 0) {
    if (h > 0) 
      return MAX_FUEL;
    return fuel_data[x][h] = 0;
  }

  if (fuel_data[x][h] != -1) 
    return fuel_data[x][h];

  int ans = MAX_FUEL;
  if (h >= 1) ans = min(ans, fuel(x-1, h-1) + 60 - wind[x-1][h-1]);
              ans = min(ans, fuel(x-1, h) +   30 - wind[x-1][h]);
  if (h <= 8) ans = min(ans, fuel(x-1, h+1) + 20 - wind[x-1][h+1]);
  fuel_data[x][h] = ans;
  return ans;
}

int main(){
  int N;
  cin >> N;
  for (int i =0 ; i < N; i++) {
    cin >> X;
    X /= 100;
    memset(fuel_data, -1, sizeof(fuel_data));
    for (int h = 9; h >= 0; h--)
      for (int j = 0; j < X; j++) {
        scanf("%d", &wind[j][h]);
      }
    cout << fuel(X, 0) << endl << endl;
  }
  return 0;
}


