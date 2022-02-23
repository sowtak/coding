#include<cstdio>
#include<cmath>
using namespace std;
double a,b,c,d,e,f;
main () {
  scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f);
  printf("%.1f", abs((c-a)*(f-b)-(d-b)*(e-a))/2);
}
