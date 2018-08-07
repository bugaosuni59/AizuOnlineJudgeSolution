#include <bits/stdc++.h>
using namespace std;
struct point{
	int a;
	char c;
	int i;
	bool operator <(const point&p)const{
		return a<p.a;
	}
	bool operator <=(const point&p)const{
		return a<=p.a;
	}
	bool operator ==(const point&p)const{
		return a==p.a;
	}
}a[100005];
int n;
int pa(int l,int r,int p){
	point x=a[r];
	int i=p-1;
	for(int j=p;j<r;j++){
		if(a[j]<=x){
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	return i+1;
}
void qs(int p,int r){
	if(p<r){
		int m=pa(0,r,p);
		qs(p,m-1);
		qs(m+1,r);
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i].c>>a[i].a,a[i].i=i;
	qs(0,n-1);
	bool ok=1;
	for(int i=0;i<n-1;i++)
		if(a[i]==a[i+1])if(a[i].i>a[i+1].i)ok=0;
	if(ok)cout<<"Stable"<<"\n";
	else cout<<"Not stable"<<"\n";
	for(int i=0;i<n;i++)
		cout<<a[i].c<<' '<<a[i].a<<"\n";
	return 0;
}
