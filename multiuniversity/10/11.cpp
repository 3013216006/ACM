#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int a[2000];
char s[200];
int main(){
	a[0]=0;
	for(int i=1;i<=1000;i++){
		gets(s);
		int l=strlen(s);
		a[i]=a[i-1]+l;
		for(int j=0;j<l;j++)
			if(s[j]==' '||s[j]=='-') a[i]--;
		printf("a[%d]=%d;\n",i,a[i]);
	}
}
