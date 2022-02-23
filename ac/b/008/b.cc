#include<iostream>
#include<map>
using namespace std;
int N;
main() {
  map<string, int>m;  
  cin>>N;
  int i=N;
  for(;i--;) {
    string s;cin>>s;
    m[s]++;
  }
  int max=0;
  string ans;
  for(auto mm:m) {
    if(mm.second>max) {
      max=mm.second;
      ans=mm.first;
    }
  }
  cout<<ans<<endl;
}

