#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long mod=1000000007;

long long getans(long long n,long long k){
	long long ret=1;
	n%=mod;
	while(k){
		if(k&1) ret=ret*n%mod;
		n=n*n%mod;
		k>>=1;
	}
	return ret;
}

int main(){
	long long n,k;
	int cas=1;
	while(~scanf("%lld%lld",&n,&k)){
		printf("Case #%d: %lld\n",cas++,getans(n,k));
	}
}
