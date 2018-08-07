#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("b.txt","r",stdin);
	freopen("e.txt","w",stdout);
	int a,b,m;
	while(cin>>a>>b){
		m=max(m,b);
//		printf("%d\t%d\n",a,m);
		cout<<a<<'\t'<<m<<"\n";
	}
	return 0;
}
