#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;
typedef pair<int,int> ii;

int main() {
  int T;
  cin >> T;
  while( T--) {
    priority_queue<ii, vector<ii>, greater<ii> > ask;
    priority_queue<ii, vector<ii>, less<ii> > bid;
    int stockprice = -1;
    int n;
    cin >> n;
    for( int i = 0; i < n; i++) {
      int number, price;
      string d1, d2;
      string s; cin >> s >> number >> d1 >> d2 >> price;
      if( s[0] == 'b') {
        bid.push(make_pair(price, number));
        //cout << "\tPushing (" << price << "," << number << ") onto bid" << endl;
      } else if( s[0] == 's') {
        ask.push(make_pair(price, number));
        //cout << "\tPushing (" << price << "," << number << ") onto ask" << endl;
      } else {
        //cout << "WHATTT" << endl;
        return 1;
      }
      while( !ask.empty() && !bid.empty()) {
        ii asktop = ask.top(); ii bidtop = bid.top();
        //cout << "\tCurrent asktop: (" << asktop.first << "," << asktop.second << "); ";
        //cout << "\tCurrent bidtop: (" << bidtop.first << "," << bidtop.second << ")" << endl;
        if( bidtop.first >= asktop.first) {
          if( bidtop.second < asktop.second) {
            asktop.second -= bidtop.second;
            ask.pop();
            bid.pop();
            ask.push(asktop);
            //cout << "\t\tDecreasing asktop with " << bidtop.second << " shares" << endl;
          } else if( bidtop.second > asktop.second) {
            bidtop.second -= asktop.second;
            ask.pop();
            bid.pop();
            bid.push(bidtop);
            //cout << "\t\tDecreasing bidtop with " << asktop.second << " shares" << endl;
          } else {
            bid.pop(); ask.pop();
            //cout << "\t\tPopping both asktop and bidtop" << endl;
          }
        } else {
          break;
        }
        stockprice = asktop.first;
      }
      if( ask.size() > 0) cout << ask.top().first; else cout << "-"; cout << " ";
      if( bid.size() > 0) cout << bid.top().first; else cout << "-"; cout << " ";
      if( stockprice != -1) cout << stockprice; else cout << "-";
      cout << endl;
    }
  }
  return 0;
}
