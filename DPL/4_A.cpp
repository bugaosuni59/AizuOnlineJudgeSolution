#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll v;
ll a[5][1005];
ll b[1005*1005];
ll c[1005*1005];
int main(){
	cin>>n>>v;
	for(int i=0;i<4;i++)for(int j=0;j<n;j++)cin>>a[i][j];
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)b[i*n+j]=a[0][i]+a[1][j],c[i*n+j]=a[2][i]+a[3][j];
	sort(b,b+n*n);sort(c,c+n*n);
	ll ans=0;
	for(int i=0;i<n*n;i++){
		pair<ll*,ll*>res=equal_range(c,c+n*n,v-b[i]);
		ans+=res.second-res.first;
	}
	cout<<ans<<"\n";
	return 0;
}

