#include <bits/stdc++.h>
using namespace std;
/*
插入排序模拟 
已经给伪代码了，所以很好写 
*/
int a[105];
int n;
int main(){
//	freopen("a.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n-1;i++)
		cin>>a[i],cout<<a[i]<<' ';
	cin>>a[n-1];
	cout<<a[n-1]<<endl;
	for(int i=1;i<n;i++){
		int key=a[i];
		int j=i-1;
		while(j>=0&&a[j]>key)
			a[j+1]=a[j],j--;
		a[j+1]=key;
		for(int i=0;i<n-1;i++)
			cout<<a[i]<<' ';
		cout<<a[n-1]<<endl;
	}
	return 0;
}
