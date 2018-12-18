#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
int n,q,a,b,c;
int main(){
	cin>>n>>q;
	while(q--){
		cin>>a;
		if(a==0){
			cin>>b>>c;
			v[b].push_back(c);
		}else if(a==1){
			cin>>b;
			for(int i=0;i<v[b].size();i++)
				i>=1&&putchar(' '),cout<<v[b][i];
			cout<<"\n";
		}else
			cin>>b,v[b].clear();			
	}
	return 0;
}
