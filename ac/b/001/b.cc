#include<iostream>
#include<iomanip>
using namespace std;
double m;
main()
{
	cin>>m;
	m/=1000.0;
	if(m<0.1)cout<<"00"<<endl;
	else if(m<=5.0)cout<<setfill('0')<<setw(2)<<(int)(10.0*m)<<endl;
	else if(m<=30.0)cout<<(int)(m+50.0)<<endl;
	else if(m<=70.0)cout<<(int)((m-30.0)/5.0+80.0)<<endl;
	else cout<<"89"<<endl;
}

