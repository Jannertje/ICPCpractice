#import <cstdio>
using namespace std;

int main() {

  int letters[27] = {
                1, 2, 3,    1, 2, 3,    
    1, 2, 3, 1, 2, 3,    1, 2, 3,    
    1, 2, 3, 4, 1, 2, 3,   1, 2, 3, 4, 
    1};
  int T;
  scanf("%d\n", &T);

  for( int t = 0; t < T; t++) {
    char line[100];
    int count = 0;
    gets( line);

    for( int i = 0; i < 100; i++) {
      if( line[i] == '\0') break;
      if( line[i] == ' ') count += 1;
      else {
        printf("%c %d\n", line[i], line[i]-'a');
        count += letters[line[i] - 'a'];
      }
    }

    printf("Case #%d: %d\n", t, count);
  }

  return 0;
}
