#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
  string line;
  while( cin >> line) {
    if( line[0] == '#') break;
    int intline[line.size()];
    for( int i = 0; i < line.size(); i++) {
      intline[i] = line[i] - 'a';
    }

    if( next_permutation(intline, intline + line.size())) {
      for( int i = 0; i < line.size(); i++) {
        printf("%c", intline[i]+'a');
      }
      printf("\n");
    } else {
      printf("No Successor\n");
    }
  }
  return 0;
}
