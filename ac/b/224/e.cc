#include<iostream>
#include<algorithm>
#include<map>
#include<utility>
#include<vector>
using namespace std;
const int mry = 364364;
int H,W,N,r,c,n[mry], ans;
main() {
  cin>>H>>W>>N;
  map<int, vector<pair<int, int>>> m;
  for(int i=0;i<N;i++){
    cin>>r>>c>>n[i];
    m.emplace(n[i], make_pair(r,c));
  }

  int mx=*max_element(n, n+(int)sizeof(n));
    
  for(int e: n) {
    for(int i=e;i<=mx;i++) {
      for(pair<int,int> p: m[i]) {
        if(m[e].first==p.first || m[e].second==p.second) {
          ans++;
          break;
        }
      }
    }
    cout<<ans<<endl;
  }
}
