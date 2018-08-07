#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mi[1000005];
ll q=19260817;
ll base=1313;
ll v=0,a=0;
string s,t;
int main(){
//	freopen("a.txt","r",stdin);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	mi[0]=1;
	for(int i=1;i<=1000000;i++)mi[i]=mi[i-1]*base%q;
	cin>>s>>t;
	if(t.length()>s.length())return 0;
	for(int i=0;i<t.length();i++){
		v=(v*base+t[i])%q;
		a=(a*base+s[i])%q;
	}
	int res=0;
	if(a==v)cout<<0<<endl;
	int l=t.length();
	for(int i=l;i<s.length();i++){
		a=(((a-s[i-t.length()]*mi[l-1])%q+q)%q*base+s[i])%q;
		if(a==v)cout<<i-l+1<<endl;
	}
	return 0;
}
