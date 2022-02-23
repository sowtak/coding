#include<iostream>
using namespace std;
int M,p[19], e[364][364],x,y;
main() {
  cin>>M;
  for(int i=0;i<M;i++){
    cin>>x>>y;x--,y--;
    e[x][y]=e[y][x]=1;
  }
  for(int i=0;i<8;i++)cin>>p[i];
  if (is_sorted(p.begin(), p.end()) cout<<0<<endl;;
  
       
      
}

