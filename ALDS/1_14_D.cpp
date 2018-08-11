#include <bits/stdc++.h>
using namespace std;
string s,t;
int n;
int sa[2000005],bb[2000005],x[2000005],y[2000005];
bool cmp(int *y,int a,int b,int k){
	int a1=y[a],b1=y[b];
	int a2=a+k>=n?-1:y[a+k];
	int b2=b+k>=n?-1:y[b+k];
	return a1==b1&&a2==b2;
}
void init(){
	// 建立后缀数组
	int m=256;
	for(int i=0;i<m;i++)bb[i]=0;
	for(int i=0;i<n;i++)bb[x[i]=s[i]]++;
	for(int i=1;i<m;i++)bb[i]+=bb[i-1];
	for(int i=n-1;i>=0;i--)sa[--bb[x[i]]]=i;
	for(int k=1;k<=n;k<<=1){
		int p=0;
		for(int i=n-k;i<n;i++)y[p++]=i;
		for(int i=0;i<n;i++)if(sa[i]>=k)y[p++]=sa[i]-k;
		for(int i=0;i<m;i++)bb[i]=0;
		for(int i=0;i<n;i++)bb[x[y[i]]]++;
		for(int i=1;i<m;i++)bb[i]+=bb[i-1];
		for(int i=n-1;i>=0;i--)sa[--bb[x[y[i]]]]=y[i];
		swap(x,y);
		m=1;x[sa[0]]=0;
		for(int i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i],sa[i-1],k)?m-1:m++;
//			x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?m-1:m++;
		if(m>=n)break;
	}
//	for(int i=0;i<n;i++)cout<<sa[i]<<' ';
}
int judge(int i){
	return t.compare(s.substr(i,min(n-i,(int)t.length())));
}
void calc(){
	int l=0,r=n,m;
	while(l<r-2){
		m=(l+r)/2;
		int res=judge(sa[m]);
		if(res==0){puts("1");return;}
		else if(res<0)r=m;
		else l=m;
	}
	for(int i=l;i<=r;i++){
		int res=judge(sa[i]);
		if(res==0){puts("1");return;}
	}
	puts("0");
}
int main(){
//	freopen("a.txt","r",stdin);
	ios::sync_with_stdio(false);cin.tie(0);
	int Q;cin>>s>>Q;n=s.length();
	init();
	while(Q--){
		cin>>t;
		calc();
	}
	return 0;
}
