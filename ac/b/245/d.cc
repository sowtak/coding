#include <bits/stdc++.h>
#define ll long long
#define rep(idx,b,e) for(int idx=(b);idx<e;idx++)
#define rrep(idx,b,e) for(int idx=b;idx>e;idx--)
#define vt vector
#define all(a) (a.begin(), a.end())
using namespace std;

const int MAX = 1000000007;
const int MAX2 = 998244353;

int main() {
  int n,m;cin>>n>>m;
  vt<int>a(n);
  vt<int>c(n+m);
  vt<int>b(m);
  rep(i,0,n)cin>>a[i];
  rep(i,0,n+m)cin>>c[i];
  
  b.push_back(c[0]/a[0]);
  rep(i,1,m) {
    
  }
}
