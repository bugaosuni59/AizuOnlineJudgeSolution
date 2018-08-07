#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("b.txt","w",stdout);
	for(int i=1;i<=2048*1024;i++){
		int k=i;
		int res=0;
		while(k){
			int cnt=1;
			while(k>=cnt){
				res++;
				k-=cnt;
				cnt*=2;
			}
		}
		cout<<i<<"\t"<<res<<"\n";
	}
	return 0;
}
