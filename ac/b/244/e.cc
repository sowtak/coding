#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n,m,k,s,t,x;
  cin>>n>>m>>k>>s>>t>>x;
  vector<vector<int>>G(n,vector<int>(n,0));
  for (int i=0;i<m;i++) {
    int u,v;
    cin>>u>>v;u--,v--;
    G[u][v]=1;
    G[v][u]=1;
  }
  cout<<G[0][1]<<endl;
}
