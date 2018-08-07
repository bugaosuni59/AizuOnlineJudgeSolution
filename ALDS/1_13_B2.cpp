#include <bits/stdc++.h>
using namespace std;
string s;
unordered_map<string,int>vis;
int jb;
int res=25;
bool check(){
	// 检查逆序数是否是偶数
	int invk=0;
	for(int i=0;i<9;i++)
		for(int j=0;j<i;j++)
			if(s[j]!='0'&&s[j]<s[i])invk++;
	if(invk%2)return 0;return 1;
}
void dfs(int k);
void nextdfs(int i,int k){
	int tem=jb;
	swap(s[i],s[jb]);
	jb=i;
	dfs(k+1);
	jb=tem;
	swap(s[i],s[jb]);
}
void dfs(int k){
//	if(vis[s]>k)return;
	if(k>=res)return;
	if(s=="123456780"){res=min(res,k);return;}
//	vis[s]=k;
	if(jb-3>=0)nextdfs(jb-3,k);
	if(jb+3< 9)nextdfs(jb+3,k);
	if(jb-1>=0&&jb%3!=0)nextdfs(jb-1,k);
	if(jb+1< 9&&(jb+1)%3!=0)nextdfs(jb+1,k);
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
	char tc;
	for(int i=0;i<9;i++){
		cin>>tc;
		if(tc=='0')jb=i;
		s+=tc;
	}
	solve();
	return 0;
}
