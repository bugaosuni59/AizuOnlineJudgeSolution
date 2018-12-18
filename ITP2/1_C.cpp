#include <bits/stdc++.h>
using namespace std;
int main(){
	list<int>v;
	int a,b,n;cin>>n;
	list<int>::iterator c=v.end();
	while(n--){
		cin>>a;
		if(a==0){
			cin>>b;
			c=v.insert(c,b);
		}else if(a==1){
			cin>>b;
			if(b>0)while(b--)c++;
			else while(b++)c--;
		}else c=v.erase(c);
	}
	for(c=v.begin();c!=v.end();c++)cout<<*c<<"\n";
	return 0;
}
