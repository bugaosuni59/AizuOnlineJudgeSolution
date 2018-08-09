#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int dp[1005][1005];
int main(){
	cin>>s1>>s2;
	for(int i=1;i<=s1.length();i++)dp[i][0]=i;
	for(int i=1;i<=s2.length();i++)dp[0][i]=i;
	for(int i=0;i<s1.length();i++){
		for(int j=0;j<s2.length();j++){
			dp[i+1][j+1]=dp[i][j]+(s1[i]!=s2[j]);
			dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j+1]+1);
			dp[i+1][j+1]=min(dp[i+1][j+1],dp[i+1][j]+1);
		}
	}
	cout<<dp[s1.length()][s2.length()]<<"\n";
	return 0;
}
