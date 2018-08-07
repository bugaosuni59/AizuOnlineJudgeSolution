#include <bits/stdc++.h>
using namespace std;
int n;
int a[22];
map<int,int> m;
void init(){
	int r=1<<20;
	for(int t=1;t<r;t++){
		int k=t;
		int s=0;
		for(int i=0;k;i++){
			if(k%2)s+=a[i];
			k/=2;
		}
		m[s]=1;
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	init();
	int T;cin>>T;
	while(T--){
		int tt;
		cin>>tt;
		if(m[tt])puts("yes");
		else puts("no");
	}
	return 0;
}
