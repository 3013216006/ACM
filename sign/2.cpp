#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
char s[1000];
int main(){
	char tmp[1000];
	tmp[0]='.';
	tmp[1]='/';
	tmp[2]='a';
	tmp[3]='.';
	tmp[4]='s';
	tmp[5]='h';
	tmp[6]=' ';
	while(scanf("%s",s)){
		int l=strlen(s);
		for(int i=0;i<=l;i++)
			tmp[7+i]=s[i];
		system(tmp);
	}
}
