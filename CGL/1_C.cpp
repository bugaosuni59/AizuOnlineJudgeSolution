#include <bits/stdc++.h>
using namespace std;
struct point{
	int x,y;
	point operator - (const point p){
		point pp;
		pp.x=x-p.x;
		pp.y=y-p.y;
		return pp;
	}
}p0,p1,p2;
double waiji(point p1,point p2){
	return p1.x*p2.y-p1.y*p2.x;
}
double neiji(point p1,point p2){
	return p1.x*p2.x+p1.y*p2.y;
}
void solve(){
	double xc=waiji(p1-p0,p2-p0);	
	if(xc>0){cout<<"COUNTER_CLOCKWISE"<<endl;return;}
	if(xc<0){cout<<"CLOCKWISE"<<endl;return;}
	if(neiji(p1-p0,p2-p0)<0){cout<<"ONLINE_BACK"<<endl;return;}
	if(abs(p1.x-p0.x)<abs(p2.x-p0.x)||abs(p1.y-p0.y)<abs(p2.y-p0.y)){cout<<"ONLINE_FRONT"<<endl;return;}
	cout<<"ON_SEGMENT"<<endl;
}
int main(){
	cin>>p0.x>>p0.y;
	cin>>p1.x>>p1.y;
	int T; cin>>T;
	while(T--){
		cin>>p2.x>>p2.y;
		solve();
	}
	return 0;
}

