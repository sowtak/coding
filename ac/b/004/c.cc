#include<iostream>
#include<algorithm>
using namespace std;
int N;
main () {
  cin>>N;N%=30;
  string s="123456";
  for(int i=0;i<N;i++) {
    swap(s[i%5], s[i%5+1]);
  }
  for(int i=0;i<6;i++)cout<<s[i];
  cout<<endl;
}
      
