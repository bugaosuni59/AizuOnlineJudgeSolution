#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100005];
int l[100005];
int r[100005];
int main(){
	cin>>n;for(int i=1;i<=n;i++)cin>>a[i];
	a[0]=a[n+1]=-1000000000;
	stack<pair<int,int> >s;
	for(int i=1;i<=n+1;i++){
		while(!s.empty()&&s.top().first>a[i]){
			int h=s.top().first;
			int jb=s.top().second;
			r[jb]=i;
			s.pop();
		}
		s.push({a[i],i});
	}
	while(!s.empty())s.pop();
	for(int i=n;i>=0;i--){
		while(!s.empty()&&s.top().first>a[i]){
			int h=s.top().first;
			int jb=s.top().second;
			l[jb]=i;
			s.pop();
		}
		s.push({a[i],i});
	}
	long long res=0;
	for(int i=1;i<=n;i++)
		res=max(res,a[i]*(r[i]-l[i]-1));
	cout<<res<<"\n";
	return 0;
}

