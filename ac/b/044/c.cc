#include <bits/stdc++.h>
#define ll long long
#define rep(idx,b,e) for(int idx=(b);idx<e;idx++)
#define rrep(idx,b,e) for(int idx=b;idx>e;idx--)
#define vt vector
using namespace std;

const int MAX = 1000000007;
const int MAX2 = 998244353;

int n,a,x[51];
ll dp[51][51][2501];

int main() {
  cin>>n>>a;
  rep(i,0,n)cin>>x[i];
  
  dp[0][0][0]=1;
  rep(i,0,n)rep(j,0,n)rep(k,0,2500){
    dp[i+1][j+1][k+x[i]]+=dp[i][j][k];
    dp[i+1][j][k]+=dp[i][j][k];
  }
  ll ans = 0;
  rep(i,1,n+1)ans+=dp[n][i][a*i];
  cout<<ans<<endl;;
}

