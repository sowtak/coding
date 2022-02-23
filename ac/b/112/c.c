N;
x[100],y[100],h[100];
hid;
main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d%d%d",x+i,y+i,h+i);
    if(h[i])hid=i;
  }
  for(int X=0;X<=100;X++)for(int Y=0;Y<=100;Y++){
    int H=h[hid]+abs(X-x[hid])+abs(Y-y[hid]);
    int ng=0;
    for(int i=0;i<N;i++){
      int nh=H-abs(X-x[i])-abs(Y-y[i]);
      if(nh<0)nh=0;
      if(h[i]!=nh)ng=1;
    }
    if(!ng){
      printf("%d %d %d\n",X,Y,H);
      return 0;
    }
  }
}
