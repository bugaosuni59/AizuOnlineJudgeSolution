#include <bits/stdc++.h>
#define ll long long
using namespace std;
int Next[1000005];
string word;
string text;
void initNext(){// 参数：Next数组，text数组，word数组 
    int len=word.length();  
    Next[0]=-1;  
    for(int j=1;j<len;j++){  
        int i=Next[j-1];  
        while((i>=0)&&(word[i+1]!=word[j])){i=Next[i];}  
        if(word[i+1]==word[j]){Next[j] = i+1;}  
        else Next[j] = -1;  
    }  
  for(int j = 0 ; j < len ; j++){printf("%d ",Next[j]);}printf("\n");// 测试Next数组 
}  
int solve(){  
	initNext();
    int i,j,cnt;i=0;j=0;cnt=0;  
    int lenp=word.length();  // 短数组长度 
    int lens=text.length();  // 长数组长度 
    while(i<=lens){  
        if(i==lens){if(j==lenp)cnt++;break;}  // 结束 
        if(text[i]==word[j]){i++;j++;}  // 匹配 
        else{if(j==0)i++;else j=Next[j-1]+1;}  // 不匹配 
        if(j>=lenp){cnt++;j=Next[lenp-1]+1;}  // 找到 
    }  
    return cnt;  
}  
string s,t;
int main(){
//	freopen("a.txt","r",stdin);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>s>>t;
	word=t;
	text=s; 
	solve();
	return 0;
}
