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

int institution[1005];
vector<int> reviewers[1005];

int main() {
  int K, N;
  while( cin >> K >> N && K > 0 && N > 0) {
    for( int n = 0; n < 1004; n++) {
      reviewers[n].clear();
    }
    int i = 1;
    memset( institution, 0, sizeof institution);
    map<string,int> inst_to_nr;
    for( int n = 1; n <= N; n++) {
      string inst;
      cin >> inst;
      if( inst_to_nr.count(inst) == 0) {
        inst_to_nr.insert(make_pair(inst, i++));
      }
      institution[n] = inst_to_nr[inst];

      for( int k = 1; k <= K; k++) {
        int paper;
        cin >> paper;
        reviewers[paper].push_back(n);
      }
    }

    /*
    for( int n = 1; n <= N; n++) {
      cout << institution[n] << " ";
      for( int k = 0; k < (int) reviewers[n].size(); k++) {
        cout << reviewers[n][k] << " ";
      }
      cout << endl;
    }
    */

    int errors = 0;
    for( int n = 1; n <= N; n++) {
      if( reviewers[n].size() != K) {
        //cout << "reviewer " << n << " wordt niet K keer gereivewer/dsfladslf" << endl;
        errors++;
        continue;
      }

      for( int k = 0; k < (int) reviewers[n].size(); k++) {
        for( int j = k+1; j < (int) reviewers[n].size(); j++) {
          if( reviewers[n][k] == reviewers[n][j]) {
            errors++;
            goto final;
          }
        }
        if( institution[n] == institution[reviewers[n][k]]) {
          errors++;
          break;
        }
      }
      final:;
    }

    if( errors > 1) {
      cout << errors << " PROBLEMS FOUND" << endl;
    } else if( errors == 1) {
      cout << "1 PROBLEM FOUND" << endl;
    } else {
      cout << "NO PROBLEMS FOUND" << endl;
    }
  }
  return 0;
}
