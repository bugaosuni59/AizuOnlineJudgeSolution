#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long pow(long long n,long long k,long long q){
	long long res=1;
	while(k){
		if(k%2)res=res*n%q,k--;
		k/=2;
		n=n*n%q;
	}return res;
}
int main(){
	int n,k;cin>>n>>k;
	printf("%lld\n",pow(k,n,1e9+7));
	return 0;
}

