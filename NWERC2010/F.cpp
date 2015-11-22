#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

#define INF 10000000

using namespace std;

typedef vector<int> vi;

int armies[101];
int borders[101][101];
int is_border[101];
int ours;

int res[400][400], mf, f, s, t;
vi p;
vector< vi> AdjList(400);

void augment( int v, int minEdge) {
  if( v == s) { f = minEdge; return;}
  else if( p[v] != -1) {augment(p[v], min(minEdge, res[p[v]][v]));
    res[p[v]][v] -= f; res[v][p[v]] += f; }}

int main() {
  int T;
  cin >> T;
  while( T--) {
    ours = 0;
    memset(armies, 0, sizeof armies);
    memset(borders, 0, sizeof borders);
    memset(is_border, 0, sizeof is_border);
    memset(res, 0, sizeof res);
    int n; cin >> n;
    for( int i = 0; i < 400; i++) {
      AdjList[i].clear();
    }
    p.clear();

    for( int i = 0; i < n; i++) {
      cin >> armies[i];
      if( armies[i] > 0) ours++;
    }
    for( int i = 0; i < n; i++) {
      for( int j = 0; j < n; j++) {
        char c;
        cin >> c;
        if( c == 'Y') borders[i][j] = 1;
      }
    }
    for( int i = 0; i < n; i++) {
      for( int j = 0; j < n; j++) {
        if( borders[i][j] == 1 && armies[i] && !armies[j]) {
          is_border[i] = 1;
        }
      }
    }
    for( int i = 0; i < n; i++) {
      for( int j = 0; j < n; j++) {
      }
    }


    int lo = 1, hi = 10000;
    while( hi - lo > 1) {
      int K = (hi + lo)/2;
      //vanaf hier BS
      for( int i = 0; i < n; i++) {
        if( armies[i] > 0) {
          for( int j = 0; j < n; j++) {
            if( armies[j] > 0 && borders[i][j])  {
              AdjList[i].push_back(n+j);
              res[i][n+j] = INF;
              res[n+j][i] = -INF;
            } else if( i == j) {
              AdjList[i].push_back(n+j);
              res[i][n+j] = INF;
              res[n+j][i] = -INF;
            }
          }
        }
      }
      s = 2*n+1;
      t = 2*n+2;
      for( int i = 0;i < n; i++) {
        if( armies[i] > 0) {
          AdjList[s].push_back(i);
          res[s][i] = armies[i];
          res[i][s] = -armies[i];
        }
      }

      //vanaf hier gaan binary search
      int tot = 0;
      for( int i = 0;i < n; i++) {
        if( armies[i] > 0) {
          AdjList[n+i].push_back(t);
          if( is_border[i]) {
            res[n+i][t] = K;
            res[t][n+i] = -K;
            tot += K;
          } else {
            res[n+i][t] = 1;
            res[t][n+i] = -1;
            tot += 1;
          }
        }
      }

      for( int i = 0; i < 2*n+3; i++) {
        for( int j = 0; j < AdjList[i].size(); j++) {
          int v = AdjList[i][j];
        }
      }

      mf = 0;
      while( 1) {
        f = 0;
        vi dist(400, INF); dist[s] = 0; queue<int> q; q.push(s);
        p.assign( 400, -1);

        while( !q.empty()) {
          int u = q.front(); q.pop();
          if( u == t) break;
          for( int j = 0; j < AdjList[u].size(); j++) {
            int v = AdjList[u][j];
            if( res[u][v] > 0 && dist[v] == INF) {
              dist[v] = dist[u] + 1; q.push(v); p[v] = u;
            }
          }
        }
        augment(t, INF);
        if( f == 0) {
          break;
        } else {
          mf += f;
        }
      }
      if( mf == tot) {
        lo = K;
      } else {
        hi = K;
      }
    }
    cout << lo << endl;
  }
  return 0;
}
