#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,k;
ll l,r;
ll a[44];
vector<ll> b[41];// 选i个硬币有哪些不同结果 
vector<ll> c[41];
void dfs1(int i,ll v,int cnt){
	if(i==n/2){b[cnt].push_back(v);return;}
	dfs1(i+1,v+a[i],cnt+1);
	dfs1(i+1,v,cnt);
}
void dfs2(int i,ll v,int cnt){
	if(i==n){c[cnt].push_back(v);return;}
	dfs2(i+1,v+a[i],cnt+1);
	dfs2(i+1,v,cnt);
}
void solve(){
	if(n==1){cout<<(k==1&&a[0]>=l&&a[0]<=r)<<"\n";return;}
	dfs1(0,0,0);
	dfs2(n/2,0,0);
	ll res=0;
	for(int i=0;i<=40;i++)sort(b[i].begin(),b[i].end()),sort(c[i].begin(),c[i].end());
	for(int i=0;i<=k;i++){
		int j=k-i;
		for(int t=0;t<b[i].size();t++){
			ll v=b[i][t];
			res+=upper_bound(c[j].begin(),c[j].end(),r-v)-lower_bound(c[j].begin(),c[j].end(),l-v);
		}
	}cout<<res<<"\n";
}
int main(){
	cin>>n>>k>>l>>r;
	for(int i=0;i<n;i++)cin>>a[i];
	solve();
	return 0;
}

