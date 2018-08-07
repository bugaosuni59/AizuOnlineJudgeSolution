#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a*b/gcd(a,b);}
int main(){
	int n,a,b=1;cin>>n;
	for(int i=0;i<n;i++)cin>>a,b=lcm(a,b);
	cout<<b<<"\n";
	return 0;
}
