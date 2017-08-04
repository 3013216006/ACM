#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[1100];
int vis[300];

int main(){
	int T;
	int cas=1;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		int l=strlen(s);
		memset(vis,-1,sizeof(vis));
		int ans=l+1;
		for(int i=0;i<l;i++){
			if(vis[s[i]]!=-1) ans=min(ans,i-vis[s[i]]);
			vis[s[i]]=i;
		}
		if(ans==l+1) ans=-1;
		printf("Case #%d: %d\n",cas++,ans);
	}
}
