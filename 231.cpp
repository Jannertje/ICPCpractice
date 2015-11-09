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
  int N;
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
        if( seq[j] >= seq[i])               //longest nonincreasing subsequence
          cnt[i] = max( cnt[i], cnt[j]+1);                //recurrence rule #2

    cout << *max_element( cnt.begin(), cnt.end()) << endl;
  }
  return 0;
}
