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
int f[1005];
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
int a[105][105];
priority_queue<edge> q;
int k=0;
int main(){
//	freopen("a.txt","r",stdin);
	for(int i=0;i<=100;i++)f[i]=i;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			if(a[i][j]!=-1)q.push(edge(i,j,a[i][j]));
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
