#include <bits/stdc++.h>
using namespace std;
//节点从0到n-1
#define maxn 100006
struct node { double x, y; };
int n;//有多少个点
int tot;//凸包上的点
node p[maxn];//所有点数组从0开始
node P[maxn];//凸包上的点
const double pi = acos(-1.0);
//三点差积	 
double X(node A, node B, node C) { return (B.x - A.x)*(C.y - A.y) - (C.x - A.x)*(B.y - A.y); }
//两点距离
double len(node A, node B) { return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y)); }
//角度小的在前面,相同的话距离小的在前面
bool cmp(node A, node B) {
	double pp = X(p[0], A, B);
	if (pp > 0)return true;
	if (pp < 0)return false;
	if (pp == 0)return len(p[0], A) < len(p[0], B);
}
const double eps = 1e-9;
//三点点积	 
double dian(node A, node B, node C) { return (B.x - A.x)*(C.x - A.x) + (C.y - A.y)*(B.y - A.y); }
//建立凸包存到P里//以下是n>=3的情况,n=1,2要特判
void build() {
	//找左下角的点
	for (int i = 0; i < n; i++) {
		if (p[i].y < p[0].y) swap(p[i], p[0]);
		if (p[i].y == p[0].y&&p[i].x < p[0].x) swap(p[i], p[0]);
	}
	sort(p + 1, p + n, cmp);
	P[0] = p[0];
	P[1] = p[1];
	tot = 1;//初始两个点
	for (int i = 2; i < n; i++) {
		//如果需要边上的点 
		while (tot > 0 && X(P[tot - 1], P[tot], p[i]) < 0)tot--;
//		while (tot > 0 && X(P[tot - 1], P[tot], p[i]) <= 0)tot--;//P[tot]在左边 舍弃
		tot++;
		P[tot] = p[i];
	}
	// 如果需要边上点 要这块 
	node endd = P[tot];
	for (int i = n - 1; i >= 0; i--) {
		if (abs(X(P[0], endd, p[i])) <= eps) {
			if (dian(p[i], P[0], endd) < 0) {
				tot++;
				P[tot] = p[i];
			}
		}
		else break;
	}
	// 到这上面是需要注释掉的 
	tot++;
}
int main(){
//	freopen("a.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++)cin>>p[i].x>>p[i].y;
	build();
	printf("%d\n",tot);
	for(int i=0;i<tot;i++){
		cout<<P[i].x<<' '<<P[i].y<<endl;
	}
	return 0;
}
