#include<iostream> 
using namespace std;
int H,W,A[50][50];
main() {
  cin>>H>>W;
  for(int i=0;i<H;i++)for(int j=0;j<W;j++)cin>>A[i][j];
  bool ok=true;
  for(int i=0, i_2=i+1;i<H;i_2++) {
    for(int j=0,j_2=j+1;j<W;j_2++) {
      if(A[i][j]+A[i_2][j_2] <= A[i_2][j]+A[i][j_2]) continue;
      ok=false;
      if(j_2==W-1) j++;
    }
    if(i_2==H-1) i++;
  }
  cout<<(ok?"Yes":"No")<<endl;
}
    
  
