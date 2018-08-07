#include <bits/stdc++.h>
using namespace std;
struct edge{
	int v,w;
	edge(){;}
	edge(int v,int w):v(v),w(w){;}
	bool operator<(const edge&p)const{
		return w>p.w;
	}
};
vector<edge> e[105];
priority_queue<edge> q;
bool ok[105];
int main(){
//	freopen("a.txt","r",stdin);
	int n,tem;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin>>tem;
			if(tem!=-1)e[i].push_back(edge(j,tem)),e[j].push_back(edge(i,tem));
		}
	int res=0;
	ok[0]=1;
	int k=0;
	for(int i=0;i<e[0].size();i++)q.push(e[0][i]);
	while(k!=n-1){
		edge te=q.top();q.pop();
		if(ok[te.v])continue;
		else{
			k++;
			ok[te.v]=1;
			res+=te.w;
			for(int i=0;i<e[te.v].size();i++)q.push(e[te.v][i]);
		}
	}
	cout<<res<<endl;
	return 0;
}
