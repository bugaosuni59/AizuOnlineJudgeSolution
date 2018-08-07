#include <bits/stdc++.h>
using namespace std;
int n;
bool ok[10005];
int d[10005];
int f[10005];
vector<int> e[10005];
int step=0;
void dfs(int i){
	ok[i]=1;
	step++;
	d[i]=step;
	for(int j=0;j<e[i].size();j++)
		if(!ok[e[i][j]])
			dfs(e[i][j]);
	step++;
	f[i]=step;
}
void solve(){
	for(int i=1;i<=n;i++)if(!ok[i])dfs(i);
	for(int i=1;i<=n;i++)
		cout<<i<<' '<<d[i]<<' '<<f[i]<<"\n";
}
int main(){
//	freopen("a.txt","r",stdin);
	cin>>n;
	int u,k,v;
	for(int i=1;i<=n;i++){
		cin>>u>>k;
		for(int j=0;j<k;j++)cin>>v,e[u].push_back(v);
	}
	solve();
	return 0;
}
