#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("a.txt","r",stdin);
	stringstream ss;
	string s;
	getline(cin,s);
	ss<<s;
	bool combo=0;
	char c;int k;
	stack<int> a;
	for(int i=0;i<s.length();i++){
		if(s[i]==' ')combo=0;
		else if(s[i]>='0'&&s[i]<='9'){
			if(combo)continue;
			else combo=1;
			ss>>k;
			a.push(k);
		}else{
			ss>>c;
			if(c=='+'){
				int y=a.top();a.pop();
				int x=a.top();a.pop();
				a.push(x+y);
			}else if(c=='-'){
				int y=a.top();a.pop();
				int x=a.top();a.pop();
				a.push(x-y);
			}else if(c=='*'){
				int y=a.top();a.pop();
				int x=a.top();a.pop();
				a.push(x*y);
			}
		}
	}
	cout<<a.top()<<endl;
	
	return 0;
}

