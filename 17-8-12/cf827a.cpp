#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[1000010],str[1000100];
int sum[1000100],ans[2000100],len[1001000];

int main(){
	int n;
	while(~scanf("%d",&n)){
		int l=0;
		int k,x;
		sum[0]=0;
		memset(ans,-1,sizeof(ans));
		for(int i=0;i<n;i++){
			scanf("%s",s);
			len[i]=strlen(s);
			sum[i+1]=sum[i]+len[i];
			k=sum[i];
			for(int j=0;j<len[i];j++)
				str[k++]=s[j];
			scanf("%d",&k);
			for(int j=0;j<k;j++){
				scanf("%d",&x);
				l=max(l,x);
				if(ans[x]==-1) ans[x]=i;
				else{
					if(len[ans[x]]<len[i]) ans[x]=i;
				}
			}
		}
		int nw,nwl=0;
		for(int i=1;i<=l;){
			if(ans[i]==-1) printf("a"),i++;
			else{
				nw=i;
				for(int j=0;j<len[ans[nw]];j++,i++){
					if(ans[i]!=-1&&len[ans[i]]>len[ans[nw]]-j) break;
					else printf("%c",str[sum[ans[nw]]+j]);
				}
			}
		}
		puts("");
	}
}
