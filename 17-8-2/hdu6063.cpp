#include <iostream>
#include <stdio.h>

using namespace std;
long long mod=1000000007ll;

long long getans(long long n,long long k){
	n%=mod;
	long long ret=1;
	while(k){
		if(k&1) ret=ret*n%mod;
		k>>=1;
		n=n*n%mod;
	}
	return ret;
}

int main(){
	long long n,m;
	int cas=1;
	while(~scanf("%lld%lld",&n,&m)){
		printf("Case #%d: %lld\n",cas++,getans(n,m));
	}
}
