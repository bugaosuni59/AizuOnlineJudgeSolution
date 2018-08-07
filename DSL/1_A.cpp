#include <bits/stdc++.h>
using namespace std;
int f[1000005];
int find(int x){
	int root=x;
	while(root!=f[root])root=f[root];
	while(x!=root){
		int tem=f[x];
		f[x]=root;
		x=tem;
	}
	return x;
}
void join(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)f[fx]=fy;
}
int main(){
	int n,q,t,l,r;
	cin>>n>>q;
	for(int i=0;i<=n;i++)f[i]=i;
	while(q--){
		cin>>t>>l>>r;
		if(t)cout<<(find(l)==find(r))<<"\n";
		else join(l,r);
	}
	return 0;
}
