#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

/* Supershort LIS
    vector<int> seq;                                                //fill this
    vector<int> cnt(seq.size(), 1);                //initialize memo table at 1
    for( int i = 0; i < seq.size(); i++) //DP recur rule: LIS(i) = 1+max(LIS(j))
      for( int j = 0; j < i; j++)                         // for j < i, Xj < Xi
        if( seq[j] < seq[i] && cnt[i] < cnt[j]+1 )    //longest inc subsequence
          cnt[i] = cnt[j] + 1;
    int max = *max_element( cnt.begin(), cnt.end());    //final opt: max LIS(j)
 */

using namespace std;

int main() {
  int N;
  int i = 1;
  while( (cin >> N) && N > -1) {
    vector<int> seq;
    seq.push_back(N);
    int M;
    while( (cin >> M) && M > -1) {
      seq.push_back(M);
    }

    vector<int> cnt(seq.size(), 1);                //initialize memo table at 1
    for( int i = 0; i < seq.size(); i++)    
      for( int j = 0; j < i; j++)
        if( seq[j] >= seq[i] && cnt[i] < cnt[j]+1 ) //longest nonincreasing subsequence
          cnt[i] = cnt[j] + 1;

    if( i != 1) cout << endl;
    cout << "Test #" << i++ << ":" << endl << "  maximum possible interceptions: " << *max_element( cnt.begin(), cnt.end()) << endl;
  }
  return 0;
}
