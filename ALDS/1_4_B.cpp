#include <bits/stdc++.h>
using namespace std;
int a[100005];
int n,q;
/*******************************************************************
���ֲ��ң�
	����һ������ֵ�����ġ���������û������Ҫ������ K��
	���ε�˼�룬 
	�ɵ������ԣ������������K����ôK��������������ߣ�Ҳ�������Ұ�ߣ� 
	����м�����ֱ�KС����ôKֻ������������Ұ�ߡ�
	��������Ұ����Ϊ���壬Ҳ���Ա���Ϊ���ߡ��Ұ�ߣ�
	�ظ��������̣�ֱ��ֻʣһ�����֣�
	�����������ֶ�����K������������û��K 

�������ѭ�����ݹ����ֶ���д�����Լ���C++��lower_boundд���ֵķ���
C������һ��������binary_search��Ҳ�������ڶ��֣�������ѧ��ûɶ���� 
*******************************************************************/
bool BinarySearch(int l,int r,int k){
	int mi=(l+r)/2;
	if(l>r)return false;
	if(a[mi]==k)return true;
	if(a[mi]<k)return BinarySearch(mi+1,r,k);
	else return BinarySearch(l,mi-1,k);
}
//bool BinarySearch(int l,int r,int k){
//	int mi;
//	while(l<=r){
//		mi=(l+r)/2;
//		if(a[mi]==k)return true;
//		else if(a[mi]<k)l=mi+1;
//		else r=mi-1;
//	}
//	return false;
//}
int main(){
//	freopen("a.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
//	sort(a,a+n);
	cin>>q;
	int res=0,number;
	for(int i=0;i<q;i++){
		cin>>number;
		if(BinarySearch(0,n-1,number))res++;
//		if(*lower_bound(a,a+n,number)==number)res++;
	}
	cout<<res<<endl;
	return 0;
}
