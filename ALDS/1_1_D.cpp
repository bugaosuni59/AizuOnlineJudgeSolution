#include <bits/stdc++.h>
using namespace std;
int a[200005],n;
/******************************************
����ȼ��ڣ�
	�и���Ʒ�۸���ʱ��仯
	����ĳ�����˺�����ĳ�������ܻ�ȡ���������
	 
������ڣ�
����{
	��i������ȥ����������С���� 
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
