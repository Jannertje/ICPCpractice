#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <tuple>

using namespace std;

bool sortinput( tuple<int,int,int,char> u1, tuple<int,int,int,char> u2) {
  return get<2>(u2) < get<2>(u1);
}

int main() {
  int T;
  scanf("%d\n\n", &T);
  for( int t = 0; t < T; t++) {
    vector<tuple<int,int,int, char> > input; //team number, number of problems solved, penalty time
    int penalties[100][9] = {0};
    int completed[100][9] = {0};
    int submission[100] = {0};
    for( int i = 0; i < T; i++) {
      while(1) {
        string line;
        getline(cin, line);
        if( line.size() == 0) break;

        int contestant, problem, time;
        char L;
        sscanf(line.c_str(), "%d %d %d %c\n", &contestant, &problem, &time, &L);
        input.push_back(make_tuple(contestant, problem, time, L));
      }
    }

    for( int i = 0; i < input.size(); i++) {
      int contestant = get<0>(input[i]), problem = get<1>(input[i]), time = get<2>(input[i]);
      char L = get<3>(input[i]);
      submission[contestant] = 1;
      switch( L) {
        case 'I':
          if( !completed[contestant][problem]) {
            penalties[contestant][problem] += 20;
          }
          break;
        case 'C':
          penalties[contestant][problem] += time;
          completed[contestant][problem] = 1;
          break;
        default:
          break;
      }
    }
    int totalsubs = 0;
    for( int i = 0; i < 100; i++) {
      if( submission[i] == 1) totalsubs += 1;
    }

    vector<tuple<int, int, int> > rankings(totalsubs);
    int j = 0;
    for( int i = 0; i < 100; i++) {
      if( submission[i] == 1) {
        int complete = 0;
        int penalty = 0;
        for( int j = 0; j < 9; j++) {
          if( completed[i][j]) {
            complete += 1;
            penalty += penalties[i][j];
          }
        }
        rankings[j++] = make_tuple(i, complete, penalty);
      }
    }
    sort( rankings.begin(), rankings.end(), [](tuple<int, int, int> a, tuple<int,int,int> b) -> bool {
      if( get<1>(a) > get<1>(b)) return 1;
      if( get<1>(a) < get<1>(b)) return 0;
      if( get<2>(a) > get<2>(b)) return 1;
      if( get<2>(a) < get<2>(b)) return 0;
      return (get<0>(a) > get<2>(b));
    });

    for( int i = 0; i < rankings.size(); i++) {
      printf("%d %d %d\n", get<0>(rankings[i]), get<1>(rankings[i]), get<2>(rankings[i]));
    }
    if( t < T-1) printf("\n");
  }
  return 0;
}
