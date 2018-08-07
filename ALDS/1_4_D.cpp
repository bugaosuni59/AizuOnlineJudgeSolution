#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[100005];
bool ok(int p){
	int cnt=0;
	int s=0;
	for(int i=0;i<n;i++){
		s+=a[i];
		if(s>p){
			s=a[i];cnt++;
			if(s>p)return 0;
		}
	}
	if(s>0)cnt++;
	if(s>p)return 0;
	return cnt<=k;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	int l=0,r=1000000001;
	int m;
	while(l<r-2){
		m=(l+r)/2;
		if(ok(m))r=m;
		else l=m;
	}
	for(int i=l;i<=r;i++)
		if(ok(i)){cout<<i<<endl;break;}
	
	return 0;
}
