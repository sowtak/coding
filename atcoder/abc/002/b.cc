#include<iostream>
using namespace std;
string s; int i;
main () {
  cin>>s;
  for (i=0;i<s.size();i++)if(s[i]!='a'&&s[i]!='i'&&s[i]!='u'&&s[i]!='e'&&s[i]!='o')cout<<s[i];
  cout<<endl;
}
