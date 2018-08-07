#include <bits/stdc++.h>
using namespace std;
int n;
int a[500005];
int b[500005];
int res=0;
void merge(int l,int r){
	int m=(l+r)/2;
	// l,m    m+1,r
	int p1=l,p2=m+1;
	for(int i=l;i<=r;i++){
		res++;
		if(p2>r||(p1<=m&&a[p1]<a[p2])){
			b[i]=a[p1];
			p1++;
		}else{
			b[i]=a[p2];
			p2++;
		}
	}
	for(int i=l;i<=r;i++)a[i]=b[i];
}
void ms(int l,int r){
	if(l>=r)return;
	ms(l,(l+r)/2);
	ms((l+r)/2+1,r);
	merge(l,r);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	ms(1,n);
	for(int i=1;i<n;i++)cout<<a[i]<<" ";
	cout<<a[n]<<endl<<res<<endl;
	return 0;
}
