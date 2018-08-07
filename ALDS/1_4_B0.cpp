#include <bits/stdc++.h>
using namespace std;
int a[100005];
int n,q;

int main(){
//	freopen("a.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
//	sort(a,a+n);
	cin>>q;
	int res=0,number;
	for(int i=0;i<q;i++){
		cin>>number;
		int jb=lower_bound(a,a+n,number)-a;
		if(jb<n&&a[jb]==number)res++;
	}
	cout<<res<<endl;
	return 0;
}
