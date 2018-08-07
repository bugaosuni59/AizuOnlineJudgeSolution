#include <bits/stdc++.h>
using namespace std;
// 单点修改
struct SegTree{
	int N;
	int a[400005];// 最小值
	void init(int n){
		N=1;while(N<n)N*=2;
		for(int i=0;i<=2*N;i++)a[i]=INT_MAX;
	}
	void update(int i,int v){
		i+=N-1;
		a[i]=v;
		while(i){
			i=(i-1)/2;
			a[i]=min(a[i*2+1],a[i*2+2]);
		}
	}
	int query(int l,int r,int L,int R,int i){
		if(R<=l||r<=L)return INT_MAX;
		if(l<=L&&R<=r)return a[i];
		int v1=query(l,r,L,(L+R)/2,i*2+1);
		int v2=query(l,r,(L+R)/2,R,i*2+2);
		return min(v1,v2);
	}
};
int main(){
	ios::sync_with_stdio(false);
	freopen("b.txt","w",stdout);
	int n,q,type,p1,p2;
	cin>>n>>q;
	SegTree st;
	st.init(n);
	while(q--){
		cin>>type>>p1>>p2;
		if(type==0){
			st.update(p1,p2);
		}else{
			cout<<st.query(p1,p2+1,0,st.N,0)<<endl;
		}
	}
	return 0;
}
