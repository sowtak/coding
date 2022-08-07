#include <bits/stdc++.h>
#define ll long long
#define rep(idx,b,e) for(int idx=(b);idx<e;idx++)
#define rrep(idx,b,e) for(int idx=b;idx>e;idx--)
#define vt vector
using namespace std;

const int MAX = 1000000007;
const int MAX2 = 998244353;

int n;ll x;string s;
int main() {
  cin>>n>>x>>s;
  
  rep(i,0,n){
    switch (s[i]) {
      case 'U':
        x/=2;
        break;
      case 'L':
        x*=2;
        break;
      case 'R':
        x=x*2+1;
        break;
    }
  }
  cout<<x<<endl;
}
