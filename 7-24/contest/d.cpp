#include <iostream>
#include <stdio.h>
using namespace std;
int cas,m;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&cas,&m);
		long long n=m;
		printf("%d %lld %lld %lld\n",cas,n*(1+n)/2,n*n,n*(1+n));
	}
}
