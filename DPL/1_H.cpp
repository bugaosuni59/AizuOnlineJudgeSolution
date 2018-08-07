#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int n;
long long W;
long long w[44],v[44];
const long long inf=1000000000000000001ll;
int target=20;
vector<pair<long long,long long> > res;
vector<pair<long long,long long> > res2;
void dfs(int i,long long ww,long long vv){
	if(i==target){if(ww<=W)res.push_back({ww,vv});return;}
	dfs(i+1,ww,vv);
	dfs(i+1,ww+w[i],vv+v[i]);
}
long long find(long long ww){
	pair<long long,long long> p=make_pair(ww,inf);
	int i=lower_bound(res2.begin(),res2.end(),p)-res2.begin()-1;
	if(i<0||i>=res2.size())return 0;
	return res2[i].second;
}
void dfs2(int i,long long ww,long long vv){
	if(i==target){if(ww<=W)res2.push_back({ww,vv});return;}
	dfs2(i+1,ww,vv);
	dfs2(i+1,ww+w[i],vv+v[i]);
}
int main(){
	cin>>n>>W;
	for(int i=0;i<n;i++)cin>>v[i]>>w[i];
	target=n/2;dfs(0,0,0);
	target=n;dfs2(n/2,0,0);
	sort(res2.begin(),res2.end());
	for(int i=res2.size()-2;i>=0;i--)
		while(i<(int)res2.size()-1&&res2[i+1].second<res2[i].second)res2.erase(res2.begin()+i+1);
	long long ans=0;	
	for(int i=0;i<res.size();i++)
		ans=max(ans,res[i].second+find(W-res[i].first));
	printf("%lld\n",ans);
	return 0;
}
