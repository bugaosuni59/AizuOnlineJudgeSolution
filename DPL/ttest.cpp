#include <bits/stdc++.h>
using namespace std;
void t1(){
	int a;
	for(int i=0;i<1000000000;i++){
		a++;
	}cout<<a<<endl;
}
void t2(){
	int a;
	for(int i=0;i<1000000000;i++){
		a=i*2;
	}cout<<a<<endl;
}
void t3(){
	int a;
	for(int i=0;i<1000000000;i++){
		a=i/2;
	}cout<<a<<endl;
}
void t4(){
	int a;
	for(int i=0;i<1000000000;i++){
		a=log(i);
	}cout<<a<<endl;
}
int main(){
	t4();
	return 0;
}
