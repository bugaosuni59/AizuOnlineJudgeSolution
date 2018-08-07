#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("a.txt","r",stdin);
	string s,t;
	cin>>s>>t;
	for(int i=0;i<=(int)(s.length()-t.length());i++)
		if(t==s.substr(i,t.length()))
			cout<<i<<endl;
	return 0;
}
