#include <bits/stdc++.h>
#define CLOCKWISE 1
using namespace std;
struct point{
	int x,y;
	point operator - (const point p){
		point pp;
		pp.x=x-p.x;
		pp.y=y-p.y;
		return pp;
	}
	bool operator < (const point& p)const{
		if(x==p.x)return y<p.y;
		return x<p.x;
	}
}pp[100005];
vector<point> stk1;
vector<point> stk2;
int n;
double waiji(point p1,point p2){
	return p1.x*p2.y-p1.y*p2.x;
}
double neiji(point p1,point p2){
	return p1.x*p2.x+p1.y*p2.y;
}
double eps=1e-9;
bool ccw(point pa,point pb,point pc){
	if(waiji(pb-pa,pc-pa)<=eps)return CLOCKWISE;
}
void andrew(){
	sort(pp,pp+n);
	stk1.clear();
	stk2.clear();
//	if(n<3)return;
	stk1.push_back(pp[0]); 
	stk1.push_back(pp[1]); 
	stk2.push_back(pp[n-1]); 
	stk2.push_back(pp[n-2]); 
	for(int i=2;i<n;i++){
		for(int j=stk1.size();j>=2&&ccw(stk1[j-2],stk1[j-1],pp[i])!=CLOCKWISE;j--)
			stk1.erase(--stk1.end());
		stk1.push_back(pp[i]);
	}
	for(int i=n-3;i>=0;i--){
		for(int j=stk2.size();j>=2&&ccw(stk2[j-2],stk2[j-1],pp[i])!=CLOCKWISE;j--)
			stk2.erase(--stk2.end());
		stk2.push_back(pp[i]);
	}
	reverse(stk2.begin(),stk2.end());
	for(int i=stk1.size()-2;i>=1;i--)stk2.push_back(stk1[i]);
}
double dis(point p1,point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int main(){
//	freopen("a.txt","r",stdin);
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		if(n==1){
			printf("0.00\n");continue;
		}
		if(n==2){
			for(int i=0;i<n;i++){
				cin>>pp[i].x>>pp[i].y;
			}		
			printf("%.2f\n",dis(pp[0],pp[1]));continue;
		}
		for(int i=0;i<n;i++)scanf("%d%d",&pp[i].x,&pp[i].y);
		andrew();
//		printf("%d\n",stk2.size());
//		for(int i=0;i<stk2.size();i++){
//			printf("%d %d\n",stk2[i].x,stk2[i].y);
//		}
		double res=0;
		for(int i=0;i<stk2.size()-1;i++){
			res+=dis(stk2[i],stk2[i+1]);
		}res+=dis(stk2[0],stk2[stk2.size()-1]);
		printf("%.2f\n",res);
	}
	return 0;
}

