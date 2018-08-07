#include <bits/stdc++.h>
using namespace std;
const int inf=1000000005;
int v[5005];
int w[5005];
int k[5005];
int dp[10005];
int cnt;
int main(){
	int n,W;cin>>n>>W;
	fill(dp,dp+10002,0);
	dp[0]=0;
	for(int i=1;i<=n;i++)cin>>v[i]>>w[i]>>k[i];
	for(int i=n;i>=1;i--){
		while(k[i]>1){
			int cnt=1;
			while(k[i]>cnt){
				k[i]-=cnt;
				n++;
				v[n]=v[i]*cnt;
				w[n]=w[i]*cnt;
				cnt*=2;
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=W;j>=w[i];j--)
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
	cout<<dp[W]<<endl;
	return 0;
}
