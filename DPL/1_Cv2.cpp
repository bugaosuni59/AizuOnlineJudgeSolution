#include <bits/stdc++.h>
using namespace std;
struct point{
	int v,w;
}a[105];
int dp[10005];
int main(){
	int n,w;cin>>n>>w;
	for(int i=1;i<=n;i++)cin>>a[i].v>>a[i].w;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=w;j++)
			dp[j]=(j<a[i].w?dp[j]:max(dp[j],dp[j-a[i].w]+a[i].v));
	cout<<dp[w]<<endl;
	return 0;
}
