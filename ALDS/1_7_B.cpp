#include <bits/stdc++.h>
using namespace std;
vector<int> m[100005];
int deg[100005];// 出度 
int pa[100005];
int t[100005];
int d[100005];// 深度
int h[100005];// 高度 
int sib[100005];
int dfs(int i,int dep){
	d[i]=dep;
	for(int j=0;j<m[i].size();j++)h[i]=max(dfs(m[i][j],dep+1),h[i]);
	return h[i]+1;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	memset(pa,-1,sizeof(pa));
	memset(sib,-1,sizeof(sib));
	for(int tu,tv;cin>>tu;){
		cin>>tv;
		if(tv!=-1){
			m[tu].push_back(tv);
			pa[tv]=tu;deg[tu]++;
			m[tv].size()>0?(t[tv]=1):(t[tv]=2);
			pa[tu]!=-1?(t[tu]=1):0;
		}
		int tv2=tv;
		cin>>tv;tv==-1?0:(m[tu].push_back(tv),0);
		if(tv!=-1){
			m[tu].push_back(tv);
			pa[tv]=tu;deg[tu]++;
			m[tv].size()>0?(t[tv]=1):(t[tv]=2);
			pa[tu]!=-1?(t[tu]=1):0;
		}
		tv2==-1?0:(sib[tv2]=tv);
		tv==-1?0:(sib[tv]=tv2);
	}
	for(int i=0;i<n;i++)if(t[i]==0)dfs(i,0);
	for(int i=0;i<n;i++){
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",
		i,pa[i],sib[i],deg[i],d[i],h[i],t[i]==0?"root":(t[i]==1?"internal node":"leaf"));
	}
	return 0;
}
