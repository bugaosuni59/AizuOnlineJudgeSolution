#include <bits/stdc++.h>
using namespace std;
int a[100005];
int n;
//void qs(int l,int r){
//	int x=a[r];
//	int p1=l,p2=r;
//	while(p1!=p2){
//		while(p1!=p2&&a[p1]<x)p1++;
//		a[p2]=a[p1];
//		while(p1!=p2&&a[p2]>x)p2--;
//		a[p1]=a[p2];
//	}
//	a[p1]=x;
//	for(int i=0;i<p1;i++)printf("%d ",a[i]);
//	printf("[%d]",a[p1]);
//	for(int i=p1+1;i<=r;i++)printf(" %d",a[i]);
//}
void pa(int l,int r,int p){
	int x=a[r];
	int i=p;
	for(int j=p;j<r;j++){
		if(a[j]<=x){
			swap(a[i],a[j]);
			i++;
		}
	}
	swap(a[i],a[r]);
	for(int j=0;j<i;j++)printf("%d ",a[j]);
	printf("[%d]",a[i]);
	for(int j=i+1;j<=r;j++)printf(" %d",a[j]);
	printf("\n");
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	pa(0,n-1,0);
	return 0;
}
