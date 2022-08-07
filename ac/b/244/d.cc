#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  vector<char>s,t;
  for(int i=0;i<3;i++) {
    char c;cin>>c;s.push_back(c);
  }
  for(int i=0;i<3;i++) {
    char c;cin>>c;t.push_back(c);
  }
  
  int cnt=0;
  vector<char>u1 = s;
  vector<char>u2 = s;
  vector<char>u3 = s;
  swap (u1[0], u1[1]);
  cnt++;
  if (u1==t && cnt==1) {
    cout<<"No"<<endl;
    return 0;
  }
  cnt=0;
  swap(u2[1], u2[2]);
  cnt++;
  if (u2==t && cnt==1) {
    cout<<"No"<<endl;
    return 0;
  }
  cnt=0;
  swap(u3[2], u3[0]);
  cnt++;
  if (u3==t && cnt==1) {
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
  
}
/*
 `123 2
  132 1
  213 1
  231 2
  312 2
  321 1
 */
