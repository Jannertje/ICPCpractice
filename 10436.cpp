#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>

#define INF 1000000000
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;

map<string,int> stations;
vector<string> invstations(20);
int parents[20];
int S, P, Q;
int cost[20];
int path[20][20];
int query[20][3];

/*
void print() {
    printf("%d %d %d\n", S, P, Q);
    for( int s = 0; s < S; s++) {
      cout << invstations[s] << cost[s] << endl;
    }
    for( int s = 0; s < S; s++) {
      for( int t = 0; t < S; t++) {
        cout << path[s][t] << " ";
      }
      cout << endl;
    }
    for( int q = 0; q < Q; q++) {
      cout << invstations[query[q][0]] << invstations[query[q][1]] << query[q][2] << endl;
    }
}
*/

int main() {
  int N;
  cin >> N;
  int mapno = 1;
  while( N--) {
    cin >> S;
    memset( cost, 0, sizeof cost);
    memset( path, -1, sizeof path);
    memset( query, 0, sizeof query);
    memset( parents, 0, sizeof parents);
    string station;
    for( int s = 0; s < S; s++) {
      cin >> station;
      stations[station] = s;
      invstations[s] = station;
      cin >> cost[s];
    }
    cin >> P;
    for( int p = 0; p < P; p++) {
      string s1, s2;
      int pc;
      cin >> s1 >> s2 >> pc;

      int S1 = stations[s1];
      int S2 = stations[s2];
      if( path[S1][S2] != -1) {
        path[S1][S2] = min(path[S1][S2], 2*pc + cost[S2]);
        path[S2][S1] = min(path[S2][S1], 2*pc + cost[S1]);
      } else {
        path[S1][S2] = 2*pc + cost[S2];
        path[S2][S1] = 2*pc + cost[S1];
      }
    }
    cin >> Q;
    for( int q = 0; q < Q; q++) {
      string s1, s2;
      int qc;
      cin >> s1 >> s2 >> qc;
      query[q][2] = qc;
      query[q][0] = stations[s1];
      query[q][1] = stations[s2];
    }
    
    //dijkstra
    int u;
      cout << "Map #" << mapno++ << endl;
    for( int q = 0; q < Q; q++) {
      int s = query[q][0]; parents[s] = -1;
      //define source
      vi dist(S, INF); dist[s] = 0;
      priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));

      while( !pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first; u = front.second;
        if( d == dist[u]) for( int j = 0; j < S; j++) {
          if( path[u][j] != -1) {
            if( dist[u] + path[u][j] < dist[j]) {
              parents[j] = u;
              dist[j] = dist[u] + path[u][j];
              pq.push( ii(dist[j], j));
            }
          }
        }
      }
      u = query[q][1];
      string output;
      do {
        output = invstations[u] + " " + output;
        u = parents[u];
      } while( u != -1);
      output = output.substr(0, output.size()-1);
      cout << "Query #" << q+1 << endl;
      cout << output << endl;
      printf("Each passenger has to pay : %.2f taka\n", (dist[query[q][1]] + cost[s])*1.1/query[q][2]);
    }
    if( N) cout << endl;
  }
  return 0;
}
