#include <bits/stdc++.h>
#define ll long long
#define rep(idx,b,e) for(int idx=(b);idx<e;idx++)
#define rrep(idx,b,e) for(int idx=b;idx>e;idx--)
#define vt vector
using namespace std;

const int MAX = 1000000007;
const int MAX2 = 998244353;

int n; 
int main() {
  cin>>n;
  vt<int>a(n);
  rep(i,0,n)cin>>a[i];
  set<int> s(a.begin(), a.end());
  a.assign(s.begin(), s.end());
  rep(i,0,n) {
    if (i != a[i]) {
      cout<<i<<endl;
      return 0;
    }
  }
}
