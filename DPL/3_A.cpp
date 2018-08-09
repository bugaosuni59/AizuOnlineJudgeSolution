#include <bits/stdc++.h>
using namespace std;
int n;
int a[1444][1444];
int p[1444][1444];
int getres(int l,int r,int u,int d){return p[d][r]-p[u-1][r]-p[d][l-1]+p[u-1][l-1];}
int main(){
	cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
	int res=0;
	for(int s=1-m;s<=n-1;s++){
		int i1,j1;
		if(s<=0)i1=1,j1=1-s;
		else j1=1,i1=s+1;
		for(int i=i1,j=j1;i<=n&&j<=m;){
			if(getres(j1,j,i1,i)==0){
				res=max(res,(j-j1+1)*(i-i1+1));// 其实这俩数字相等啦…… 
				i++,j++;
			}else{
				i1++,j1++;
			}
		}
	}
	cout<<res<<endl;
	return 0;
}

