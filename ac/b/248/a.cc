#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstring>
#define ll long long
#define rep(idx,b,e) for(int idx=(b);idx<e;idx++)
#define rrep(idx,b,e) for(int idx=b;idx>e;idx--)
#define vt vector
using namespace std;

const int MAX = 1000000007;
const int MAX2 = 998244353;

int main() {
  int b[10]={0,1,2,3,4,5,6,7,8,9};
  int s[9];rep(i,0,9)s[i]=getchar();
  
  sort(s, s+9);
  rep(i,0,9) {
    if(char(s[i])!=char(b[i])){
      cout<<b[i]<<endl;
      return 0;
    }
  }
  
}
