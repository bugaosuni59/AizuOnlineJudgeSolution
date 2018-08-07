#include <bits/stdc++.h>
using namespace std;
int n;
map<string,int> m;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		if(s=="insert"){
			cin>>s;
			m[s]=1;
		}else{
			cin>>s;
			if(m[s])cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
	}

	return 0;
}
