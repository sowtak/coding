#include<iostream>
#include<cmath>
using namespace std;
int N,X[810],Y[810], ans;
main () {
  cin>>N;
  for(int i=0;i<N;i++)cin>>X[i]>>Y[i];
  
  for(int i=0;i<N;i++)
    for(int j=i+1;j<N;j++)
      for(int k=j+1;k<N;k++)
        if(abs((X[j]-X[i])*(Y[k]-Y[i])-(Y[j]-Y[i])*(X[k]-X[i]))>0)ans++;

  cout<<ans<<endl;}
  
