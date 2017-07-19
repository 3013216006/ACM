#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
long long ans[15];
void init(){
	ans[0]=1;
	for(int i=1;i<=12;i++)
		ans[i]=ans[i-1]*i;
}

int main(){
	int n,m;
	init();
	while(~scanf("%d%d",&n,&m)){
		printf("%lld\n",ans[min(n,m)]);
	}
	
}
