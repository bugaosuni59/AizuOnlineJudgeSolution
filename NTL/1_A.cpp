#include <bits/stdc++.h>
using namespace std;
vector<int> f;
void solve(int n){
	cout<<n<<":";
	int i=0;
	for(i=2;i*i<=n;i++)
		while(n%i==0)f.push_back(i),n/=i;
	if(n!=1)f.push_back(n);
	for(int i=0;i<f.size();i++){
		cout<<" "<<f[i];
	}cout<<endl;
}
int main(){
	int n;cin>>n;
	solve(n);
	return 0;
}
