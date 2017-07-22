#include <iostream>
#include <stdio.h>
using namespace std;

long long mypow(long long x,int k,int p){
	long long ret=1;
	while(k){
		if (k & 1) ret = (ret * x) % p;
		k >>= 1;
		x = x * x % p;
	}
	return ret;
}

int main(){
	int n,m,p;
	while(~scanf("%d%d%d",&n,&m,&p)){
		n=n-m+1;
		long long ans=1;
		long long div=1;
		for(int i=1;i<=m;i++,n--){
			ans=(ans*n)%p;
			div=div*i%p;
		}
		ans=(ans*mypow(div,p-2,p))%p;
		cout << ans << endl;
	}
}
