#include <cstdio>
#include <cstring>
#include <list>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
  string line;
  while(cin >> line) {

    list<char> endline;
    list<char>::iterator it = endline.begin();
    for( int i = 0; i < line.size(); i++) {
      switch( line[i]) {
        case '[':
          it = endline.begin();
          break;
        case ']':
          it = endline.end();
          break;
        default:
            endline.insert(it, line[i]);
            break;
      }
    }

    for( auto it = endline.begin(); it != endline.end(); it = ++it) {
      cout << *it;
    }
    cout << endl;
  };
  return 0;
}
