#include <bits/stdc++.h>
using namespace std;
int n;
int a[2000005];
void insert(int k){
	a[++n]=k;
	int i=n;
	while(i/2>=1&&a[i/2]<a[i])swap(a[i/2],a[i]),i/=2;
}
void adjust(int i){
	int l=i*2;int r=i*2+1;
	int jb;
	if(l<=n&&a[l]>a[i])jb=l;else jb=i;
	if(r<=n&&a[r]>a[jb])jb=r;
	if(jb!=i)swap(a[i],a[jb]),adjust(jb);
}
void extract(){
	printf("%d\n",a[1]);
	a[1]=a[n];n--;
	adjust(1);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s;int k;
	n=0;
	while(cin>>s){
		if(s=="insert")cin>>k,insert(k);
		else if(s=="extract")extract();
		else break;
	}
	return 0;
}
