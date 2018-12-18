#include <bits/stdc++.h>
using namespace std;
double dp[505][505];
double s[505][505];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//	freopen("a.txt","r",stdin);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i];	
	for(int i=0;i<=n;i++)cin>>q[i];	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=i;k<=j;k++){
				dp[i][j]=min(dp[i][k-1] + dp[k+1][j] + );
				
				
				
				
			}
		}
	}
	return 0;
}
