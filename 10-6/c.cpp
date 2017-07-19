#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main(){
	int T,cas=1;
	long long x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&x,&y);
		printf("Case #%d:\n",cas++);
		if(x==y){
			puts("1");
			printf("%lld %lld\n",x,y);
		}
		else{
			puts("2");
			if(x>y) swap(x,y);
			printf("%lld %lld\n",x,y);
			printf("%lld %lld\n",y,x);
		}
	}
}
