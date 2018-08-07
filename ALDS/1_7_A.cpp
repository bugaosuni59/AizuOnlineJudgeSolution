#include <bits/stdc++.h>
using namespace std;
vector<int> m[100005];
int pa[100005];
int d[100005];
int t[100005];// 0 rt 1 nd 2 lf
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	memset(pa,-1,sizeof(pa));
	for(int tu,tn,tv;cin>>tu;){
		cin>>tn;
		while(tn--){
			cin>>tv;
			m[tu].push_back(tv);
			pa[tu]==-1?(0):(t[tu]=1);
			t[tv]=(m[tv].size()>0?1:2);
			pa[tv]=tu;
		}
	}
	queue<int> q;
	for(int i=0;i<n;i++)if(t[i]==0)q.push(i);
	while(!q.empty()){
		int i=q.front();q.pop();
		for(int j=0;j<m[i].size();j++){
			d[m[i][j]]=d[i]+1;
			q.push(m[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		printf("node %d: parent = %d, depth = %d, %s, [",i,pa[i],d[i],t[i]==0?"root":(t[i]==1?"internal node":"leaf"));
		m[i].size()>0?(printf("%d",m[i][0])):(1);
		for(int j=1;j<m[i].size();j++)printf(", %d",m[i][j]);
		printf("]\n");
	}
	return 0;
}
