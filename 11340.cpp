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
  long long N;
  cin >> N;
  for( long long i = 0; i < N; i++) {
    double cents = 0;
    long long costs[100] = {0};
    char letters[100];
    long long K;
    scanf("%lld\n", &K);
    for( long long k = 0; k < K; k++) {
      scanf("%c %lld\n", &letters[k], &costs[k]);
    }
    long long M;
    scanf("%lld\n", &M);
    for( long long m = 0; m < M; m++) {
      string line;
      getline(cin, line);
      for( long long l = 0; l < line.size(); l++) {
        for( long long k = 0; k < K; k++) {
          if( letters[k] == line[l]) cents += costs[k];
        }
      }
    }
    printf("%.2lf$\n", cents/100);
  }
  return 0;
}
