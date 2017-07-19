#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int n,m;
int dp[100100][35],mark[3000];
char s[100100],s1[20];
int main(){
	while(~scanf("%s",s)){
		scanf("%d",&n);
		memset(mark,-1,sizeof(mark));
		for(int i=0;i<n;i++){
			scanf("%s",s1);
			mark[s1[0]-'a']=s1[1]-'a';
			mark[s1[1]-'a']=s1[0]-'a';
		}
		int ans=0;
		int len=strlen(s);
		int l=0;
		while(l<len){
			int r=l+1,x=0;
			while(r<len&&(s[r]==s[l]||s[r]-'a'==mark[s[l]-'a'])){
				if(s[r]-'a'==mark[s[l]-'a']) x++;
				r++;
			}
			ans+=min(x,r-l-x);
			l=r;
		}
		cout << ans << endl;
	}
}
