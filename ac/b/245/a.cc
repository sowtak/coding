#include <bits/stdc++.h>
#define ll long long
#define rep(idx,b,e) for(int idx=(b);idx<e;idx++)
#define rrep(idx,b,e) for(int idx=b;idx>e;idx--)
#define vt vector
using namespace std;

const int MAX = 1000000007;
const int MAX2 = 998244353;


int main() {
  int a,b,c,d;cin>>a>>b>>c>>d;
  if (a<c) {
    cout<<"Takahashi"<<endl;
    return 0;
  } else if (a>c) {
    cout<<"Aoki"<<endl;
    return 0;
  } else {
    if (b<d) {
      cout<<"Takahashi"<<endl;return 0;
    } else if (b>d){
      cout<<"Aoki"<<endl;
      return 0;
    } else {
      cout<<"Takahashi"<<endl;return 0;
    }
  }
}
