#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n; string t;
  cin>>n>>t;
  int x=0,y=0;
  //const char dir[4] = {'N', 'E', 'W', 'S'};
  char current_dir = 'E';
  for (int i=0;i<n;i++) {
    if (t[i]=='R') {
      switch (current_dir) {
        case 'N':
          current_dir = 'E';
          break;
        case 'E':
          current_dir = 'S';
          break;
        case 'S':
          current_dir = 'W';
          break;
        case 'W':
          current_dir = 'N';
          break;
      }
    } else {
      switch (current_dir) {
        case 'N':
          y++;
          break;
        case 'E':
          x++;
          break;
        case 'S':
          y--;
          break;
        case 'W':
          x--;
          break;
      }
    }
  }
  cout<<x<<' '<<y<<endl;
}
