#include <bits/stdc++.h>
using namespace std;
struct point{
	double x,y;
	point(){;}
	point(double x,double y):x(x),y(y){;}
	point operator -(point p){
		return point(x-p.x,y-p.y);
	}
};
// 判断p3在p1p2的哪侧 
double direction(point p1, point p2, point p3) {
	return (p2.x - p1.x)*(p3.y - p2.y) - (p3.x - p2.x)*(p2.y - p1.y);
}
bool isjiao(point p1,point p2,point p3,point p4){
	// 每条线段的两个端点在另一条线断的两端
	double a,b,c,d;
	a=direction(p1,p2,p3);
	b=direction(p1,p2,p4);
	c=direction(p3,p4,p1);
	d=direction(p3,p4,p2);
	if(abs(a+b)<max(abs(a),abs(b))&&abs(c+d)<max(abs(c),abs(d)))return true;
	return false; 
}
double waiji(point p1,point p2){
	return p1.x*p2.y-p1.y*p2.x;
}
double neiji(point p1,point p2){
	return p1.x*p2.x+p1.y*p2.y;
}
// 点与线段距离：三种情况		
double dis(point p,point p1,point p2){
	point v1,v2,v;
	v1=p2-p1;
	v2=p1-p2;
	v=p-p1;
	if(neiji(v,v1)<0)
		return sqrt((p.x-p1.x)*(p.x-p1.x)+(p.y-p1.y)*(p.y-p1.y));
	v=p-p2;
	if(neiji(v,v2)<0)
		return sqrt((p.x-p2.x)*(p.x-p2.x)+(p.y-p2.y)*(p.y-p2.y));
	// 点到线段的垂直距离
	return abs(waiji(v,v2))/sqrt(v2.x*v2.x+v2.y*v2.y); 
}
point p1,p2,p3,p4;
double solve(){
// 相交、或线段1的端点到线段二距离或线段2的端点到线段1距离		
	if(isjiao(p1,p2,p3,p4))return 0;
	double res=min(dis(p1,p3,p4),dis(p2,p3,p4));
	res=min(res,dis(p3,p1,p2));
	res=min(res,dis(p4,p1,p2));
	return res;
}
int main(){
//	freopen("a.txt","r",stdin);
	int T;
	cin>>T;
	while(T--){
		cin>>p1.x>>p1.y;
		cin>>p2.x>>p2.y;
		cin>>p3.x>>p3.y;
		cin>>p4.x>>p4.y;
		printf("%.10f\n",solve()); 
	}
	return 0;
}
