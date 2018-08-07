#include<bits/stdc++.h>
using namespace std;
/*
如果是\，推入
如果是/，则造成积水
	如果sc里没有\了，没法积水了
	如果sc里有\，查看这个\距离多远，造成 底长度 l+1的积水，
		同时干掉一个\，距离+2 
其实不是距离，是位置
 	如果sc里有\，查看这个\的位置，计算距离，抛弃这个\ 
*/
struct point{
	int l,v;
	point(){;}
	point(int a,int b):l(a),v(b){;}
};
string s;
stack<int> sp;
stack<point>res;
vector<int> tt;
int main(){
//	freopen("a.txt","r",stdin);
	cin>>s;	
	int ans=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='\\'){
			sp.push(i);
		}else if(s[i]=='_'){
			;
		}else{
			if(sp.empty())continue;
			int p=sp.top();
			sp.pop();
			int d=i-p-1;
			ans+=d+1;
			int v=0;
			while(!res.empty()&&p<res.top().l){
				v+=res.top().v;
				res.pop();
			}
			v+=d+1;
			res.push(point(p,v));
		}
	}
	cout<<ans<<endl;
	while(!res.empty()){
		tt.push_back(res.top().v);res.pop();
	}
	cout<<tt.size();
	for(int i=tt.size()-1;i>=0;i--){
		cout<<' '<<tt[i];
	}cout<<endl;
	return 0;
}

