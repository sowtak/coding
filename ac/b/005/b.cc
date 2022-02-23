#include<iostream>
#include<algorithm>
using namespace std;
int N,T[114];
main() {
  cin>>N;for(int i=0;i<N;i++)cin>>T[i];
  sort(T, T+N);
  cout<<T[0]<<endl;
}
