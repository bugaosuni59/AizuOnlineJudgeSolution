#include <bits/stdc++.h>
using namespace std;
int le[100005];
int ri[100005];
int a[100005];
int b[100005];
int n;
void solve(int i,int l,int r){
	int j;
	for(j=l;b[j]!=a[i];j++);
	le[i]=ri[i]=-1;
	if(j-l>0){// ´æÔÚ×óÊ÷ 
		le[i]=i+1;
		solve(i+1,l,j-1);	
	}
	if(r-j>0){
		ri[i]=i+j-l+1;
		solve(i+j-l+1,j+1,r);
	}
}
vector<int>res;
void dfs(int i){
	if(le[i]!=-1)dfs(le[i]);
	if(ri[i]!=-1)dfs(ri[i]);
	res.push_back(a[i]);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	solve(0,0,n-1);
	dfs(0);
	for(int i=0;i<res.size()-1;i++){
		cout<<res[i]<<' ';
	}cout<<res[res.size()-1]<<endl;
	return 0;
}
