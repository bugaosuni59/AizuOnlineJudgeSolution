#include <bits/stdc++.h>
using namespace std;
struct point{
	int x,y;
};
point p1,p2,p3,p4,v1,v2;
int main(){
//	freopen("a.txt","r",stdin);
	int T;
	cin>>T;
	while(T--){
		cin>>p1.x>>p1.y;
		cin>>p2.x>>p2.y;
		cin>>p3.x>>p3.y;
		cin>>p4.x>>p4.y;
		v1.x=p2.x-p1.x;
		v1.y=p2.y-p1.y;
		v2.x=p4.x-p3.x;
		v2.y=p4.y-p3.y;
		// 外积为0则平行，内积为0则垂直 
		if(v1.x*v2.y-v1.y*v2.x==0){
			cout<<2<<endl;
		}else if(v1.x*v2.x+v1.y*v2.y==0){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	
	return 0;
}
