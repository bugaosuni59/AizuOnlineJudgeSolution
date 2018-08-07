#include <bits/stdc++.h>
using namespace std;
int n;
int inf=1<<30;
int d[105][105];
int main(){
//	freopen("a.txt","r",stdin);
	fill(d[0],d[0]+105*105,inf);
	cin.tie(0);
	int m,u,v,c;
	cin>>n>>m;
	while(m--){
		cin>>u>>v>>c;
		d[u][v]=c;
	}
	for(int i=0;i<n;i++)d[i][i]=0;
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(d[i][k]<inf&&d[k][j]<inf)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(d[i][j]>=inf)cout<<"INF ";
			else cout<<d[i][j]<<' ';
		}int j=n-1;
		if(d[i][j]>=inf)cout<<"INF\n";
		else cout<<d[i][j]<<"\n";
	}
	return 0;
}
