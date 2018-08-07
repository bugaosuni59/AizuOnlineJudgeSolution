#include <bits/stdc++.h>
using namespace std;
struct point{
	int a,i;
	bool operator<(const point&p)const{
		return a<p.a;
	}
}b[2005];
int a[2005];
int k[2005];
bool ok[2005];
int n;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		b[i].a=a[i];
		b[i].i=i;
	}
	sort(b,b+n);
	for(int i=0;i<n;i++)k[b[i].i]=i;
	int res=0;
	for(int i=0;i<n;i++){
		if(ok[i])continue;
		int j=i;
		int t=0;
		int s=0;
		while(k[j]!=i){
			ok[j]=1;
			s+=a[j];
			j=k[j];
			t++;
		}
//		s+=t*a[j];
		ok[j]=1;
		res+=min(s+t*a[j],s+t*b[0].a+2*(b[0].a+a[j]));
	}
	cout<<res<<endl;
	return 0;
}
