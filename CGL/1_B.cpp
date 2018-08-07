#include <bits/stdc++.h>
using namespace std;
struct point{
	double x,y;
}p1,p2,p,v0,v,v1;
int main(){
//	freopen("a.txt","r",stdin);
	int T;
	cin>>p1.x>>p1.y>>p2.x>>p2.y;
	cin>>T;
	v0.x=p1.x-p2.x;v0.y=p1.y-p2.y;
	while(T--){
		cin>>p.x>>p.y;
		v.x=p.x-p1.x;v.y=p.y-p1.y;
		double d=v0.x*v.x+v0.y*v.y;
		d=d/sqrt(v0.x*v0.x+v0.y*v0.y);
		v1.x=p1.x+v0.x/sqrt(v0.x*v0.x+v0.y*v0.y)*d-p.x;
		v1.y=p1.y+v0.y/sqrt(v0.x*v0.x+v0.y*v0.y)*d-p.y;
		v1.x*=2;
		v1.y*=2;
		printf("%.10lf %.10lf\n",p.x+v1.x,p.y+v1.y);
	}
	return 0;
}
