#include <bits/stdc++.h>
using namespace std;
vector<int> e[105];
int res[105];
bool ok[105];
int n;
int inf=1<<30;
int main(){
//	freopen("a.txt","r",stdin);
	cin>>n;
	int u,v,k;
	fill(res,res+103,inf);
	while(cin>>u){
		cin>>k;
		for(int i=0;i<k;i++)cin>>v,e[u].push_back(v);
	}
	queue<pair<int,int> >q;
	q.push({1,0});
	ok[1]=1;
	while(!q.empty()){
		pair<int,int> p=q.front();q.pop();
		int i=p.first;int d=p.second;
		res[i]=min(res[i],d);
		for(int j=0;j<e[i].size();j++)
			if(!ok[e[i][j]])q.push({e[i][j],d+1}),ok[e[i][j]]=1;
	}
	for(int i=1;i<=n;i++)
		printf("%d %d\n",i,(ok[i])?res[i]:-1);
	return 0;
}
