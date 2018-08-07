#include <bits/stdc++.h>
using namespace std;
//�ڵ��0��n-1
#define maxn 100006
struct node { double x, y; };
int n;//�ж��ٸ���
int tot;//͹���ϵĵ�
node p[maxn];//���е������0��ʼ
node P[maxn];//͹���ϵĵ�
const double pi = acos(-1.0);
//������	 
double X(node A, node B, node C) { return (B.x - A.x)*(C.y - A.y) - (C.x - A.x)*(B.y - A.y); }
//�������
double len(node A, node B) { return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y)); }
//�Ƕ�С����ǰ��,��ͬ�Ļ�����С����ǰ��
bool cmp(node A, node B) {
	double pp = X(p[0], A, B);
	if (pp > 0)return true;
	if (pp < 0)return false;
	if (pp == 0)return len(p[0], A) < len(p[0], B);
}
const double eps = 1e-9;
//������	 
double dian(node A, node B, node C) { return (B.x - A.x)*(C.x - A.x) + (C.y - A.y)*(B.y - A.y); }
//����͹���浽P��//������n>=3�����,n=1,2Ҫ����
void build() {
	//�����½ǵĵ�
	for (int i = 0; i < n; i++) {
		if (p[i].y < p[0].y) swap(p[i], p[0]);
		if (p[i].y == p[0].y&&p[i].x < p[0].x) swap(p[i], p[0]);
	}
	sort(p + 1, p + n, cmp);
	P[0] = p[0];
	P[1] = p[1];
	tot = 1;//��ʼ������
	for (int i = 2; i < n; i++) {
		//�����Ҫ���ϵĵ� 
		while (tot > 0 && X(P[tot - 1], P[tot], p[i]) < 0)tot--;
//		while (tot > 0 && X(P[tot - 1], P[tot], p[i]) <= 0)tot--;//P[tot]����� ����
		tot++;
		P[tot] = p[i];
	}
	// �����Ҫ���ϵ� Ҫ��� 
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
	// ������������Ҫע�͵��� 
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
