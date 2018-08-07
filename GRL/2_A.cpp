#include <bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w;
	edge(){;}
	edge(int u,int v,int w):u(u),v(v),w(w){;}
	bool operator<(const edge&p)const{
		return w>p.w;
	}
};
int f[100005];
int find(int x){
	int y=x;
	while(y!=f[y])y=f[y];
	while(x!=f[x]){
		int z=f[x];
		f[x]=y;
		x=z;
	}return x;
}
void join(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)f[fx]=fy;
}
priority_queue<edge> q;
int k=0;
int main(){
//	freopen("a.txt","r",stdin);
	cin.tie(0);
	for(int i=0;i<=100000;i++)f[i]=i;
	int n,m,tu,tv,tw;
	cin>>n>>m;
	while(m--){
		cin>>tu>>tv>>tw;
		q.push(edge(tu,tv,tw));
	}
	int res=0;
	while(k!=n-1){
		edge e=q.top();q.pop();
		if(find(e.u)==find(e.v))continue;
		else{
			k++;
			join(e.u,e.v);
			res+=e.w;
		}
	}
	cout<<res<<endl;
	return 0;
}
