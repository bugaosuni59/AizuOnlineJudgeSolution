#include <bits/stdc++.h>
using namespace std;
string s1,s2;
// ¹«¹²
int dp[1005][1005];
void solve(){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<s1.length();i++)
		for(int j=1;j<=s2.length();j++)
			dp[i][j]=(s1[i]==s2[j]?dp[i-1][j-1]+1:max(dp[i-1][j],dp[i][j-1]));
	cout<<dp[s1.length()-1][s2.length()-1]<<endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//	freopen("a.txt","r",stdin);
	int T;cin>>T;
	while(T--){
		cin>>s1>>s2;
		s1=" "+s1;
		s2=" "+s2;
		solve();		
	}
	return 0;
}
