#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("c.txt","r",stdin);
	freopen("d.txt","w",stdout);
	double a,b;
	while(cin>>a>>b){
		printf("%f\t%f\n",a,b/a);
	}
	return 0;
}
