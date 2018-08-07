#include <bits/stdc++.h>
using namespace std;
struct point{
	string s;
	string path;
	int k;
	int i;
};
string s;
unordered_map<string,bool>vis;
queue<point> q;
int jb;
void solve(){
	point p;
	p.s=s;p.i=jb;p.k=0;
	q.push(p);
	while(!q.empty()){
		p=q.front();q.pop();
		string path=p.path;
		if(vis[p.s])continue;
		if(p.s=="123456780"){
			cout<<p.k<<"\n";
//			cout<<p.path<<"\n";
			exit(0);
		}
//		cout<<p.s<<endl;
		vis[p.s]=1;
		p.k+=1;
		if(p.k==5){
			p.k=p.k;
		}
		int i=p.i;
		if(i-3>=0){
			swap(p.s[i],p.s[i-3]);
			p.i=i-3;
			p.path=path+"u";
			q.push(p);
			swap(p.s[i],p.s[i-3]);
		}
		if(i-1>=0&&i%3!=0){
			swap(p.s[i],p.s[i-1]);
			p.i=i-1;
			p.path=path+"l";
			q.push(p);
			swap(p.s[i],p.s[i-1]);
		}
		if(i+3<9){
			swap(p.s[i],p.s[i+3]);
			p.i=i+3;
			p.path=path+"d";
			q.push(p);
			swap(p.s[i],p.s[i+3]);
		}
		if(i+1<9&&(i+1)%3!=0){
			swap(p.s[i],p.s[i+1]);
			p.i=i+1;
			p.path=path+"r";
			q.push(p);
			swap(p.s[i],p.s[i+1]);
		}
	}	
}
int main(){
//	freopen("a.txt","r",stdin);
//	freopen("b.txt","w",stdout);
	char tc;
	for(int i=0;i<9;i++){
		cin>>tc;
		if(tc=='0')jb=i;
		s+=tc;
	}
	solve();
	return 0;
}
