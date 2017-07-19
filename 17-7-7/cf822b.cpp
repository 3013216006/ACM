#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
char s1[1001],s2[1000];

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		scanf("%s%s",s1,s2);
		int ans=1000,l=0;
		for(int i=0;i+n<=m;i++){
			int tmp=0;
			for(int j=0;j<n;j++){
				if(s1[j]!=s2[i+j])tmp++;
			}
			if(tmp<ans) ans=tmp,l=i;
		}
		printf("%d\n",ans);
		int flag=0;
		for(int i=0;i<n;i++)
		if(s1[i]!=s2[i+l]){
			if(flag) printf(" ");
			flag=1;
			printf("%d",i+1);
		}
		puts("");

	}
}
