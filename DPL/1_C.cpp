#include <bits/stdc++.h>
using namespace std;
struct point{
	int v,w;
}a[105];
int dp[105][10005];
int main(){
	int n,w;cin>>n>>w;
	for(int i=1;i<=n;i++)cin>>a[i].v>>a[i].w;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=w;j++)
			dp[i][j]=(j<a[i].w?dp[i-1][j]:max(dp[i-1][j],dp[i][j-a[i].w]+a[i].v));
	cout<<dp[n][w]<<endl;
	return 0;
}
