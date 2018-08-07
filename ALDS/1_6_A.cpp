#include <bits/stdc++.h>
using namespace std;

int b[10005];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int n,a;cin>>n;
	for(int i=0;i<n;i++)cin>>a,b[a]++;
	for(int i=0;i<=10000;i++)
		if(b[i]){b[i]--;cout<<i;break;}
	for(int i=0;i<=10000;i++)
		while(b[i]--)cout<<' '<<i;
	cout<<endl;
	return 0;
}
