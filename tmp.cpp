#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[111],b[111];
int x;

int main(){
	for(int i=1;i<=11;i++){
		a[i]=0;
		b[i]=0;
		for(int j=0;j<7;j++){
			scanf("%d",&x);
			a[i]=a[i]*2+x;
			b[i]=b[i]*2+1-x;
		}
	}
	for(int i=1;i<=11;i++)
		printf("%c",a[i]);
		puts("");
	for(int i=1;i<=11;i++)
		printf("%c",b[i]);
		puts("");
}
