#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n;
 
  cin>>n;
  int N=2*n+1;
  vector<bool>v(N, true);
  bool my_turn = false;
  for (int i= 0;i<N;i++) {
    if (my_turn) {
      int x;
      cin>>x;
      v[x-1]=false;
      my_turn=false;
    }else{
      for (int j = 0;j<N;j++) {
        if (v[j]) {
          v[j]=false;
          cout<<j+1<<endl<<flush;
          my_turn=true;
          break;
        }
      }
    }
  }

}
