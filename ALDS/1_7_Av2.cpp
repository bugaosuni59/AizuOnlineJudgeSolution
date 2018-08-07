#include <bits/stdc++.h>
using namespace std;
vector<int> m[100005];
int pa[100005];
int d[100005];
int t[100005];// 0 rt 1 nd 2 lf
void dfs(int i,int dep){
	d[i]=dep;
	t[i]=(m[i].size()>0?1:2);
	for(int j=0;j<m[i].size();j++){
		pa[m[i][j]]=i;
		dfs(m[i][j],dep+1);
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	memset(pa,-1,sizeof(pa));
	for(int tu,tn,tv;cin>>tu;){
		cin>>tn;
		while(tn--){
			cin>>tv;
			m[tu].push_back(tv);
			pa[tv]=tu;
		}
	}
	for(int i=0;i<n;i++)if(t[i]==0){dfs(i,0);t[i]=0;}
	for(int i=0;i<n;i++){
		printf("node %d: parent = %d, depth = %d, %s, [",i,pa[i],d[i],t[i]==0?"root":(t[i]==1?"internal node":"leaf"));
		m[i].size()>0?(printf("%d",m[i][0])):(1);
		for(int j=1;j<m[i].size();j++)printf(", %d",m[i][j]);
		printf("]\n");
	}
	return 0;
}
