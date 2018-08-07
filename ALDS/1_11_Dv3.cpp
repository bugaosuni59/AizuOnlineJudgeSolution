#include <bits/stdc++.h>
using namespace std;
int n;
int f[100005];
int find(int x){
	int y=x;
	while(y!=f[y])y=f[y];
	while(x!=f[x]){
		int z=f[x];
		f[x]=y;
		x=z;
	}
	return f[x];
}
void join(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)f[fx]=fy;
}
int main(){
//	freopen("a.txt","r",stdin);
	int T,q,u,v;cin>>n>>T;
	for(int i=0;i<=n;i++)f[i]=i;
	while(T--){
		cin>>u>>v;
		join(u,v);
	}cin>>q;
	while(q--){
		cin>>u>>v;
		if(find(u)==find(v))puts("yes");
		else puts("no");
	}
	return 0;
}
