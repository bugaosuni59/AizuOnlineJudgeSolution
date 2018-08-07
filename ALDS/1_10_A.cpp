#include <bits/stdc++.h>
using namespace std;
long long a[1005];
int main(){
//	freopen("a.txt","r",stdin);
	a[0]=a[1]=1;
	for(int i=2;i<=44;i++)
		a[i]=a[i-2]+a[i-1];
	int n;cin>>n;cout<<a[n]<<endl;
	return 0;
}
