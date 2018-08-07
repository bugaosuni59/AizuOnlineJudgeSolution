#include <bits/stdc++.h>
using namespace std;
int n,k;
int c[55];
int dp[55][50005];
const int inf=1000000000;
int main(){
	cin>>n>>k;
	for(int i=1;i<=k;i++)cin>>c[i];
	memset(dp,0x7f,sizeof(dp));
	for(int j=1;j<=n;j++)dp[0][j]=inf;
	for(int i=0;i<=k;i++)dp[i][0]=0;
	for(int i=1;i<=k;i++)
		for(int v=0;v<=n;v++)
			dp[i][v]=min(dp[i-1][v],dp[i][v-c[i]]+1);
	cout<<dp[k][n]<<endl;
	return 0;
}
