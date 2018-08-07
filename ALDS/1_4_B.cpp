#include <bits/stdc++.h>
using namespace std;
int a[100005];
int n,q;
/*******************************************************************
二分查找：
	查找一个【数值递增的】数组里有没有你想要的数字 K，
	分治的思想， 
	由递增特性，如果数组中有K，那么K可能在数组的左半边，也可能在右半边， 
	如果中间的数字比K小，那么K只可能在数组的右半边。
	而数组的右半边作为整体，也可以被分为左半边、右半边，
	重复上述过程，直到只剩一个数字，
	如果连这个数字都不是K，那这个数组就没有K 

下面给出循环、递归两种二分写法，以及用C++的lower_bound写二分的方法
C语言有一个函数叫binary_search，也可以用于二分，可以自学，没啥卵用 
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
