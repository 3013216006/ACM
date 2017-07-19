#include <iostream>
#include <stdio.h>
using namespace std;
long long n,m;
int main(){
	while(~scanf("%lld%lld",&n,&m)){
		long long k=n/2/(m+1);
		printf("%lld %lld %lld\n",k,k*m,n-k-k*m);
	}
}
