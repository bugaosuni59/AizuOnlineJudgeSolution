#include <bits/stdc++.h>
using namespace std;
struct point{
	double x,y;
};
point p1,p2,p,v1,v2;
int main(){
//	freopen("a.txt","r",stdin);
	int n;
	cin>>p1.x>>p1.y>>p2.x>>p2.y;
	v1.x=p2.x-p1.x;
	v1.y=p2.y-p1.y;
	cin>>n;
	while(n--){
		cin>>p.x>>p.y;
		v2.x=p.x-p1.x;
		v2.y=p.y-p1.y;
		double t = (v1.x*v2.x+v1.y*v2.y)/sqrt(v1.x*v1.x+v1.y*v1.y);
		printf("%.10lf %.10lf\n",p1.x+v1.x*t/sqrt(v1.x*v1.x+v1.y*v1.y),p1.y+v1.y*t/sqrt(v1.x*v1.x+v1.y*v1.y));
	}
	return 0;
}
