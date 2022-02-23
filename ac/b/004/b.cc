#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
string sa[4];
main () {
  for(int i=0;i<4;i++) {
    getline(cin, sa[i]);
    reverse(sa[i].begin(), sa[i].end());
  }
  for(int i=4;i--;)cout<<sa[i]<<endl;
}
