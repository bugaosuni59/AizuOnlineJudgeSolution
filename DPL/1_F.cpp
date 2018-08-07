#include <bits/stdc++.h>
using namespace std;
int v[105];
int w[105];
int dp[10005];// 获得k价格需要花费多少容量 
const int inf=1000000005;
int main(){
	int n,W;cin>>n>>W;
	fill(dp,dp+10002,inf);
	dp[0]=0;
	for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
	for(int i=1;i<=n;i++)
		for(int j=10000;j>=v[i];j--)
			dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
	for(int i=10000;i>=0;i--)
		if(dp[i]<=W){
			cout<<i<<endl;
			return 0;
		}
	return 0;
}
