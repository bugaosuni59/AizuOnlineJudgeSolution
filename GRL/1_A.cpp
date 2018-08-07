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
const int inf=1<<30;
void solve(int s){
	priority_queue<node> q;
	ok[s]=1;
	fill(d,d+n,inf);
	d[s]=0;
	for(int i=0;i<e[s].size();i++)q.push(e[s][i]);
	int k=1;
	while(k!=n&&!q.empty()){
		node v=q.top();q.pop();
		if(ok[v.v])continue;
		d[v.v]=v.c;
		ok[v.v]=1;
		k++;
		for(int j=0;j<e[v.v].size();j++)
			q.push({e[v.v][j].v,e[v.v][j].c+v.c});
	}
	for(int i=0;i<n;i++)
		if(d[i]>=inf)cout<<"INF\n";
		else cout<<d[i]<<"\n";
}
int main(){
//	freopen("a.txt","r",stdin);
	cin.tie(0);
	int u,v,k,c,m,s;
	cin>>n>>m>>s;
	while(m--){
		cin>>u>>v>>c;
		e[u].push_back({v,c});
	}
	solve(s);
	return 0;
}
