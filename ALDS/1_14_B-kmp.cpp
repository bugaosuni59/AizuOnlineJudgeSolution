#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s,t;
int Next[1000005];
void init(){
	Next[0]=-1;
	for(int i=1;i<t.length();i++){
		int j=Next[i-1];
		while(j>=0&&t[j+1]!=t[i])j=Next[j];
		if(t[j+1]==t[i])Next[i]=j+1;
		else Next[i]=-1;
	}
}
void solve(){
	init();
	int i,j,cnt;i=j=cnt=0;
	while(i<s.length()){
		if(s[i]==t[j])i++,j++;
		else if(j==0)i++;
		else j=Next[j-1]+1;
//		if(j==t.length())cnt++,j=0;
		if(j==t.length())j=Next[j-1]+1,cout<<i-t.length()<<endl;
	}
	if(j==t.length())cout<<i-t.length()<<endl;
//	if(j==t.length())cnt++,j=0;
//	cout<<cnt<<endl;
}
int main(){
//	freopen("a.txt","r",stdin);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>s>>t;
	solve();
	return 0;
}
