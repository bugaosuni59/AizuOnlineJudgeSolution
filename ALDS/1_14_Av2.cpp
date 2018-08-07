#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("a.txt","r",stdin);
	string s,t;
	cin>>s>>t;
	int i=0;
	while((i=s.find(t,i))!=-1)cout<<i++<<endl;
	return 0;
}
