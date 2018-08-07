#include <bits/stdc++.h>
using namespace std;
int exgcd(int a,int &s,int b,int &t){
	if(b==0){
		s=1;t=0;return a;
	}
	int k=exgcd(b,s,a%b,t);
	swap(s,t);
	t=t-a/b*s;
	return k;
}
int main(){
	int a,b,x,y;
	cin>>a>>b;
	int k=exgcd(a,x,b,y);
	cout<<x<<' '<<y<<"\n";
	return 0;
}
