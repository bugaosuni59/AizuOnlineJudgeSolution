#include <bits/stdc++.h>
using namespace std;
int main(){
	deque<int>q;
	int a,b,c,n;cin>>n;
	while(n--){
		cin>>a;
		if(a==0){
			cin>>b>>c;
			if(b==0)q.push_front(c);
			else q.push_back(c);
		}else if(a==1){
			cin>>b;
			cout<<q[b]<<"\n";
		}else if(a==2){
			cin>>b;
			if(b==0)q.pop_front();
			else q.pop_back();
		}
	}
	return 0;
}
