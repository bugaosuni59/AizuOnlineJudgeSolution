#include <bits/stdc++.h>
using namespace std;
int a[500005];
int n;
void maxHeapify(int i){
	int l=i*2,r=i*2+1;
	int jb;
	if(l<=n&&a[l]>a[i])jb=l;
	else jb=i;
	if(r<=n&&a[r]>a[jb])jb=r;
	if(jb!=i){
		swap(a[i],a[jb]);
		maxHeapify(jb);
	}
}
void buildMaxHeap(){
	for(int i=n/2;i>=1;i--)
		maxHeapify(i);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	buildMaxHeap();
	for(int i=1;i<=n;i++){
		cout<<' '<<a[i];
	}cout<<endl;
	return 0;
}
