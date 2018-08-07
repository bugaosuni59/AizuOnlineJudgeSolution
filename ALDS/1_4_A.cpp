#include <bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int n,q;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	cin>>q;
	for(int i=0;i<q;i++)cin>>b[i];
	int res=0;
	for(int i=0;i<q;i++){
		for(int j=0;j<n;j++){
			if(a[j]==b[i]){
				res++;break;
			}
		}
	}	
	cout<<res<<endl;
	return 0;
}
