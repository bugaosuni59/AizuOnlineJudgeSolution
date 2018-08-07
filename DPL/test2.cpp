#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cout.tie(0);
	freopen("b.txt","r",stdin);
	freopen("c.txt","w",stdout);
	int a,b,s=0;
	while(cin>>a>>b){
		s+=b;
		cout<<a<<'\t'<<s<<"\n";
	}
	return 0;
}
