#include <bits/stdc++.h>
using namespace std;
int l[100005];
int r[100005];
int ind[100005];
void dfs1(int i){
	printf(" %d",i);
	if(l[i]!=-1)dfs1(l[i]);
	if(r[i]!=-1)dfs1(r[i]);
}
void dfs2(int i){
	if(l[i]!=-1)dfs2(l[i]);
	printf(" %d",i);
	if(r[i]!=-1)dfs2(r[i]);
}
void dfs3(int i){
	if(l[i]!=-1)dfs3(l[i]);
	if(r[i]!=-1)dfs3(r[i]);
	printf(" %d",i);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int tu;cin>>tu;){
		cin>>l[tu]>>r[tu];
		ind[l[tu]]++;ind[r[tu]]++;
	}
	int rt;
	for(int i=0;i<n;i++)if(ind[i]==0)rt=i;
	printf("Preorder\n");
	dfs1(rt);printf("\n");
	printf("Inorder\n");
	dfs2(rt);printf("\n");
	printf("Postorder\n");
	dfs3(rt);printf("\n");
	return 0;
}
