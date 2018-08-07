#include <bits/stdc++.h>
using namespace std;
long long dp[1005][1005];
long long a[1005];
long long b[1005];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//	freopen("a.txt","r",stdin);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	memset(dp,0xc,sizeof(dp));
	for(int i=1;i<=n;i++)dp[i][i]=0;
	for(int l=1;l<n;l++){
		for(int i=1;i<=n;i++){
			int j=i+l;
			if(j>n)continue;
			for(int k=i;k<j;k++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*b[j]);
		}
	}		
	cout<<dp[1][n]<<endl;
	return 0;
}
