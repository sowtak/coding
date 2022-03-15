#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  double a,b,c,x;cin>>a>>b>>c>>x;
  if (x>=1 && x<=a) {
    cout<<1<<endl;
  } else if (x>=a+1 && x<=b) {
    cout<<c/(double)(a-b)<<endl;
  } else cout<<0<<endl;
}
