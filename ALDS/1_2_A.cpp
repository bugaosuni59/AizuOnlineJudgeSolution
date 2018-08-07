#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int a[105];
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int res=0;
	for(int i=0;i<n;i++)
		for(int j=n-1;j>i;j--)
			if(a[j]<a[j-1])swap(a[j],a[j-1]),res++;
	for(int i=0;i<n-1;i++)cout<<a[i]<<' ';cout<<a[n-1]<<endl;
	cout<<res<<endl;
	return 0;
}
