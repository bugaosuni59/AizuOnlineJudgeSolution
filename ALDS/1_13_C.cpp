#include <bits/stdc++.h>
using namespace std;
struct point{
	string s;
	int k,i;
	int h;
	bool operator<(const point&p)const{
		return h>p.h;
	}
};
string s;
int jb;
unordered_map<string,int> vis;
int geth(string &t,int k){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(t[i*4+j]!='0'){
				char c=t[i*4+j];
				int a=(c>='a'?(c-'a'+10):c-'0');
				int x=(a-1)/4,y=(a-1)%4;
				k+=abs(x-i)+abs(y-j);
			}
		}
	}
	return k;
}
void solve(){
	priority_queue<point> q;
	point p={s,0,jb};
	p.h=geth(p.s,p.k);
	q.push(p);
	while(!q.empty()){
		p=q.top();q.pop();
		if(vis[p.s])continue;
		vis[p.s]=1;
//		cout<<p.k<<" "<<p.s<<"\n";
		if(p.s=="123456789abcdef0")cout<<p.k<<"\n",exit(0);
		int i=p.i;
		p.k++;
		if(i-4>=0){
			p.i=i-4;
			swap(p.s[p.i],p.s[i]);
			p.h=geth(p.s,p.k);
			if(p.h<=45)q.push(p);
			swap(p.s[p.i],p.s[i]);
		}
		if(i+4<16){
			p.i=i+4;
			swap(p.s[p.i],p.s[i]);
			p.h=geth(p.s,p.k);
			if(p.h<=45)q.push(p);
			swap(p.s[p.i],p.s[i]);
		}
		if(i-1>=0&&i%4!=0){
			p.i=i-1;
			swap(p.s[p.i],p.s[i]);
			p.h=geth(p.s,p.k);
			if(p.h<=45)q.push(p);
			swap(p.s[p.i],p.s[i]);
		}
		if(i+1<16&&(i+1)%4!=0){
			p.i=i+1;
			swap(p.s[p.i],p.s[i]);
			p.h=geth(p.s,p.k);
			if(p.h<=45)q.push(p);
			swap(p.s[p.i],p.s[i]);
		}
	}
}
int main(){
//	freopen("a.txt","r",stdin);
//	freopen("b.txt","w",stdout);
	int ta;
	for(int i=0;i<16;i++){
		cin>>ta;
		if(ta<=9)s+=('0'+ta);
		else s+='a'+(ta-10);
		if(ta==0)jb=i;
	}
	solve();
	return 0;
}
