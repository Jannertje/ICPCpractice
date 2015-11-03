#import <cstdio>
#import <algorithm>
using namespace std;

int main() {
  int T;
  scanf("%d\n", &T);
  for( int i = 0; i < T; i++) {

    int salaries[3];
    scanf("%d %d %d\n", &salaries[0], &salaries[1], &salaries[2]);
    sort(salaries, salaries+3);
    printf("Case %d: %d\n", T, salaries[1]);
  }
  return 0;
}
