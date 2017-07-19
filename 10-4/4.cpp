#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[100];
int main(){
	memset(a,0,sizeof(a));
	a[1]=1;
	a[2]=1;
	a[3]=1;
	a[5]=1;
	a[8]=1;
	a[13]=1;
	for(int i=2;i<=20;i++)
		a[i]+=a[i-1];
	int T,n,cas=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("Case #%d: %d\n",cas++,n-a[n]);
	}
}
