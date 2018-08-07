#include <bits/stdc++.h>
using namespace std;
long long pow(long long a,long long b,long long q){
	long long res=1;
	while(b){
		if(b%2)res=res*a%q;
		b/=2;
		a=a*a%q;
	}return res;
}
int n,m,q=1e9+7;
int main(){
	cin>>n>>m;
	cout<<pow(n,m,q)<<endl;
	return 0;
}
