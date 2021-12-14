#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int n,k;
double r[810], ans;
main () {
  cin>>n>>k;for(int i=0;i<n;i++)cin>>r[i];
  sort(r,r+n, greater<double>());
  for(int i=k-1;i>=0;i--)ans=(ans+r[i])/2;
  cout<<fixed<<setprecision(9)<< ans<<endl;
}
