#include <bits/stdc++.h>
using namespace std;
struct point{
	char c;
	int a;
}p[100];
string word[100];
int n;
void BubbleSort(){
	point a[100];
	memcpy(a,p,sizeof(a));
	for(int i=0;i<n;i++)
		for(int j=n-1;j>i;j--)
			if(a[j].a<a[j-1].a)swap(a[j],a[j-1]);
	for(int i=0;i<n-1;i++){
		cout<<a[i].c<<a[i].a<<' ';
	}cout<<a[n-1].c<<a[n-1].a<<endl;
	string s[100];	
	for(int i=0;i<=9;i++)s[i]="";
	for(int i=0;i<n;i++)
		s[a[i].a]+=a[i].c;
	int flag=0;
	for(int i=0;i<=9;i++)
		if(s[i]!=word[i])
			flag=1;
	if(flag)cout<<"Not stable"<<endl;
	else cout<<"Stable"<<endl;
}
void SelectionSort(){
	point a[100];
	memcpy(a,p,sizeof(a));
	for(int i=0;i<n;i++){
		int mini=i;
		for(int j=i;j<n;j++){
			if(a[j].a<a[mini].a)mini=j;
		}swap(a[i],a[mini]);
	}
	for(int i=0;i<n-1;i++){
		cout<<a[i].c<<a[i].a<<' ';
	}cout<<a[n-1].c<<a[n-1].a<<endl;
	string s[100];	
	for(int i=0;i<=9;i++)s[i]="";
	for(int i=0;i<n;i++)
		s[a[i].a]+=a[i].c;
	int flag=0;
	for(int i=0;i<=9;i++)
		if(s[i]!=word[i])
			flag=1;
	if(flag)cout<<"Not stable"<<endl;
	else cout<<"Stable"<<endl;
}
int main(){
//	freopen("a.txt","r",stdin);
	cin>>n;
	for(int i=0;i<=9;i++)word[i]="";
	getchar();
	for(int i=0;i<n;i++){
		cin>>p[i].c>>p[i].a;
		word[p[i].a]+=p[i].c;
		getchar();
	}
	BubbleSort();
	SelectionSort();
	return 0;
}
