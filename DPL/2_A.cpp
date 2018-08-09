#include <bits/stdc++.h>
using namespace std;
int n;
int m[66][66];
int inf=1000000;
int main(){
	int Q;cin>>n>>Q;
	for(int i=0;i<=20;i++)for(int j=0;j<=20;j++)m[i][j]=inf;
	while(Q--)int u,v,w,cin>>u>>v>>w,m[u][v]=w;
	return 0;
}

