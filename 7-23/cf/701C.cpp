#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int mark[100100];
char s[100100];
int main(){
	int n;
	while(~scanf("%d",&n)){
		scanf("%s",s);
		memset(mark,0,sizeof(mark));
		int len=0,sum=0,ans=0,l=0;
		for(int i=0;i<n;i++){
			len++;
			if(mark[s[i]]==0){
				sum++;
				ans=len;
			}
			mark[s[i]]++;
			while(mark[s[l]]>=2){
				mark[s[l]]--;
				l++;
				len--;
			}
			ans=min(ans,len);
		}
		printf("%d\n",ans);
	}
}
