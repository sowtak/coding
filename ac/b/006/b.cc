#include<iostream>
using namespace std;
int n;
main() {
  cin>>n;
  int a=0,b=0,c=1,d;
  for(int i=4;i<=n;i++) {
    d=(a+b+c)%10007;
    a=b,b=c,c=d;
  }
  if(n>=4)cout<<d<<endl;
  else if(n==3)cout<<1<<endl;
  else cout<<0<<endl;
}

