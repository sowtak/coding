#include<iostream>
using namespace std;
string s,t;
bool ok=true;
main () {
  cin>>s>>t;int n=s.size();
  for(int i=0;i<n;i++) {
    if(s[i]==t[i])continue;
    int sok=0,tok=0;
    // どれかに当てはまればフラグが正になる
    for(int j=0;j<7;j++) {
      sok+=s[i]=="atcoder"[j];
      tok+=t[i]=="atcoder"[j];
    }
    if (s[i]=='@'&&tok||t[i]=='@'&&sok)continue;
    ok=false;
  }
  cout<<(ok?"You can win":"You will lose")<<endl;}
