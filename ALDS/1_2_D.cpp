#include <bits/stdc++.h>
using namespace std;
int cnt;
int a[1000005];
void is(int n,int g){
	for(int i=g;i<n;i++){
		int v=a[i];
		int j=i-g;
		while(j>=0&&a[j]>v){
			a[j+g]=a[j];
			j=j-g;
			cnt++;
		}
		a[j+g]=v;
	}
}
int g[1000005];
int m;
void ss(int n){
	cnt=0;
	m=1;
	g[0]=1;
	for(;g[m-1]*3+1<=n;m++)
		g[m]=g[m-1]*3+1;
	reverse(g,g+m);
	for(int i=0;i<m;i++){
		is(n,g[i]);
	}
}
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	ss(n);
	cout<<m<<endl;
	for(int i=0;i<m-1;i++){
		cout<<g[i]<<' ';
	}cout<<g[m-1]<<"\n";
	cout<<cnt<<"\n";
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\n";
	}
	return 0;
}

