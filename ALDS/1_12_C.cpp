#include <bits/stdc++.h>
using namespace std;
struct node{
	int v,c;
	bool operator<(const node&p)const{
		return c>p.c;
	}
};
int d[100005];
vector<node> e[100005];
bool ok[100005];
int n;
void solve(){
	priority_queue<node> q;
	ok[0]=1;
	for(int i=0;i<e[0].size();i++)q.push(e[0][i]);
	int k=1;
	while(k!=n){
		node v=q.top();q.pop();
		if(ok[v.v])continue;
		d[v.v]=v.c;
		ok[v.v]=1;
		k++;
		for(int j=0;j<e[v.v].size();j++)
			q.push({e[v.v][j].v,e[v.v][j].c+v.c});
	}
	for(int i=0;i<n;i++)
		cout<<i<<' '<<d[i]<<"\n";
}
int main(){
//	freopen("a.txt","r",stdin);
	cin.tie(0);
	int u,v,k,c;
	cin>>n;
	while(cin>>u>>k){
		for(int i=0;i<k;i++){
			cin>>v>>c;
			e[u].push_back({v,c});
		}
	}
	solve();
	return 0;
}
