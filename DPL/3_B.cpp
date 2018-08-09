#include <bits/stdc++.h>
using namespace std;
int n;
int a[1444][1444];
int p[1444][1444];
int l[1444],r[1444];
int main(){
	cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
	for(int j=1;j<=m;j++){
		int k=0;
		for(int i=1;i<=n;i++){
			if(a[i][j]==0)k++;
			else k=0;
			p[i][j]=k;
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		stack<pair<int,int> >s;// (h,jb)最小单增队列 
		s.push({-1,0});// 作为左最小界 
		int ll=0;
		for(int j=1;j<=m;j++){
			while(s.top().first>p[i][j]){// 不用判空，因为留着最小的呢不会空 
				int h=s.top().first;
				int jb=s.top().second;
				s.pop();
				r[jb]=j;
			}
			if(s.top().first<p[i][j])ll=s.top().second;
			l[j]=ll;
			s.push({p[i][j],j});
		}
		while(!s.empty()){
			int h=s.top().first;
			int jb=s.top().second;
			s.pop();
			r[jb]=m+1;
		}
		for(int j=1;j<=m;j++)
			res=max(res,(r[j]-l[j]-1)*p[i][j]);
	}
	cout<<res<<endl;
	return 0;
}

