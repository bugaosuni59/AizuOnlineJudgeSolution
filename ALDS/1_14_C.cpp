#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s[1005],t[1005];
ll pre[1005][1005];
ll pre2[1005][1005];
ll mp[1005];
ll mq[1005];
int n1,m1,n2,m2;
ll p=131,q=233;
ll Q=1e9+7;
void solve(){
	mp[0]=mq[0]=1;
	for(int i=1;i<=1000;i++){
		mp[i]=mp[i-1]*p%Q;
		mq[i]=mq[i-1]*q%Q;
	}
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=m1;j++){
			pre[i][j]=(-pre[i-1][j-1]*p*q+pre[i-1][j]*p+pre[i][j-1]*q+s[i-1][j-1])%Q;
			pre[i][j]=(pre[i][j]+Q)%Q;
		}
	}
	for(int i=1;i<=n2;i++){
		for(int j=1;j<=m2;j++){
			pre2[i][j]=(-pre2[i-1][j-1]*p*q+pre2[i-1][j]*p+pre2[i][j-1]*q+t[i-1][j-1])%Q;
			pre2[i][j]=(pre2[i][j]+Q)%Q;
		}
	}
	ll hs=pre2[n2][m2];
	for(int i=1;i<=n1-n2+1;i++){
		for(int j=1;j<=m1-m2+1;j++){
			ll v=(pre[i+n2-1][j+m2-1]+pre[i-1][j-1]*mp[n2]%Q*mq[m2]%Q-pre[i+n2-1][j-1]*mq[m2]%Q-pre[i-1][j+m2-1]*mp[n2]%Q)%Q;
			v=(v+Q)%Q;
			if(v==hs){
				cout<<i-1<<' '<<j-1<<"\n";
			}
		}
	}	
}
int main(){
//	freopen("a.txt","r",stdin);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n1>>m1;
	for(int i=0;i<n1;i++)cin>>s[i];
	cin>>n2>>m2;
	for(int i=0;i<n2;i++)cin>>t[i];
	solve();	
	return 0;
}
