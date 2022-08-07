#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n;
  int a[n];
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];

  int max_cnt_continuous;
  if (n%2==0) {
    max_cnt_continuous=n/2;
  } else max_cnt_continuous=n/2+1;

  int cnt_continuous=0;
  int cnt=0;
  int pre=0;
  for(int i=0;i<n;i++) {
    if (a[i]==1) {
      cnt++;
      if (pre == 1) {
        continue;
      }else {
        pre=1;
        cnt_continuous++;
      }
    }
    else pre=0;
  }
}
