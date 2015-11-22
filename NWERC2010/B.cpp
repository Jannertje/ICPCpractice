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
      //cout << "Jan " << jan[i].first << " " << - jan[i].second.first << " " << endl;
    }
    for (int i = 0; i < n; i++) {
      //cout << "Petra " << petra[i].first << " " << - petra[i].second.first << " " << endl;
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

      int gepak_jan = 0;
      int mag = 1;
      jans[i] = 1;
      for (int j = 0; j < n; j++) {
        //Convert petra idx, to jan idx
        int ori_idx = petra[j].second.second;
        int jan_idx  = invjan[ori_idx];
        //cout << "jan_idx is " << jan_idx << " en petra_j is " << j << " en ori j is " << ori_idx << endl;
        if (jans[jan_idx]) {
          gepak_jan++;
        }
        if (s[0] == 'P' ) {
          if (2*gepak_jan > j+1) { //HELP
            mag = 0;
            break;
          }
        } else {
          if (2*gepak_jan > j+2) {//DAFUQ
            mag = 0;
            break;
          }
        }
      }
      if (!mag)  {
        jans[i] = 0;
        //cout << "ik pak " << i << " niet en gepak is " << gepak_jan << endl;
      } else {
        //cout << "ik pak " << i << " en gepak is " << gepak_jan << endl;
      }
    }
    for( int i = 0; i < n; i++) {
      //cout << jans[i];
    }
    //cout << endl;
    int val_jan = 0;
    int val_pet = 0;
    for (int i = 0; i < n; i++) {
      if (jans[i]) {
        val_jan += jan[i].first;
      } else {
        val_pet += -jan[i].second.first;
      }
    }
    cout << val_pet << " " << val_jan << endl;
  }
  return 0;
}
