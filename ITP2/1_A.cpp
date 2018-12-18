#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int>v;
	int a,b,n;cin>>n;
	while(n--){
		cin>>a;
		if(a==2)v.pop_back();
		else cin>>b;
		if(a==1)cout<<v[b]<<"\n";
		else if(a==0)v.push_back(b);
	}
	return 0;
}
