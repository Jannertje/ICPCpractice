#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>


#define INF 1000000000

using namespace std;

int res[50][50];

int mf, f, s, t;
vector<int> p;

void augment( int v, int minEdge) {
  if( v == s) { f = minEdge; return;}
  else if( p[v] != -1) {
    augment(p[v], min(minEdge, res[p[v]][v]));
    res[p[v]][v] -= f; res[v][p[v]] += f; }
}

int main() {
  int n, m;
  while( (cin >> n >> m) && n > 0 && m > 0) {
    vector< vector< int > > AdjList(n);
    for( int i = 0; i < 50; i++) for( int j = 0; j < 50; j++) res[i][j] = 0;
    s = 0;
    t = 1;

    int a, b, w;
    for( int i = 0; i < m; i++) {
      cin >> a >> b >> w;
      AdjList[a-1].push_back(b-1);
      AdjList[b-1].push_back(a-1);

      res[a-1][b-1] = w;
      res[b-1][a-1] = w;
    }

    for( int i = 0; i < AdjList.size(); i++) {
      for( int j = 0; j < AdjList[i].size(); j++) {
        //printf("%d %d\n", i, AdjList[i][j]);
      }
    }

    //data ingeladen
    mf = 0;
    while( 1 ) {
      f = 0;
      //run BFS
      vector<int> dist(50, INF); dist[s] = 0; queue<int> q; q.push(s);
      p.assign(50, -1);

      while( !q.empty()) {
        int u = q.front(); q.pop();
        if( u == t) break;
        for( int j = 0; j < AdjList[u].size(); j++) {
          int v = AdjList[u][j];
          if( res[u][v] > 0 && dist[v] == INF) {
            dist[v] = dist[u] + 1, q.push(v), p[v] = u;
          }
        }
      }
      augment(t, INF);
      if( f == 0) break;
      mf += f;
    }
    queue<int> q; q.push(s);
    vector< int> visited(50, 0);
    while( !q.empty()) {
      int u = q.front(); q.pop();
      visited[u] = 1;
      for( int j = 0; j < AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if( res[u][v] > 0 && visited[v] == 0) {
          q.push(v);
        }
      }
    }

    for( int i = 0; i < AdjList.size(); i++) {
      for( int j = 0; j < AdjList[i].size(); j++) {
        if( visited[i] && !visited[AdjList[i][j]] ) printf("%d %d\n", i+1, AdjList[i][j]+1);
      }
    }
    printf("\n");
  }
  return 0;
}
