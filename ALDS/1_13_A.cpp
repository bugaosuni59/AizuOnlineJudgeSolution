#include <bits/stdc++.h>
using namespace std;
int k;
int a[9][9];
int r[9];
int c[9];
int zhu[19];
int ci[19];
bool ok=0;
void dfs(int i){
	if(i==8){ok=1;return;}
	for(int j=0;j<8;j++){
		if(a[i][j])dfs(i+1);
		if(!a[i][j]&&!c[j]&&!r[i]&&!zhu[i-j+8]&&!ci[i+j]){
			a[i][j]=1;
			c[j]++;r[i]++;zhu[i-j+8]++;ci[i+j]++;
			dfs(i+1);
			if(ok)return;
			a[i][j]=0;
			c[j]--;r[i]--;zhu[i-j+8]--;ci[i+j]--;
		}
	}
}
void solve(){
	dfs(0);
}
int main(){
//	freopen("a.txt","r",stdin);
	cin>>k;
	for(int i=0;i<k;i++){
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
		r[x]++;c[y]++;
		zhu[x-y+8]++;
		ci[x+y]++;
	}
	solve();
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(a[i][j])cout<<'Q';
			else cout<<'.';
		}cout<<"\n";
	}
	return 0;
}
