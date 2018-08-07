#include<bits/stdc++.h>
using namespace std;
struct point{
	point *l;
	point *r;
	int v;
	point(){l=r=NULL;	}
	point(int vv):v(vv){l=r=NULL;	}
}*head,*tail;
int n;
int main(){
//	freopen("a.txt","r",stdin);
	cin>>n;
	string s;int tv;
	head=tail=NULL;
	for(int i=0;i<n;i++){
		cin>>s;
		if(s=="insert"){
			cin>>tv;
			if(!tail)head=tail=new point(tv);
			else{
				point *p=tail;
				tail=tail->r;
				tail=new point(tv);
				tail->l=p;
				p->r=tail;
			}
		}else if(s=="delete"){
			cin>>tv;
			point *p=tail;
			while(p){
				if(p->v==tv){
					if(p->l&&p->r){
						p->l->r=p->r;
						p->r->l=p->l;
					}else{

						if(p==head){
							if(head!=tail){
								head=head->r;
								head->l=NULL;
							}else head=tail=NULL;
						}else{
							if(head!=tail){
								tail=tail->l;
								tail->r=NULL;
							}else head=tail=NULL;
						}
					}
					delete(p);
					break;
				}
				p=p->l;
			}
		}else if(s=="deleteFirst"){
			point *p=tail;
			if(head!=tail){
				tail=tail->l;
				tail->r=NULL;
			}else head=tail=NULL;
			delete(p);
		}else{
			point *p=head;
			if(head!=tail){
				head=head->r;
				head->l=NULL;
			}else head=tail=NULL;
			delete(p);
		}
	}
	point *p=tail;
	while(p!=head){
		cout<<p->v<<' ';
		p=p->l;
	}if(head)cout<<head->v;
	cout<<endl;
	return 0;
}

