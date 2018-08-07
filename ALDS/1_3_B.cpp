#include<bits/stdc++.h>
using namespace std;
struct point{
	string s;
	int t;
}a;
int n,t;
int main(){
//	freopen("a.txt","r",stdin);
	cin>>n>>t;
	queue<point> q;
	for(int i=0;i<n;i++){
		cin>>a.s>>a.t;
		q.push(a);
	}
	int k=0;
	while(!q.empty()){
		a=q.front();q.pop();
		if(a.t<=t){
			k+=a.t;
			cout<<a.s<<' '<<k<<"\n";
		}else{
			k+=t;
			a.t-=t;
			q.push(a);
		}
	}
	return 0;
}

