#include <bits/stdc++.h>
using namespace std;
int a[10];
int jb;// 0的位置 
unordered_map<int,bool>ma;
bool vis(){
	int b=0;
	for(int i=0;i<9;i++)b=b*10+a[i];
	return ma[b];
}
void setvis(){
	int b=0;
	for(int i=0;i<9;i++)b=b*10+a[i];
	ma[b]=1;
}
void cancelvis(){
	int b=0;
	for(int i=0;i<9;i++)b=b*10+a[i];
	ma[b]=0;
}
bool check(){
	// 检查逆序数是否是偶数
	int invk=0;
	for(int i=0;i<9;i++)
		for(int j=0;j<i;j++)
			if(a[j]!=0&&a[j]<a[i])invk++;
	if(invk%2)return 0;return 1;
}
bool ok(){for(int i=0;i<8;i++)if(a[i]!=i+1)return 0;return 1;}
int res=31;
void dfs(int k){
	if(k>=res||vis())return;
	if(ok()){res=min(res,k);return;}
	setvis();
	if(jb-3>=0){
		swap(a[jb],a[jb-3]);
		jb=jb-3;
		dfs(k+1);
		swap(a[jb],a[jb+3]);
		jb=jb+3;
	}
	if(jb+3<9){
		swap(a[jb],a[jb+3]);
		jb=jb+3;
		dfs(k+1);
		swap(a[jb],a[jb-3]);
		jb=jb-3;
	}
	if(jb-1>=0&&jb%3!=0){
		swap(a[jb],a[jb-1]);
		jb=jb-1;
		dfs(k+1);
		swap(a[jb],a[jb+1]);
		jb=jb+1;
	}
	if(jb+1<9&&(jb+1)%3!=0){
		swap(a[jb],a[jb+1]);
		jb=jb+1;
		dfs(k+1);
		swap(a[jb],a[jb-1]);
		jb=jb-1;
	}
	cancelvis();
}
void solve(){
	// 检验正确性
	if(!check())return;
	// 搜索
	dfs(0);
	cout<<res<<endl; 
}
int main(){
//	freopen("a.txt","r",stdin);
	for(int i=0;i<9;i++){
		cin>>a[i];
		if(a[i]==0)jb=i;
	}
	solve();
	return 0;
}
