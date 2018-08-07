#include <bits/stdc++.h>
using namespace std;
// 邻接表转化为邻接矩阵
int mat[105][105]; 
int main(){
//	freopen("a.txt","r",stdin);
	memset(mat,0,sizeof(mat));
	int n;
	cin>>n;
	int u,k,v;
	for(int i=0;i<n;i++){
		cin>>u>>k;
		for(int j=0;j<k;j++){
			cin>>v;
//			mat[u-1][v-1]=1;
			mat[u][v]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-1;j++){
			cout<<mat[i][j]<<' ';
		}cout<<mat[i][n]<<endl;
	}
	return 0;
}
