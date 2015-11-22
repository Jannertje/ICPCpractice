#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main() {
  int T;
  cin >> T;
  while( T--) {
    int n;
    cin >> n;
    vector<iii> petra(n), jan(n);
    string s;
    cin >> s;
    for( int i = 0; i < n; i++) {
      int ptemp, jtemp;
      cin >> ptemp >> jtemp;
      petra[i] = make_pair( ptemp, make_pair( -jtemp, i));
      jan[i] = make_pair( jtemp, make_pair( -ptemp, i));
    }

    sort(petra.begin(), petra.end());
    sort(jan.begin(), jan.end());
    reverse(petra.begin(), petra.end());
    reverse(jan.begin(), jan.end());
    for (int i = 0; i < n; i++) {
      cout << "Jan " << jan[i].first << " " << - jan[i].second.first << " " << endl;
    }
    for (int i = 0; i < n; i++) {
      cout << "Petra " << petra[i].first << " " << - petra[i].second.first << " " << endl;
    }
    int invpetra[n], invjan[n];
    for( int i = 0; i < n; i++) {
      invpetra[petra[i].second.second] = i;
      invjan[jan[i].second.second] = i;
    }
    bool jans[n];
    for( int i = 0; i < n; i++) {
      jans[i] = false;
    }
    for( int i = 0; i < n; i++) {
      iii jan_nu = jan[i];
      int idx_item = jan_nu.second.second;
      int idx_bij_petra = invpetra[idx_item];

      int gepak_jan = 0;
      for (int j = 0;  j <= idx_bij_petra; j++) {
        //Convert petra idx, to jan idx
        int ori_idx = petra[j].second.second;
        int jan_idx  = invjan[ori_idx];
        if (jans[jan_idx])
          gepak_jan++;
      }
      int mag = 0;
      if (s[0] == 'P' ) {
        if (2*gepak_jan+1 <= idx_bij_petra) { //HELP
          mag = 1;
        }
      } else {
        if (2*gepak_jan <= idx_bij_petra+1) //DAFUQ
          mag = 1;
      }
      if (mag) 
        jans[i] = 1;
    }
    int val_jan = 0;
    int val_pet = 0;
    for (int i = 0; i < n; i++) 
    {
      if (jans[i]) {
        val_jan += jan[i].first;
      } else
        val_pet += -jan[i].second.first;
    }
    cout << val_pet << "  " << val_jan << endl;
  }
  return 0;
}
