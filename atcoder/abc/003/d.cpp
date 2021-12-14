#include<iostream>
using namespace std;
long r,c,x,y,d,l,1e9+7;

main () {
  cin>>r>>c>>x>>y>>d>>l;
  if (x*y!=d+l)return 0;
  long one=1, ans=0;
  string s = "test";
  for(long i=1;i<=d;i++)one=one*(d+l-i+1)
