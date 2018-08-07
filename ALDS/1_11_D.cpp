#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> e[100005];
int main(){
//	freopen("a.txt","r",stdin);
	int T,q,u,v;cin>>n>>T;
	while(T--){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}cin>>q;
	while(q--){
		cin>>u>>v;
		
	}
	return 0;
}
