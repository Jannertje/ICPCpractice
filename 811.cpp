#include <cstdio>
#include <cstring>
#include <bitset>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;
int n;
int tree[16][4];

typedef int T;
struct PT {
  T x,y;
  PT() {}
  PT( T x, T y) : x(x), y(y) {}
  bool operator < (const PT &rhs) const { return make_pair(y,x) < make_pair( rhs.y, rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair( rhs.y, rhs.x); }
};

T cross(PT p, PT q) { return p.x*q.y - p.y*q.x; }
T area2( PT a, PT b, PT c) {return cross(a,b) + cross(b,c) + cross(c,a);}

void ConvexHull( vector<PT> &pts) {
  sort( pts.begin(), pts.end());
  pts.erase( unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for( int i = 0; i < pts.size(); i++) {
    while( up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
    while( dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
    up.push_back( pts[i]);
    dn.push_back( pts[i]);
  }
  pts = dn;
  for( int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}

double dist( PT p1, PT p2) {
  return hypot( p1.x - p2.x, p1.y - p2.y);
}

double perim( vector<PT> pts) {
  double result = 0.0;
  for( int i = 0; i < (int) pts.size(); i++) {
    result += dist( pts[i], pts[(i+1)%pts.size()]);
  }
  return fabs(result);
}

int main() {
  int K = 1;
  while( cin >> n && n > 1) {
    if( K > 1) cout << endl;
    for( int i = 0; i < n; i++) {
      cin >> tree[i][0] >> tree[i][1] >> tree[i][2] >> tree[i][3];
    }

    int minval = 100000000;
    int minmask, mincount = 1000000;
    double minexc;
    for( int i = 0; i < (1 << n); i++) {
      bitset<16> dummy(i);
      //printf("\n%s", dummy.to_string().c_str());
      int val = 0, len = 0;
      vector<PT> trees;
      for( int j = 0; j < n; j++) {
        if( i & (1 << j)) {
          trees.push_back(PT(tree[j][0], tree[j][1]));
        } else {
          val += tree[j][2];
          len += tree[j][3];
        }
      }
      ConvexHull( trees);
      if( len - perim(trees) > -0.001) {
        //printf(" val %d len %d perim %f", val, len, len- perim(trees));
        bitset<16> checker(i);
        if(minval > val || (minval == val && checker.count() > mincount)) {
          minval = val;
          minmask = i;
          mincount = checker.count();
          minexc = len - perim(trees);
        }
      }
    }
    cout << "Forest " << K++ << endl << "Cut these trees:";
    for( int i = 0; i < n; i++) {
      if( !(minmask & (1 << i))) {
        cout << " " << i+1;
      }
    }
    printf("\nExtra wood: %.2f\n", minexc);
  }
  return 0;
}
