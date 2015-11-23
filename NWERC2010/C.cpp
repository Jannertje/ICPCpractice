#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

#define BLA 10000
int toRight[BLA];
int consARight[BLA];

int toLeft[BLA];
int consALeft[BLA];
char s[BLA];
int main() {
  int T;
  cin >> T;
  while( T--) {
    scanf("%s\n", s);
    int res = 0;
    int ALeft = 0;
    int ARight = 0;
    for( int i = 0; i < strlen(s); i++) {
      consALeft[i] = 0;
      //Starting from the initial position, how many calculations needed?
      if (i ==  0) //Already at initial pos
        toRight[i] = 0;
      else
        toRight[i] = toRight[i - 1] + 1; //We need one extra move to go to this side

      toRight[i] += min(s[i] - 'A', 1+ ('Z'- s[i]));  //Amount of rotations needed

      if (s[i] == 'A') {
        if (ALeft) //Had A on the left
          consALeft[i] = consALeft[i-1] + 1;
        else
          consALeft[i] = 1;
        ALeft = 1;
      } else
        ALeft = 0;
    }
    //cout << s << endl;
    for( int i = strlen(s) - 1; i >= 0; i--) {
      consARight[i] = 0;
      if (i == strlen(s) - 1) //Already at the end position
        toLeft[i] = 0;
      else
        toLeft[i] = 1 + toLeft[i+1];
      toLeft[i] += min(s[i] - 'A', 1+ ('Z'- s[i])); 
      //cout << "Rolls from end to " << i << " " << s[i] <<  " is " << toLeft[i] << endl;
      if (s[i] == 'A') {
        if (ARight) //Had A on the right
          consARight[i] = consARight[i+1] + 1;
        else
          consARight[i] = 1;
        ARight = 1;
      } else
        ARight = 0;
    }
    int min_val = 0; //Minimal amount of moves needed so far
    //Going directly to the right
    if (strlen(s) == 1)
      min_val = toRight[0];
    else
      min_val = 99999999;

    /*
    cout << s << endl;
    for (int i = 0; i < strlen(s); i++) {
      cout << consARight[i] << " " << consALeft[i] << endl;
    }
    */
    //Calculate the amount needed if first go i steps to right and then to left
    for (int i = 0; i < strlen(s) - 1; i++) { 
      int val;
      val = toRight[i]; //Calculate value needed to get to position i
      val += i + 1; //Calculate amount of steps needed to get to the end
      val += toLeft[i+1]; //Plus the amount of steps needed to get from the end to
      val -= consARight[i+1]; //Correct for block or something..
      min_val = min(val, min_val);
      //cout << "First going to " << i << " then to left " << val << endl;
    }
    //Calculate the amount needed if first go i steps to left and then to right
    for (int i = strlen(s) - 1; i > 0; i--) {
      int val = 1; //Value needed to go to end
      val += toLeft[i]; //Value needed to go from end to position i
      val += (strlen(s)  -1) - i; //Amount of steps to get back to end
      val += 1; //Amount needed to get back to begin
      val += toRight[i-1]; //Amount needed to get from begin to i-1
      val -= consALeft[i-1]; //Correct for the amount of consecutive A's
      min_val = min(val, min_val);
      //cout << "First going left " << i << " then to right " << val << endl;
    }

    cout << min_val << endl;
  }
  return 0;
}
