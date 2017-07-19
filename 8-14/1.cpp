#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[10000010];
int main(){
	int cas=1;
	while(~scanf("%s",s)){
		int l=strlen(s);
		int x=0,y=0,mod=73*137;
		for(int i=0;i<l;i++){
			x=x*10+s[i]-'0';
			while(x>=mod) x-=mod;
		}
		printf("Case #%d: ",cas++);
		if(x){
			puts("NO");
		}
		else{
			puts("YES");
		}
	}
}
