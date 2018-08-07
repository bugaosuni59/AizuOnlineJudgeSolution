#include <bits/stdc++.h>
using namespace std;
struct point{
	int v;
	point *l,*r,*pa;
	point(){l=r=pa=NULL;}
	point(int vv):v(vv){l=r=pa=NULL;}
};
point *root;
void insert(int v){
	point *p,*pa=NULL;
	p=root;
	while(p){
		pa=p;
		if(v>=p->v)p=p->r;
		else p=p->l;
	}
	if(!pa){root=new point(v);return;}
	if(v>=pa->v)pa->r=new point(v),pa->r->pa=pa;
	else pa->l=new point(v),pa->l->pa=pa;
}
point* find(int v){
	point *p=root;
	while(p){
		if(v>p->v)p=p->r;
		else if(v<p->v)p=p->l;
		else break;
	}return p;
}
point* nextp(point *p){
	if(!p->l)return p;
	else return nextp(p->l); 
}
void del(point *p){
	if(!p)return;
	point *pa=p->pa;
	if(!p->l&&!p->r){if(pa)p->v>=pa->v?(pa->r=NULL):(pa->l=NULL);}
	else if(p->l&&!p->r){if(pa)p->v>=pa->v?(pa->r=p->l):(pa->l=p->l),p->l->pa=pa;}
	else if(!p->l&&p->r){if(pa)p->v>=pa->v?(pa->r=p->r):(pa->l=p->r),p->r->pa=pa;}
	else{
		// 中序遍历该点的后一个节点（某个叶子）放过来 
		point *ne=nextp(p->r);
		p->v=ne->v;
		p=ne;
		p->v>=p->pa->v?(p->pa->r=NULL):(p->pa->l=NULL);
	}
	delete(p);
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
	dfs1(root);printf("\n");
	dfs2(root);printf("\n");
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;cin>>T;
	string s;int vv;
	bool first=0;
	while(T--){
		cin>>s;
		if(s=="insert")cin>>vv,insert(vv);
		else if(s=="find")cin>>vv,(printf("%s\n",find(vv)?"yes":"no"));
		else if(s=="delete")cin>>vv,del(find(vv));
		else print();
	}
	return 0;
}
