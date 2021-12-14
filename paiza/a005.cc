#include<iostream>
using namespace std;
int a,b,n,p[201];
main() {
  cin>>a>>b>>n;
  for(int i=0;i<n;i++){
    char c;cin>>c;
    if(c=='G')p[i]=0;
    else if(c>='1' && c<='9')p[i]=c-'0';
    else p[i]=10;
  }

  bool flag=false, lastFrameFirstStrike=false; 
  int frame=0;
  int ans=0, remaining=0;

  for(int i=0;i<n;i++) {
    if(frame==a-1) {
      if(!flag) {
        remaining=b;
        if(p[i]==b) {
          lastFrameFirstStrike=true;
          ans+=p[i];
          flag=true;
        } else {
          remaining-=p[i];
          flag=true;
          ans+=p[i];
        }
      }
      // 2投目以降
      else {
        if(lastFrameFirstStrike && p[i]==b) {
          ans+=(2*p[i]+ 3*p[i+1]);
        } else if (lastFrameFirstStrike && p[i]!=b) {
          ans+=(2*p[i] + 2*p[i+1]);
          } else if(!lastFrameFirstStrike) {
          if(remaining-p[i]==0) {
            ans+=(p[i]+2*p[i+1]);
          } else {
            ans+=p[i];
          }
        }
    }
    // 最終フレームより前
    }
    else {
      if(!flag) {
        remaining=b;
        if(p[i]==b) {
