#include <bits/stdc++.h>
using namespace std;
int dp[100005];
int a[100005];
const int inf=1000000005;
int main(){
	int n;cin>>n;
	fill(dp,dp+n+2,inf);
	dp[0]=-inf;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int jb=lower_bound(dp,dp+n+2,a[i])-dp;
		dp[jb]=a[i];
	}
	for(int i=0;i<=n+1;i++)if(dp[i]==inf){
		cout<<i-1<<endl;
		break;
	}
	return 0;
}
