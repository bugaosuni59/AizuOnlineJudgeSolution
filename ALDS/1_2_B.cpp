#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int a[105];
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int res=0;
	for(int i=0;i<n;i++){
		int mini=i;
		for(int j=i;j<n;j++)
			if(a[j]<a[mini])mini=j;
		if(i!=mini)res++;
		swap(a[i],a[mini]);
	}
	for(int i=0;i<n-1;i++)cout<<a[i]<<' ';cout<<a[n-1]<<endl;
	cout<<res<<endl;
	return 0;
}
