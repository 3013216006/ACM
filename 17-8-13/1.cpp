#include <iostream>
#include <stdio.h>
using namespace std;
long long mod=1000000007ll;

long long a[1010],inv[1010];

long long getpow(long long x,long long k){
	long long ret=1;
	while(k){
		if(k&1) ret=ret*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return  ret;
}


void init(){
	a[0]=1;
	inv[0]=1;
	for(int i=1;i<=1000;i++){
		a[i]=a[i-1]*i;
		a[i]%=mod;
		inv[i]=getpow(a[i],mod-2);
	}
}

int main(){
	init();
	int T;
	int n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(n<m) swap(n,m);
		long long ans=a[n];
		ans=ans*inv[m]%mod*inv[n-m]%mod;
		printf("%lld\n",ans);
	}
}
