#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef vector<int> vi;
int res[MAX_V][MAX_V], mf, f, s, t;
int tcost;

vi p;
vector<int> Adj_list(MAX_V);

void augment(int v, int minEdge) {
  if( v== s) { 
    f = minEdge; 
    return; 
  } else if (p[v] != -1) { 
    augment(p[v], min(minEdge, res[p[v]][v]));
    res[p[v]][v] -= f; 
    res[v][p[v]] += f;
    tcost 
  }
}

int main() {

  mf = 0;
  tcost = 0;
  

  while(1) {
    f = 0;
    vi dist(V, INF); dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0,s));

    p.assign(MAX_V, -1);
    while (!pq.empty()) {
      ii front = pq.top(); pq.pop();
      int d = front.first, u = front.second;
      if (d == dist[u]) 
        for (int j = 0; j < AdjList[u].size(); j++) {
          ii v = AdjList[u][j];
          //NOTE u to v may not exist anymore!!
          if (res[u][v.first] <= 0)
            continue;
          //if (flow[u][v.first] >= cap[u][v.first]) //EDGE DOES NOT EXIST
            //continue;
          if (dist[u] + v.second < dist[v.first]) {
            dist[v.first] = dist[u] + v.second;
            pq.push( ii(dist[v.first], v.first));
            p[v.first] = u;
          }
        }
    }

    augment(t, INF);
    if (f == 0)
      break; //FUCKARONY

    mf += f;
  }
  return 0;
}
