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
  while (T--) {
    int n;
    cin >> n;
    int A[2*n];
    memset(A, 0, sizeof A);
    for( int i = 1; i <= n; i++) {
      cin >> A[i];
    }

    vector<int> B(2*n);
    B.clear();
    int cnt = 0;
    for( int i = 1; i <= n; i++) {
      if( A[i] == 0) {
        B.insert(B.begin(),i);
      } else {
        //find location of i in B
        for( int j = 0; j < B.size(); j++) {
          if( B[j] == A[i]) {
            //hoeveel man moet er naar links of rechts?
            int gaatnaarlinks = j+1;
            int gaatnaarrechts = B.size()-gaatnaarlinks;
            //cout << "We hogen cnt op met min " << gaatnaarlinks << "," << gaatnaarrechts << endl;
            cnt += min(gaatnaarlinks, gaatnaarrechts);
            //even gaan kijken
            //zet i direct rechts van A[i] zetten
            B.insert(B.begin()+j+1, i);
            break;
          }
        }
      }
    }
    cout << cnt << endl;

  }
  return 0;
}
