#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[1200][10];
int main(){
	int T;
	while(~scanf("%d",&T)){
	int ans=0;
	for(int i=0;i<T;i++){
		scanf("%s",s[i]);
		if(ans) continue;
		if(s[i][0]==s[i][1]&&s[i][0]=='O'){
			ans=1;
			s[i][0]='+';
			s[i][1]='+';
		}
		if(ans) continue;
		if(s[i][3]==s[i][4]&&s[i][3]=='O'){
			ans=1;
			s[i][3]='+';
			s[i][4]='+';
		}
	}
	if(ans){
		puts("YES");
		for(int i=0;i<T;i++)
			printf("%s\n",s[i]);
	}
	else{
		puts("NO");
	}
	}
}
