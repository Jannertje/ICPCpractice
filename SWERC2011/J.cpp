#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

bool boolprimes[10000001];
vector<int> primes;

unsigned long long func2( int prime, int cnt) {
  unsigned long long res = 1;
  for( int j = 0; j < cnt; j++) res = (res*prime) % 1000000007;
  return res;
}
unsigned long long func(int prime, int cnt) {
  if( cnt == 0) return 1;
  unsigned long long k = func(prime, cnt/2);
  k = (k * k) % 1000000007;
  if( cnt % 2) return (prime * k) % 1000000007;
  return (k) % 1000000007;
}

int main() {
  for( int i = 0; 2*i < 10000001; i++) {
    boolprimes[i] = true;
  }
  for( int i = 2; 2*i*i < 10000001; i++) {
    if( boolprimes[i]) {
      for( int j = 2; 2*j*i < 10000001; j++) {
        boolprimes[j*i] = false;
      }
    }
  }
  for( int i = 2; 2*i < 10000001; i++) {
    if( boolprimes[i] == true) primes.push_back(i);
  }
  //cout << primes.size() << endl;
  int n;
  while( cin >> n && n > 0) {
    vector<int> primecounts;
    primecounts.clear();
    for( int i = 0; i < (int) primes.size(); i++) {
      int k = n;
      int cnt = 0;
      while( primes[i] <= k) {
        cnt+= k/primes[i];
        k /= primes[i];
      }
      primecounts.push_back(cnt);
    }
    for( int i = 0; i < (int) primecounts.size(); i++) {
      if( primecounts[i] % 2) primecounts[i]--;
    }
    unsigned long long res = 1;
    for( int i = 0; i < (int) primes.size(); i++) {
      unsigned long long acc = func(primes[i], primecounts[i]);
      res = (res * acc) % 1000000007;
    }
    /*
     *
     *
    for( int i = 0; i < (int) primes.size(); i++) {
      for( int j = 0; j < primecounts[i]; j++) 
        res = (res*primes[i]) % 1000000007;
    }
    */
    cout << res << endl;
  }
  return 0;
}
