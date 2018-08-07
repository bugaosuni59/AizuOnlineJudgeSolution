#include <bits/stdc++.h>
using namespace std;
struct point{
	double x,y;
	point(){;}
	point(double a,double b):x(a),y(b){;}
};
vector<point> v;
double dis(point p1,point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

void dfs(int d,point pl,point pr){
	if(d<=0)return;
	// 1/3 1/2 2/3¼Ó3¸öµã 
	point p1,p2,p3;
	p1.x=pl.x/3*2+pr.x/3;
	p1.y=pl.y/3*2+pr.y/3;
	dfs(d-1,pl,p1);
	v.push_back(p1);

	point vert;
	vert.x=-(pr.y-pl.y);
	vert.y=(pr.x-pl.x);
	vert.x/=2*sqrt(3);
	vert.y/=2*sqrt(3);

	p2.x=(pl.x+pr.x)/2+vert.x;
	p2.y=(pl.y+pr.y)/2+vert.y;
	dfs(d-1,p1,p2);
	v.push_back(p2);

	p3.x=pl.x/3+pr.x/3*2;
	p3.y=pl.y/3+pr.y/3*2;
	dfs(d-1,p2,p3);
	v.push_back(p3);
	dfs(d-1,p3,pr);
}
int main(){
	int n;cin>>n;
	v.push_back(point(0,0));
	dfs(n,point(0,0),point(100,0));
	v.push_back(point(100,0));
	for(int i=0;i<v.size();i++)
		printf("%.6f %.6f\n",v[i].x,v[i].y);
	return 0;
}
