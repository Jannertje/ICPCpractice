#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;


int N; 
int vert[600];
typedef pair<int, int> ii;
typedef vector<int> vi;
vector < pair<int , ii>> EdgeList;

vi pset;

void initSet(int n) { pset.assign(n, 0); //Initalize partitioning, each element own parent
  for (int i = 0; i < n; i++) {
    pset[i] = i;
  }}
int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));} //Find parent of element i
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); } //Check if both parents equal
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); } //Makes parent of parent of i becomes parent of j.

//Amount of rolls to go from u to v
int weight(int u, int v) {
  int result = 0;
  int u_code[4] = {vert[u] / 1000, (vert[u] % 1000) / 100, (vert[u] % 100)/ 10, vert[u] % 10};
  int v_code[4] = {vert[v] / 1000, (vert[v] % 1000) / 100, (vert[v] % 100)/ 10, vert[v] % 10};
  //printf("%d: %d %d %d %d\n", vert[u], u_code[0], u_code[1], u_code[2], u_code[3]);
  for (int i = 0; i < 4; i++) {
    int diff = max(u_code[i], v_code[i])- min(u_code[i], v_code[i]);
    result += min(diff, 10 - diff);
  }
  //printf("%d %d: %d \n ", vert[u], vert[v],  result);
  return result;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    EdgeList.clear();
    cin >> N;
    //N++; //Also have vertex 0000
    //vert[0] = 0;
    for (int i = 0; i < N; i++) {
      scanf("%d", &vert[i]);
    }
    //Add edges + weights between all edges
    for (int i = 0; i < N; i++) {
      for (int j = i+1; j < N; j++) {
        //Caculate amount of rolls needed to go from edge i to j
        EdgeList.push_back(make_pair(weight(i,j), ii(i,j)));
        //cout << i << " " << j << " " << weight(i,j) << endl;
      }
    }
    sort(EdgeList.begin(), EdgeList.end());
    int mst_cost = 0 ; initSet(N);
    for (int i = 0; i < EdgeList.size(); i++) {
      pair<int, ii> edge = EdgeList[i]; //Edge i
      if (!isSameSet(edge.second.first, edge.second.second)) //If not endpoints both blue
      {
        mst_cost += edge.first; //Weight of edge
        unionSet(edge.second.first, edge.second.second); //Add edge to blue forest
        //printf("%d %d - %d\n", edge.second.first, edge.second.second, edge.first);
      }
    }
    vert[N+1] = 0;
    int min = 1000000;
    for (int j = 0; j < N; j++) {
      if (weight(j, N+1) < min) {
        min = weight(j, N+1);
      }
    }
    cout << mst_cost + min << endl;
  }

  return 0;
}
