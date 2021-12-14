#include<iostream>
#include<string>
using namespace std;
int a,b,n,p[201];
main() {
  cin>>a>>b>>n;
  for(int i=0;i<n;i++){
    string c;cin>>c;
    if(c=="G"){
      p[i]=0;
    } else p[i]=stoi(c);
    //cout<<p[i]<<' ';
  }

  bool flag=false, lastFrameFirstStrike=false,lastFrameSecondStrike=false; 
  int frame=1;
  int ans=0, remaining=0;

  for(int i=0;i<n;i++) {
    //最終フレーム
    if(frame==a) {
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
        if(lastFrameFirstStrike) {
          if(p[i]==b) {
          ans+=2*p[i];
          lastFrameSecondStrike=true;
          } else {
            ans+=2*p[i];
            remaining-=p[i];
          }
        } else if (lastFrameFirstStrike && lastFrameSecondStrike) {
            ans+=3*p[i];
          } else if(lastFrameFirstStrike && !lastFrameSecondStrike) {
          if((remaining-p[i])==0) {
            ans+=2*p[i];
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
          ans+=(p[i]+p[i+1]+p[i+2]);
          frame++;
        } else {
            flag=true;
            remaining-=p[i];
            ans+=p[i];
          }
      } else {
          if((remaining-p[i])==0) {
            ans+=(p[i]+p[i+1]);
            flag=false;
            frame++;
          } else {
              ans+=p[i];
              flag=false;
              frame++;
          }
      }
    }
    cout<< ans << endl;
  }
  cout<<endl;
  cout<<ans<<endl;
}
