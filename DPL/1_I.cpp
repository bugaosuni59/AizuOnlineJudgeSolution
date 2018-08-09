#include <bits/stdc++.h>
using namespace std;
struct point{
	long long v,w;
	bool operator<(const point &p)const{
		return w<p.w;
	}
}a[100005];
bool cmp1(point p1,point p2){
	return p1.v<p2.v;
}
bool cmpw(const point &p1,const point &p2){
	return p1.w<p2.w;
}
bool cmp2(point p1,point p2){
	return 1.0*p1.v/p1.w>1.0*p2.v/p2.w;
}
vector<point> vec[3000];
long long N,W;
long long dp[3000][10001];
int n=1;

void solve(){
	for(int i=0;i<3000;i++)for(int j=0;j<10001;j++)dp[i][j]=1000000000000000000ll;
	for(int i=0;i<3000;i++)dp[i][0]=0;
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++)
		for(int j=10000;j>=a[i].v;j--)
			dp[i][j]=min(dp[i-1][j],dp[i-1][j-a[i].v]+a[i].w);
	for(int i=1;i<=n;i++)
		for(int j=10000;j>=a[i].v;j--)
			if(dp[i][j]!=1000000000000000000ll)
				vec[i].push_back({j,dp[i][j]});
	for(int i=1;i<3000;i++)
		sort(vec[i].begin(),vec[i].end(),cmp1);
	long long res=0;
	for(int i=1;i<=n;i++){
		// 从i开始
		long long w=0,v=0; 
		for(int j=i+1;j<=n;j++){
			// 选第j个
			w+=a[j].w;
			v+=a[j].v;
			if(w>W)break;
			res=max(res,v);
			int rest=W-w;
			// vec[i]里找 .w <= rest 取其v
			point tem;tem.w=rest;
			if(vec[i].size()==0)continue;
			int jb=lower_bound(vec[i].begin(),vec[i].end(),tem)-vec[i].begin();
			if(jb==(int)vec[i].size())jb--;
			if(vec[i][jb].w>rest)jb--;
			if(jb<0)break;
			res=max(res,v+vec[i][jb].v);
		}
	}
	cout<<res<<"\n";
}

int main(){
	cin>>N>>W;
	long long vv,ww,mm;
	while(cin>>vv>>ww>>mm){
		while(mm){
			long long k=1;
			while(mm>=k){
				mm-=k;
				a[n].v=k*vv;
				a[n].w=k*ww;
				k=k*2;
				n++;
			}
		}
	}
	solve();
	return 0;
}
