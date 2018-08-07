#include <bits/stdc++.h>
using namespace std;
int phi(int n){
	long long res=1;
	for(int i=2;i*i<=n;i++){
		if(n%i==0)res*=i-1,n/=i;
		while(n%i==0)res*=i,n/=i;
	}
	if(n>1)res*=n-1;
	return res;
}
int main(){
	int n;cin>>n;
	cout<<phi(n)<<endl;
	return 0;
}
