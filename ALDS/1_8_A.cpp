#include <bits/stdc++.h>
using namespace std;
struct point{
	int v;
	point *l,*r,*pa;
	point(){l=r=pa=NULL;}
	point(int vv):v(vv){l=r=pa=NULL;}
};
point root;
void insert(int v){
	point *p=&root;
	while(1){
		if(v>=p->v){
			if(!(p->r)){
				p->r=new point(v);
				p->r->pa=p;
				break;
			}else p=p->r;
		}
		else{
			if(!(p->l)){
				p->l=new point(v);
				p->l->pa=p;
				break;
			}else p=p->l;
		} 
	}
}
void dfs1(point *p){
	if(!p)return;
	dfs1(p->l);
	printf(" %d",p->v);
	dfs1(p->r);
}
void dfs2(point *p){
	if(!p)return;
	printf(" %d",p->v);
	dfs2(p->l);
	dfs2(p->r);
}
void print(){
	dfs1(&root);printf("\n");
	dfs2(&root);printf("\n");
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;cin>>T;
	string s;int vv;
	bool first=0;
	while(T--){
		cin>>s;
		if(s=="insert")cin>>vv,first?(insert(vv),0):(root.v=vv,first=!first);
		else print();
	}
	return 0;
}
