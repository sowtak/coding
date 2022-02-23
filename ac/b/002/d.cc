#include<iostream>
#include<vector>
using namespace std;
int n,m,e[114][514];
main () {
  cin>>n>>m;
  for(int i=0;i<m;i++) {
    int x,y;cin>>x>>y;
    e[x][y]=e[y][x]=1;
  }
  int ans=0;
  for(int i=1;i<1<<n;i++) {
    vector<int>a;
    for(int j=0;j<n;j++) {
      if(i&(1<<j))a.push_back(j+1);
    }
    bool ok=true;
    //　1組でも知り合いでないペアがあれば、false
    for(int j=0;j<a.size();j++) {
      for(int k=j+1;k<a.size();k++) {
        ok&=e[a[j]][a[k]];
      }
    }
    if(ok)ans=max(ans, (int)a.size());
  }
  cout << ans  <<endl;
}

