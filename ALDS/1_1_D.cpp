#include <bits/stdc++.h>
using namespace std;
int a[200005],n;
/******************************************
题意等价于：
	有个物品价格随时间变化
	求在某天买了后再在某天卖，能获取的最大利润
	 
结果等于：
最大的{
	第i个数减去该数左面最小的数 
}
******************************************/
int main(){
//	freopen("a.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int smallest=a[0];
	int res=a[1]-a[0];
	for(int i=1;i<n;i++){
		res=max(res,a[i]-smallest);
		smallest=min(smallest,a[i]);
	}
	cout<<res<<endl;
	return 0;
}
