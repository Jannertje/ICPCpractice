#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

int papers[1005][7];
int institution[1005];
int number_of_reviews[1005];
int has_error[1005];
int main() {
  int K, N;
  while( cin >> K >> N && K > 0 && N > 0) {
    int i = 0;
    memset( papers, -1, sizeof papers);
    memset( institution, -1, sizeof institution);
    memset( number_of_reviews, 0, sizeof number_of_reviews);
    memset( has_error, 0, sizeof has_error);
    map<string,int> inst_to_nr;
    for( int n = 1; n <= N; n++) {
      string inst;
      cin >> inst;
      if( inst_to_nr.count(inst) == 0) {
        inst_to_nr.insert(make_pair(inst, i++));
      }
      institution[n] = inst_to_nr[inst];
      for( int k = 1; k <= K; k++) {
        cin >> papers[n][k];
        int seen = 0;
        for( int j = 1; j < k; j++) {
          if( papers[n][j] == papers[n][k]) {
            seen = 1;
            break;
          }
        }
        if( seen == 0) {
          number_of_reviews[papers[n][k]]++;
        }
      }
    }

    for( int n = 1; n <= N; n++) {
      if( number_of_reviews[n] != K) {
        has_error[n] = 1;
      }
      for( int k = 1; k <= K; k++) {
        if( institution[n] == institution[papers[n][k]]) has_error[papers[n][k]] = 1;
      }
    }
    int res = 0;
    for( int n = 1; n <= N; n++) {
      res += has_error[n];
    }
    if( res > 1) {
      cout << res << " PROBLEMS FOUND" << endl;
    } else if( res == 1) {
      cout << "1 PROBLEM FOUND" << endl;
    } else {
      cout << "NO PROBLEMS FOUND" << endl;
    }
  }
  return 0;
}
